use proconio::input;
fn main() {
    input! {n:usize,q:usize,mut a:[i64;n],mut b:[i64;n]}
    let mut sum: i64 = (0..n).map(|i| a[i].min(b[i])).sum();
    for _ in 0..q {
        input! {c:char,x:usize,v:i64}
        let i = x - 1;
        sum -= a[i].min(b[i]);
        if c == 'A' {
            a[i] = v
        } else {
            b[i] = v
        }
        sum += a[i].min(b[i]);
        println!("{sum}");
    }
}
