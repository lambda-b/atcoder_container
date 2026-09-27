use proconio::input;
fn main() {
    input! { _n: usize, a: usize, b: usize, s: String }
    println!("{}", &s[a..s.len() - b]);
}
