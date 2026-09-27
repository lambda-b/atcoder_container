use proconio::input;
fn main() {
    input! {n:usize,m:usize,a:[i64;n]}
    let mut a = a;
    a.sort_unstable();
    a.dedup();
    let mut gaps = a.windows(2).map(|p| p[1] - p[0]).collect::<Vec<_>>();
    let mut answer = a.last().copied().unwrap_or(0) - a.first().copied().unwrap_or(0);
    gaps.sort_unstable_by(|x, y| y.cmp(x));
    for g in gaps.into_iter().take(m.saturating_sub(1)) {
        answer -= g;
    }
    println!("{answer}");
}
