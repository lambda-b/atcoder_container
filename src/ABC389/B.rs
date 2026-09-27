use proconio::input;
fn main() {
    input! { x: u128 }
    let mut fact = 1u128;
    for i in 1..=100 {
        fact *= i;
        if fact == x {
            println!("{i}");
            return;
        }
        if fact > x {
            break;
        }
    }
}
