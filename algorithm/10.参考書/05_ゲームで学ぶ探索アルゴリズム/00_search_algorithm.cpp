#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Coord
{
    int y_;
    int x_;
    Coord(const int y = 0, const int x = 0) : y_(y), x_(x) {}
};

mt19937 mt_for_action(0);                // 行動選択用の乱数生成器を初期化
using ScoreType = int64_t;                    // ゲームの評価スコアの型を決めておく。
constexpr const ScoreType INF = 1000000000LL; // あり得ないぐらい大きなスコアの例を用意しておく

constexpr const int H = 3;  // 迷路の高さ
constexpr const int W = 4;  // 迷路の幅
constexpr int END_TURN = 4; // ゲーム終了ターン

class TimeKeeper {
private:
    chrono::high_resolution_clock::time_point start_time_;
    int64_t time_threshold_;

public:
    TimeKeeper(const int64_t &time_threshold) : start_time_(chrono::high_resolution_clock::now()), time_threshold_(time_threshold){}

    // インスタンス生成した時から指定した時間制限を経過したか判定する
    bool isTimeOver() const {

        using chrono::duration_cast;
        using chrono::milliseconds;
        auto diff = chrono::high_resolution_clock::now() - this->start_time_;

        return duration_cast<milliseconds>(diff).count() >= time_threshold_;
    }
};

class MazeState {
private:
    // 右、左、下、上への移動方向のx成分とy成分
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int points_[H][W] = {};
    int turn_ = 0;

public:
    Coord character_ = Coord();
    int first_action_ = -1;
    ScoreType evaluated_score_ = 0;
    int game_score_ = 0;
    MazeState() {}

    // h+wの迷路を生成する
    MazeState(const int seed) {
        auto mt_for_construct = mt19937(seed);
        this->character_.y_ = mt_for_construct() % H;
        this->character_.x_ = mt_for_construct() % W;

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (y == character_.y_ && x == character_.x_) {
                    continue;
                }
                this->points_[y][x] = mt_for_construct() % 10;
            }
        }
    }

    bool isDone() const {
        return this->turn_ == END_TURN;
    }

    void evaluateScore() {
        this->evaluated_score_ = this->game_score_;
    }

    void advance(const int action) {
        this->character_.x_ += dx[action];
        this->character_.y_ += dy[action];

        auto &point = this->points_[this->character_.y_][this->character_.x_];
        if (point > 0) {
            this->game_score_ += point;
            point = 0;
        }
        this->turn_++;
    }

    vector<int> legalActions() const {
        vector<int> actions;
        for (int action = 0; action < 4; action++) {
            int ty = this->character_.y_ + dy[action];
            int tx = this->character_.x_ + dx[action];
            if (ty >= 0 && ty < H && tx >= 0 && tx < W) {
                actions.emplace_back(action);
            }
        }
        return actions;
    }

    string toString() const {
        stringstream ss;
        ss << "turn:\t" << this->turn_ << "\n";
        ss << "score:\t" << this->game_score_ << "\n";
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (this->character_.y_ == h && this->character_.x_ == w) {
                    ss << '@';
                } else if (this->points_[h][w] > 0) {
                    ss << points_[h][w];
                } else {
                    ss << '.';
                }
            }
            ss << '\n';
        }

        return ss.str();
    }
 
};

bool operator<(const MazeState &maze_1, const MazeState &maze_2) {
    return maze_1.evaluated_score_ < maze_2.evaluated_score_;
}

using State = MazeState;

int randomAction(const State &state) {
    auto legal_actions = state.legalActions();
    return legal_actions[mt_for_action() % (legal_actions.size())];
}

int greedyAction(const State &state) {
    auto legal_actions = state.legalActions();
    ScoreType best_score = -INF;
    int best_action = -1;
    for (const auto action : legal_actions) {
        State now_state = state;
        now_state.advance(action);
        now_state.evaluateScore();
        if (now_state.evaluated_score_ > best_score) {
            best_score = now_state.evaluated_score_;
            best_action = action;
        }
    }
    return best_action;
}

int beamSearchAction(const State &state, const int beam_width, const int64_t time_threshold) {
    auto time_keeper = TimeKeeper(time_threshold);
    priority_queue<State> now_beam;
    State best_state;

    now_beam.push(state);

    for (int t = 0;; t++) {
        priority_queue<State> next_beam;
        for (int i = 0; i < beam_width; i++) {
            if (time_keeper.isTimeOver()) {
                return best_state.first_action_;
            }

            if (now_beam.empty()) break;
            State now_state = now_beam.top();
            now_beam.pop();
            auto legal_actions = now_state.legalActions();
            for (const auto &action : legal_actions) {
                State next_state = now_state;
                next_state.advance(action);
                next_state.evaluateScore();
                if (t == 0) next_state.first_action_ = action;
                next_beam.push(next_state);
            }
        }

        now_beam = next_beam;
        best_state = now_beam.top();

        if (best_state.isDone()) break;
    }

    return best_state.first_action_;
}

int chokudaiSearchAction(const State &state, const int beam_width, const int beam_depth, const int beam_number) {
    auto beam = vector<priority_queue<State>>(beam_depth + 1);
    for (int t = 0; t < beam_depth; t++) {
        beam[t] = priority_queue<State>();
    }
    beam[0].push(state);
    for (int cnt = 0; cnt < beam_number; cnt++) {
        for (int t = 0; t < beam_depth; t++) {
            auto &now_beam = beam[t];
            auto &next_beam = beam[t+1];
            for (int i = 0; i < beam_depth; i++) {
                if (now_beam.empty()) break;
                State now_state = now_beam.top();
                if (now_state.isDone()) break;
                now_beam.pop();
                auto legal_actions = now_state.legalActions();
                for (const auto &action : legal_actions) {
                    State next_state = now_state;
                    next_state.advance(action);
                    next_state.evaluateScore();
                    if (t == 0) next_state.first_action_ = action;
                    next_beam.push(next_state);
                }
            }
        }
    }
    for (int t = beam_depth; t >=0; t--) {
        const auto &now_beam = beam[t];
        if (!now_beam.empty()) {
            return now_beam.top().first_action_;
        }
    }

    return -1;
}


void testAiScore(const int game_number) {
    mt19937 mt_for_construct(0);
    double score_mean = 0;
    for (int i = 0; i < game_number; i++) {
        auto state = State(mt_for_construct());

        while(!state.isDone()) {
            state.advance(chokudaiSearchAction(state, 1, END_TURN, 2));
        }
        auto score = state.game_score_;
        score_mean += score;
    }
    score_mean /= (double)game_number;
    cout << "Score:\t" << score_mean << endl;
}

int main()
{
    testAiScore(100);
    return 0;
}

