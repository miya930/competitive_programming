use proconio::input;

fn main() {
    input!(
        s: String,
    );
    let mut v = vec![];
    for c in s.chars() {
        v.push(c);
        let mut ad = vec![];
        loop {
            let si = v.len();
            if si > 1 && v[si - 1] == 'A' && v[si - 2] == 'W' {
                v.pop();
                v.pop();
                v.push('A');
                ad.push('C');
            } else {
                break;
            }
        }
        for a in ad {
            v.push(a);
        }
    }
    for c in v {
        print!("{}", c);
    }
    println!("");
}
