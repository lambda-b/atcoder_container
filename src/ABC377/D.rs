use proconio::input;
fn main() {
    input! {n:usize,m:usize,lr:[(usize,usize);n]}
    let mut a = lr
        .into_iter()
        .map(|(l, r)| (l - 1, r - 1))
        .collect::<Vec<_>>();
    a.sort_unstable();
    let mut suffix = vec![m as i64; n + 1];
    for i in (0..n).rev() {
        suffix[i] = suffix[i + 1].min(a[i].1 as i64);
    }
    let mut ans = 0i64;
    for i in 0..=m {
        let k = a.partition_point(|&(l, _)| l < i);
        let x = suffix[k].min(m as i64);
        ans += x - i as i64;
    }
    println!("{ans}");
}
