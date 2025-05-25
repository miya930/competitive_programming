use proconio::input;

fn main() {
    input!(
        a: [usize; 4],
    );
    let mut count = [0; 4];
    for ai in a {
        count[ai - 1] += 1;
    }
    let mut ans = 0;
    for v in count {
        ans += v / 2;
    }
    println!("{}", ans);
}