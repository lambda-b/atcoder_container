use proconio::input;
fn main() {
    input! { n: usize, k: i64, a: [i64; n], b: [i64; n] }
    let (mut x, mut y) = (true, true);
    for i in 1..n {
        let nx = (x && (a[i - 1] - a[i]).abs() <= k) || (y && (b[i - 1] - a[i]).abs() <= k);
        let ny = (x && (a[i - 1] - b[i]).abs() <= k) || (y && (b[i - 1] - b[i]).abs() <= k);
        x = nx;
        y = ny;
    }
    println!("{}", if x || y { "Yes" } else { "No" });
}
