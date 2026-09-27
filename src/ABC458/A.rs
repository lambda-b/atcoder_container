use proconio::input;
fn main() {
    input! { s: String, n: usize }
    let end = s.len() - n;
    println!("{}", &s[n..end]);
}
