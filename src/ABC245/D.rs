use proconio::input;
fn main() {
    input! {n:usize,m:usize,a:[i64;n+1],c:[i64;n+m+1]}
    let mut b = vec![0i64; m + 1];
    for i in (0..=m).rev() {
        let mut sum = 0;
        for j in (i + 1)..=(m.min(i + n)) {
            sum += a[i + n - j] * b[j];
        }
        b[i] = (c[i + n] - sum) / a[n];
    }
    println!(
        "{}",
        b.iter().map(i64::to_string).collect::<Vec<_>>().join(" ")
    );
}
