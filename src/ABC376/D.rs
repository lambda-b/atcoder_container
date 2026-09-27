use proconio::input;
use std::collections::VecDeque;
fn main() {
    input! {n:usize,m:usize,edges:[(usize,usize);m]}
    let mut g = vec![Vec::new(); n];
    for (a, b) in edges {
        g[a - 1].push(b - 1);
    }
    let mut d = vec![usize::MAX; n];
    let mut q = VecDeque::new();
    d[0] = 0;
    q.push_back(0);
    while let Some(v) = q.pop_front() {
        for &u in &g[v] {
            if d[u] == usize::MAX {
                d[u] = d[v] + 1;
                q.push_back(u);
            }
        }
    }
    let ans = g
        .iter()
        .enumerate()
        .filter(|(_, e)| e.contains(&0))
        .map(|(v, _)| d[v].saturating_add(1))
        .min()
        .unwrap_or(usize::MAX);
    println!("{}", if ans == usize::MAX { -1 } else { ans as i64 });
}
