use proconio::input;
use std::collections::HashSet;
fn main() {
    input! {n:usize,_m:usize}
    let mut devices = Vec::with_capacity(n);
    for _ in 0..n {
        input! {k:usize,items:[usize;k]}
        devices.push(items);
    }
    input! {p:usize,q:usize,checks:[usize;p]}
    let checked: HashSet<_> = checks.into_iter().collect();
    let answer = devices
        .iter()
        .filter(|d| d.iter().filter(|x| checked.contains(x)).count() >= q)
        .count();
    println!("{answer}");
}
