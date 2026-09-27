use proconio::input;
use std::collections::BTreeMap;
fn main() {
    input! { n: usize, p: [i64; n] }
    let mut counts = BTreeMap::new();
    for &x in &p {
        *counts.entry(x).or_insert(0usize) += 1;
    }
    for x in p {
        let greater: usize = counts
            .range((std::ops::Bound::Excluded(x), std::ops::Bound::Unbounded))
            .map(|(_, &c)| c)
            .sum();
        println!("{}", greater + 1);
    }
}
