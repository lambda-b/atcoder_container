use proconio::input;
fn main() {
    input! {mut s:String}
    let b = unsafe { s.as_bytes_mut() };
    for i in (1..b.len()).rev() {
        if b[i] == b'A' && b[i - 1] == b'W' {
            b[i] = b'C';
            b[i - 1] = b'A';
        }
    }
    println!("{}", String::from_utf8(b.to_vec()).unwrap());
}
