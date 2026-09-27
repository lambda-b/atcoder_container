use proconio::input;
use std::collections::HashSet;
fn main() {
    input! { n:i64,m:usize, points:[(i64,i64);m] }
    let mut hit = HashSet::new();
    let ds = [
        (2, 1),
        (1, 2),
        (-1, 2),
        (-2, 1),
        (-2, -1),
        (-1, -2),
        (1, -2),
        (2, -1),
    ];
    for (a, b) in points {
        hit.insert((a, b));
        for (x, y) in ds {
            let p = (a + x, b + y);
            if 1 <= p.0 && p.0 <= n && 1 <= p.1 && p.1 <= n {
                hit.insert(p);
            }
        }
    }
    println!("{}", n * n - hit.len() as i64);
}
