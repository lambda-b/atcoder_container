use proconio::input;
fn main() {
    input! { s: String }
    println!("{}", ('a'..='z').find(|c| !s.contains(*c)).unwrap());
}
