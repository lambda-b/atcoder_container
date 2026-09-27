use proconio::input;
fn main() {
    input! { n: usize, mut a: [i64; n] }
    a.sort_unstable();
    let answer = a
        .iter()
        .enumerate()
        .filter(|(i, x)| **x >= (n - *i) as i64)
        .map(|(i, _)| n - i)
        .max()
        .unwrap_or(0);
    println!("{answer}");
}
