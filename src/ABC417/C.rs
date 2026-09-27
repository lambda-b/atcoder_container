use proconio::input;
use std::collections::HashMap;
fn main() {
    input! {n:usize,a:[i64;n]}
    let mut freq = HashMap::new();
    let mut answer = 0i64;
    for (i, &x) in a.iter().enumerate() {
        let i = i as i64;
        answer += freq.get(&(i - x)).copied().unwrap_or(0);
        *freq.entry(i + x).or_insert(0) += 1;
    }
    println!("{answer}");
}
