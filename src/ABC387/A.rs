use proconio::input;
fn main() {
    input! { a: i64, b: i64 }
    let sum = a + b;
    println!("{}", sum * sum);
}
