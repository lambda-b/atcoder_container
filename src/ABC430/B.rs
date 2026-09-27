use proconio::input;
use std::collections::HashSet;
fn main() {
    input! { n: usize, m: usize, grid: [String; n] }
    let mut patterns = HashSet::new();
    for i in 0..=n - m {
        for j in 0..=n - m {
            let pattern: String = (i..i + m).flat_map(|r| grid[r][j..j + m].chars()).collect();
            patterns.insert(pattern);
        }
    }
    println!("{}", patterns.len());
}
