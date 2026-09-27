use proconio::input;
fn main() {
    input! { p: String, l: usize }
    println!("{}", if p.len() >= l { "Yes" } else { "No" });
}
