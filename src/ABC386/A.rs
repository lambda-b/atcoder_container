use proconio::input;
use std::collections::HashSet;
fn main() {
    input! { a: i32, b: i32, c: i32, d: i32 }
    println!(
        "{}",
        if HashSet::from([a, b, c, d]).len() == 2 {
            "Yes"
        } else {
            "No"
        }
    );
}
