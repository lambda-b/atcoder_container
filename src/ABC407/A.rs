use proconio::input;
fn main() {
    input! { a: i64, b: i64 }
    let q = a / b;
    let r = a % b;
    println!("{}", if 2 * r < b { q } else { q + 1 });
}
