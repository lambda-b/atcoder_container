use proconio::input;
fn main() {
    input! { s: String }
    let answer = s
        .as_bytes()
        .chunks(4)
        .enumerate()
        .filter(|(_, x)| x.get(1) == Some(&b'o'))
        .map(|(i, _)| (i + 1).to_string())
        .last()
        .unwrap_or_else(|| "none".to_string());
    println!("{answer}");
}
