use proconio::input;
use std::collections::HashSet;
fn main() {
    input! { n: usize, m: usize, a: [usize; m] }
    let gone: HashSet<_> = a.into_iter().collect();
    let b: Vec<_> = (1..=n).filter(|x| !gone.contains(x)).collect();
    println!("{}", b.len());
    println!(
        "{}",
        b.iter().map(usize::to_string).collect::<Vec<_>>().join(" ")
    );
}
