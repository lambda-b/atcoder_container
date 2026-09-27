use proconio::input;
fn main() {
    input! {n:usize,a:[usize;n]}
    let mut count = vec![0i64; n];
    for x in a {
        count[x - 1] += 1;
    }
    println!(
        "{}",
        count
            .into_iter()
            .map(|x| x * (x - 1) / 2 * (n as i64 - x))
            .sum::<i64>()
    );
}
