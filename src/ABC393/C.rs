use proconio::input;
use std::collections::HashSet;
fn main() {
    input! {n:usize,m:usize,e:[(usize,usize);m]}
    let mut set = HashSet::new();
    for (u, v) in e {
        if u != v {
            set.insert((u.min(v), u.max(v)));
        }
    }
    println!("{}", m - set.len());
    let _ = n;
}
