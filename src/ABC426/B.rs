use proconio::input;
use std::collections::BTreeMap;
fn main() {
    input! { s: String }
    let mut count = BTreeMap::new();
    for c in s.chars() {
        *count.entry(c).or_insert(0) += 1;
    }
    if let Some((&c, _)) = count.iter().find(|(_, v)| **v == 1) {
        println!("{c}");
    }
}
