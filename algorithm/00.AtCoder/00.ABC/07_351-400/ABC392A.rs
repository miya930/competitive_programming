use proconio::input;

fn main() {
    input!(
        a1: i32,
        a2: i32,
        a3: i32,
    );
    if a1 * a2 == a3 || a1 * a3 == a2 || a2 * a3 == a1 {
        println!("Yes");
    } else {
        println!("No");
    }
}
