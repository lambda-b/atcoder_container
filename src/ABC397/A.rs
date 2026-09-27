use proconio::input;
fn main() {
    input! { x: f64 }
    println!(
        "{}",
        if x >= 38.0 {
            1
        } else if x >= 37.5 {
            2
        } else {
            3
        }
    );
}
