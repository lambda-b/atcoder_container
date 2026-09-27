use proconio::input;
fn main() {
    input! { s: String }
    println!("{}UPC", s.chars().next().unwrap());
}
