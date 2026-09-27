use proconio::input;
fn main() {
    input! { a: i64, b: i64, c: i64 }
    println!(
        "{}",
        if a == b || b == c || c == a {
            "Yes"
        } else {
            "No"
        }
    );
}
