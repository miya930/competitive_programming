use proconio::input;

fn main() {
    input!(
        n: usize,
        s: [String; n],
    );
    let mut li = vec![];
    for v in &s {
        li.push((v.len(), v));
    }
    li.sort();
    for v in &li {
        print!("{}", v.1);
    }
    println!("");
}
