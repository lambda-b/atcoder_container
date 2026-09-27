use proconio::input;
fn main() {
    input! { n: usize, s: String }
    println!(
        "{}",
        if n >= 3 && s.ends_with("tea") {
            "Yes"
        } else {
            "No"
        }
    );
}
