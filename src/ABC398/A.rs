use proconio::input;
fn main() {
    input! { n: usize }
    let side = (n - 1) / 2;
    println!(
        "{}{}{}",
        "-".repeat(side),
        "=".repeat(n - 2 * side),
        "-".repeat(side)
    );
}
