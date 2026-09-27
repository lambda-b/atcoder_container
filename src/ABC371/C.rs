use proconio::input;
fn next_perm(a: &mut [usize]) -> bool {
    let Some(i) = (0..a.len() - 1).rev().find(|&i| a[i] < a[i + 1]) else {
        return false;
    };
    let j = (i + 1..a.len()).rev().find(|&j| a[i] < a[j]).unwrap();
    a.swap(i, j);
    a[i + 1..].reverse();
    true
}
fn main() {
    input! { n: usize, mg: usize, ge: [(usize,usize); mg], mh: usize, he: [(usize,usize); mh] }
    let mut g = vec![vec![false; n]; n];
    let mut h = vec![vec![false; n]; n];
    for (u, v) in ge {
        g[u - 1][v - 1] = true;
        g[v - 1][u - 1] = true;
    }
    for (u, v) in he {
        h[u - 1][v - 1] = true;
        h[v - 1][u - 1] = true;
    }
    let mut cost = vec![vec![0i64; n]; n];
    for (i, row) in cost.iter_mut().enumerate() {
        for cell in row.iter_mut().skip(i + 1) {
            input! { x:i64 }
            *cell = x;
        }
    }
    let mut p: Vec<_> = (0..n).collect();
    let mut ans = i64::MAX;
    loop {
        let mut cur = 0;
        for i in 0..n {
            for j in i + 1..n {
                if g[p[i]][p[j]] != h[i][j] {
                    cur += cost[i][j];
                }
            }
        }
        ans = ans.min(cur);
        if !next_perm(&mut p) {
            break;
        }
    }
    println!("{ans}");
}
