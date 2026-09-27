use proconio::input;
fn floor_sum(mut n: i128, mut m: i128, mut a: i128, mut b: i128) -> i128 {
    let mut ans = 0;
    loop {
        if a >= m {
            ans += (n - 1) * n * (a / m) / 2;
            a %= m;
        }
        if b >= m {
            ans += n * (b / m);
            b %= m;
        }
        let y = a * n + b;
        if y < m {
            return ans;
        }
        n = y / m;
        b = y % m;
        std::mem::swap(&mut m, &mut a);
    }
}
fn main() {
    input! {t:usize,queries:[(i64,i64,i64,i64);t]}
    for (n, m, a, b) in queries {
        println!("{}", floor_sum(n as i128, m as i128, a as i128, b as i128));
    }
}
