use proconio::input;

fn main() {
    input!(
        s: String,
    );
    let mut ans = 0;
    for x in 0..(s.len()) {
        for y in 0..(s.len()) {
            let i = x;
            let j = i + y;
            let k = j + y;
            if k >= s.len() {
                continue;
            }
            if s.chars().nth(i).unwrap() == 'A'
                && s.chars().nth(j).unwrap() == 'B'
                && s.chars().nth(k).unwrap() == 'C'
            {
                ans += 1;
            }
        }
    }
    println!("{}", ans);
}
