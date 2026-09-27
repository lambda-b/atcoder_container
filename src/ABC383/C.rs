use proconio::input;
use std::collections::VecDeque;
fn main() {
    input! { h:usize,w:usize,d:usize,grid:[String;h] }
    let mut dist = vec![vec![usize::MAX; w]; h];
    let mut q = VecDeque::new();
    for i in 0..h {
        for j in 0..w {
            if grid[i].as_bytes()[j] == b'H' {
                dist[i][j] = 0;
                q.push_back((i, j));
            }
        }
    }
    while let Some((i, j)) = q.pop_front() {
        if dist[i][j] == d {
            continue;
        }
        for (di, dj) in [(1isize, 0isize), (-1, 0), (0, 1), (0, -1)] {
            let ni = i as isize + di;
            let nj = j as isize + dj;
            if ni >= 0 && nj >= 0 && (ni as usize) < h && (nj as usize) < w {
                let (ni, nj) = (ni as usize, nj as usize);
                if grid[ni].as_bytes()[nj] != b'#' && dist[ni][nj] == usize::MAX {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push_back((ni, nj));
                }
            }
        }
    }
    println!("{}", dist.iter().flatten().filter(|&&x| x <= d).count());
}
