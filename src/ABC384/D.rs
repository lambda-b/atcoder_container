use proconio::input;
fn main() {
    input! {n:usize,s:i64,a:[i64;n]}
    let total: i64 = a.iter().sum();
    let target = s.rem_euclid(total);
    if target == 0 {
        println!("Yes");
        return;
    }
    let mut pref = vec![0i64; 2 * n + 1];
    for i in 0..2 * n {
        pref[i + 1] = pref[i] + a[i % n];
    }
    let mut left = 0;
    let mut yes = false;
    for right in 1..=2 * n {
        while pref[right] - pref[left] > target || right - left > n {
            left += 1;
        }
        if pref[right] - pref[left] == target {
            yes = true;
            break;
        }
    }
    println!("{}", if yes { "Yes" } else { "No" });
}
