use proconio::input;
fn main() {
    input! { n: usize, a: [i64; n], y: i64 }
    println!("{}", if a.contains(&y) { "Yes" } else { "No" });
}
