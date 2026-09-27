use proconio::input;
fn main() {
    input! { s: String }
    let padded = format!("o{}i", s);
    println!(
        "{}",
        padded
            .as_bytes()
            .windows(2)
            .filter(|w| w[0] == w[1])
            .count()
    );
}
