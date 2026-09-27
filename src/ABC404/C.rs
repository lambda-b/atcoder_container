use proconio::input;
use std::collections::VecDeque;
fn main() {
    input! {n:usize,m:usize,e:[(usize,usize);m]}
    let mut g = vec![Vec::new(); n];
    for (u, v) in e {
        g[u - 1].push(v - 1);
        g[v - 1].push(u - 1);
    }
    let mut seen = vec![false; n];
    let mut q = VecDeque::from([0]);
    seen[0] = true;
    while let Some(v) = q.pop_front() {
        for &u in &g[v] {
            if !seen[u] {
                seen[u] = true;
                q.push_back(u);
            }
        }
    }
    println!(
        "{}",
        if g.iter().all(|x| x.len() == 2) && seen.iter().all(|&x| x) {
            "Yes"
        } else {
            "No"
        }
    );
}
