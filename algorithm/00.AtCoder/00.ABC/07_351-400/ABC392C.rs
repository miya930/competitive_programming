use proconio::input;
use std::collections::HashMap;

fn main() {
    input!(
        n: usize,
        p: [i32; n],
        q: [i32; n],
    );
    let mut map = HashMap::new();
    for i in 0..n {
        map.insert(q[i], i);
    }
    for i in 0..n {
        let idx = map.get(&((i + 1) as i32)).unwrap();
        let v = p[*idx];
        print!("{} ", q[(v - 1) as usize]);
    }
    println!("");
}
