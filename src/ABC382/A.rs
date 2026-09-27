use proconio::input;
fn main() {
    input! { _n: usize, d: usize, s: String }
    println!("{}", s.chars().filter(|&c| c == '.').count() + d);
}
