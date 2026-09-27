use proconio::input;
use std::collections::HashMap;
fn main() {
    input! {n:usize,a:[i64;n]}
    let mut c = HashMap::new();
    for &x in &a {
        *c.entry(x).or_insert(0usize) += 1;
    }
    let answer = a
        .iter()
        .enumerate()
        .filter(|(_, x)| c[x] == 1)
        .max_by_key(|(_, x)| *x)
        .map(|(i, _)| i + 1)
        .unwrap_or(0);
    println!("{answer}");
}
