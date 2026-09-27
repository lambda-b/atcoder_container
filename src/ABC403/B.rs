use proconio::input;
fn main() {
    input! { t: String, u: String }
    let yes = t
        .as_bytes()
        .windows(u.len())
        .any(|w| w.iter().zip(u.bytes()).all(|(&a, b)| a == b || a == b'?'));
    println!("{}", if yes { "Yes" } else { "No" });
}
