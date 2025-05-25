use proconio::input;

fn main() {
    input!(
        s1: String,
        s2: String,
    );

    let mut ans = 4;
    if s1 == "sick".to_string() && s2 == "fine".to_string() {
        ans = 2;
    } else if s1 == "fine".to_string() && s2 == "sick".to_string() {
        ans = 3;
    } else if s1 == "sick".to_string() && s2 == "sick".to_string() {
        ans = 1;
    }
    println!("{}", ans);
}
