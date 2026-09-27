use proconio::input;
use std::collections::BTreeSet;
fn main() {
    input! { n: usize, a: [usize; n] }
    let values: BTreeSet<_> = a.into_iter().collect();
    println!("{}", (0..=n).find(|x| !values.contains(x)).unwrap());
}
