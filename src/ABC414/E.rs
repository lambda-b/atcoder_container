use proconio::input;
const MOD: i128 = 998244353;
fn main() {
    input! {n:i64}
    let mut k = 1i64;
    let mut sum = 0i128;
    while k <= n {
        let v = n / k;
        let next = n / v + 1;
        sum = (sum + ((next - k) as i128 * v as i128) % MOD) % MOD;
        k = next;
    }
    let nn = n as i128 % MOD;
    let triangle = nn * ((n as i128 - 1).rem_euclid(MOD)) % MOD * 499122177 % MOD;
    let ans = (nn * nn % MOD - sum - triangle).rem_euclid(MOD);
    println!("{ans}");
}
