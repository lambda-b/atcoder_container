use proconio::input;
use std::collections::VecDeque;
fn main() {
    input! {n:usize,requirements:[(usize,usize);n]}
    let mut g = vec![Vec::new(); n + 1];
    for (i, &(a, b)) in requirements.iter().enumerate() {
        if a == 0 && b == 0 {
            g[n].push(i);
        } else {
            if a > 0 {
                g[a - 1].push(i);
            }
            if b > 0 && b != a {
                g[b - 1].push(i);
            }
        }
    }
    let mut seen = vec![false; n + 1];
    seen[n] = true;
    let mut q = VecDeque::from([n]);
    while let Some(v) = q.pop_front() {
        for &u in &g[v] {
            if !seen[u] {
                seen[u] = true;
                q.push_back(u);
            }
        }
    }
    println!("{}", seen[..n].iter().filter(|&&x| x).count());
}
