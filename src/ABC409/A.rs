use proconio::input;
fn main() {
    input! { _n: usize, t: String, a: String }
    let yes = t
        .bytes()
        .zip(a.bytes())
        .any(|(x, y)| x == b'o' && y == b'o');
    println!("{}", if yes { "Yes" } else { "No" });
}
