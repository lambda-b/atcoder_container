use proconio::input;
fn main() {
    input! { n: usize, m: i64, a: [i64; n] }
    let sum: i64 = a.iter().sum();
    println!(
        "{}",
        if a.iter().any(|&x| sum - x == m) {
            "Yes"
        } else {
            "No"
        }
    );
}
