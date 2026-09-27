use proconio::input;
use std::collections::HashMap;
fn main() {
    input! { n: usize, m: usize, a: [i64; n], b: [i64; m] }
    let mut cnt = HashMap::new();
    for x in b {
        *cnt.entry(x).or_insert(0usize) += 1;
    }
    let mut answer = Vec::new();
    for x in a {
        if let Some(c) = cnt.get_mut(&x) {
            if *c > 0 {
                *c -= 1;
                continue;
            }
        }
        answer.push(x);
    }
    println!(
        "{}",
        answer
            .iter()
            .map(i64::to_string)
            .collect::<Vec<_>>()
            .join(" ")
    );
}
