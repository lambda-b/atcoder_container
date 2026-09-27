use proconio::input;
fn main() {
    input! {n:usize,a:[i64;n]}
    let b = &a[n / 2..];
    let mut j = 0;
    let mut pairs = 0;
    for &x in &a[..n / 2] {
        j = b[j..].partition_point(|&y| y < 2 * x) + j;
        if j == b.len() {
            break;
        }
        pairs += 1;
        j += 1;
    }
    println!("{pairs}");
}
