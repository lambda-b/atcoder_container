use proconio::input;
fn main() {
    input! { x: i64 }
    let multiples = (1..=9)
        .flat_map(|i| (1..=9).map(move |j| i * j))
        .filter(|&p| p == x)
        .count() as i64;
    println!("{}", 2025 - x * multiples);
}
