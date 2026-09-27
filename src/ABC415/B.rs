use proconio::input;
fn main() {
    input! { s: String }
    let mut start = None;
    for (i, c) in s.bytes().enumerate() {
        if c == b'#' {
            if let Some(p) = start.take() {
                println!("{},{}", p + 1, i + 1);
            } else {
                start = Some(i);
            }
        }
    }
}
