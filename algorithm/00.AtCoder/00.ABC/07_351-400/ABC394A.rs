use proconio::input;

fn main() {
    input!(
        s: String,
    );
    let mut ans = "".to_string();
    let si = s.len();
    for i in 0..si {
        if s.chars().nth(i) == Some('2') {
            ans.push(s.chars().nth(i).unwrap());
        }
    }
    println!("{}", ans);
}
