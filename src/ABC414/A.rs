use proconio::input;
fn main() {
    input! { n: usize, l: i64, r: i64, intervals: [(i64, i64); n] }
    println!(
        "{}",
        intervals.iter().filter(|&&(x, y)| x <= l && r <= y).count()
    );
}
