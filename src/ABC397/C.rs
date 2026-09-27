use proconio::input;
fn main() {
    input! {n:usize,mut a:[usize;n]}
    let mut best = 0;
    for split in 1..n {
        let left: std::collections::HashSet<_> = a[..split].iter().collect();
        let right: std::collections::HashSet<_> = a[split..].iter().collect();
        best = best.max(left.len() + right.len());
    }
    println!("{best}");
}
