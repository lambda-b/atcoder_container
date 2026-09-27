use proconio::input;
fn main() {
    input! { n: usize, c1: char, c2: char, s: String }
    let answer: String = s
        .chars()
        .take(n)
        .map(|c| if c == c1 { c } else { c2 })
        .collect();
    println!("{answer}");
}
