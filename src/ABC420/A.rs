use proconio::input;
fn main() {
    input! { x: i64, y: i64 }
    println!("{}", (x + y - 1) % 12 + 1);
}
