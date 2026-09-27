use proconio::input;
fn main() {
    input! { s: i32 }
    println!(
        "{}",
        if (200..300).contains(&s) {
            "Success"
        } else {
            "Failure"
        }
    );
}
