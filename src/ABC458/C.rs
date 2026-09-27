use proconio::input;
fn main() {
    input! {s:String}
    let n = s.len() as i64;
    let answer: i64 = s
        .bytes()
        .enumerate()
        .filter(|&(_, c)| c == b'C')
        .map(|(i, _)| (i as i64 + 1).min(n - i as i64))
        .sum();
    println!("{answer}");
}
