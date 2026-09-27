use proconio::input;
fn digit_sum(mut n: i64) -> i64 {
    let mut sum = 0;
    while n > 0 {
        sum += n % 10;
        n /= 10;
    }
    sum
}
fn main() {
    input! { n: usize }
    let mut a = 1i64;
    for _ in 1..n {
        a += digit_sum(a);
    }
    println!("{a}");
}
