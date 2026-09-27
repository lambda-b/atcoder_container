use proconio::input;
fn main() {
    input! { s: String }
    let b = s.as_bytes();
    println!("{}", (b[0] - b'0') * (b[2] - b'0'));
}
