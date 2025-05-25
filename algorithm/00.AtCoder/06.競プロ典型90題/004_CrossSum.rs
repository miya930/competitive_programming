use proconio::input;

fn main() {
    input!(
        h: usize,
        w: usize,
        a: [[usize; w]; h],
    );
    let mut c = vec![0; w];
    let mut r = vec![0; h];
    for y in 0..h {
        let mut sum = 0;
        for x in 0..w {
            sum += a[y][x];
        }
        r[y] = sum;
    }
    for x in 0..w {
        let mut sum = 0;
        for y in 0..h {
            sum += a[y][x];
        }
        c[x] = sum;
    }
    for y in 0..h {
        for x in 0..w {
            print!("{} ", r[y] + c[x] - a[y][x]);
        }
        println!("");
    }
}
