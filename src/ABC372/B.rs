use proconio::input;
fn main() {
    input! { mut m: usize }
    let mut powers = Vec::new();
    let mut i = 0;
    while m > 0 {
        for _ in 0..m % 3 {
            powers.push(i);
        }
        m /= 3;
        i += 1;
    }
    println!("{}", powers.len());
    println!(
        "{}",
        powers
            .iter()
            .map(usize::to_string)
            .collect::<Vec<_>>()
            .join(" ")
    );
}
