use proconio::input;
fn main() {
    input! { a: i64, b: i64, c: i64, d: i64 }
    println!("{}", if c >= a && d < b { "Yes" } else { "No" });
}
