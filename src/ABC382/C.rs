use proconio::input;
use std::collections::BTreeMap;
fn main() {
    input! { n:usize,m:usize,a:[i64;n],b:[i64;m] }
    let mut map = BTreeMap::new();
    for (i, x) in a.into_iter().enumerate() {
        if map.range(..=x).next_back().is_none() {
            map.insert(x, i + 1);
        }
    }
    for x in b {
        if let Some((_, &i)) = map.range(..=x).next_back() {
            println!("{i}");
        } else {
            println!("-1");
        }
    }
}
