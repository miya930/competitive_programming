use proconio::input;

fn main() {
    input!(
        n: i32,
        m: usize,
        a:[i32; m],
    );
    let mut seen = vec![false; (n + 1) as usize];
    for val in &a {
        seen[*val as usize] = true;
    }

    let mut ans = vec![];
    for i in 1..(n + 1) {
        if !seen[i as usize] {
            ans.push(i);
        }
    }
    println!("{}", ans.len());
    for val in ans {
        print!("{} ", val);
    }
    println!("");
}
