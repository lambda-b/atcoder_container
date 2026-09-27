use proconio::input;
fn main() {
    input! { n: u128, m: u32 }
    let mut power = 1u128;
    let mut sum = 0u128;
    for _ in 0..=m {
        sum = match sum.checked_add(power) {
            Some(v) if v <= 1_000_000_000 => v,
            _ => {
                println!("inf");
                return;
            }
        };
        if let Some(v) = power.checked_mul(n) {
            power = v;
        } else {
            println!("inf");
            return;
        }
    }
    println!("{sum}");
}
