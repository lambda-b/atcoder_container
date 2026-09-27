use proconio::input;
fn main() {
    input! { _n: usize, d: usize, s: String }
    let keep = s.bytes().filter(|&c| c == b'@').count().saturating_sub(d);
    let mut left = keep;
    let ans: String = s
        .chars()
        .map(|c| {
            if c == '@' && left > 0 {
                left -= 1;
                '@'
            } else {
                '.'
            }
        })
        .collect();
    println!("{ans}");
}
