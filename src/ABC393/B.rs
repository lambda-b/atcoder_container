use proconio::input;
fn main() {
    input! { s: String }
    let b = s.as_bytes();
    let mut answer = 0;
    for i in 0..b.len() {
        if b[i] == b'A' {
            for j in i + 1..b.len() {
                if b[j] == b'B' {
                    let k = j + (j - i);
                    if k < b.len() && b[k] == b'C' {
                        answer += 1;
                    }
                }
            }
        }
    }
    println!("{answer}");
}
