use proconio::input;
fn main() {
    input! { s: String }
    let i = s.len() / 2;
    println!("{}{}", &s[..i], &s[i + 1..]);
}
