use proconio::{input, marker::Usize1};

fn main() {
    input!(
        n: usize,
        qr: [(i64, i64); n],
        q: usize,
        td: [(Usize1, i64); q],
    );

    for (t, d) in td {
        let (q, r) = qr[t];
        if d % q <= r {
            println!("{}", d - d%q + r);
        } else {
            println!("{}", d - d%q + q + r);
        }
    }
}