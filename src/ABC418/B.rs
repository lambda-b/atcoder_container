use proconio::input;
fn main() {
    input! { s: String }
    let b = s.as_bytes();
    let mut best = 0.0f64;
    for i in 0..b.len() {
        if b[i] == b't' {
            for j in i + 2..b.len() {
                if b[j] == b't' {
                    best = best.max(
                        (b[i..=j].iter().filter(|&&c| c == b't').count() - 2) as f64
                            / (j - i - 1) as f64,
                    );
                }
            }
        }
    }
    println!("{best:.17}");
}
