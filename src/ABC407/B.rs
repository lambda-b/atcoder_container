use proconio::input;
fn main() {
    input! { x: i32, y: i32 }
    let count = (1..=6)
        .flat_map(|i| (1..=6).map(move |j| (i, j)))
        .filter(|&(i, j)| i + j >= x || (i - j).abs() >= y)
        .count();
    println!("{:.16}", count as f64 / 36.0);
}
