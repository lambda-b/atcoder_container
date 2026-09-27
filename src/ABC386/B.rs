use proconio::input;
fn main() {
    input! { s: String }
    let b = s.as_bytes();
    let mut count = 0;
    let mut i = 0;
    while i < b.len() {
        count += 1;
        if b[i] == b'0' && i + 1 < b.len() && b[i + 1] == b'0' {
            i += 1;
        }
        i += 1;
    }
    println!("{count}");
}
