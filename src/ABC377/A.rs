use proconio::input;
fn main() {
    input! { s: String }
    let mut chars: Vec<char> = s.chars().collect();
    chars.sort_unstable();
    println!(
        "{}",
        if chars == ['A', 'B', 'C'] {
            "Yes"
        } else {
            "No"
        }
    );
}
