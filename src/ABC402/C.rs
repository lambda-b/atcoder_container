use proconio::input;
fn main() {
    input! {n:usize,m:usize}
    let mut boxes = vec![Vec::new(); n];
    let mut remaining = vec![0usize; m];
    for j in 0..m {
        input! {k:usize,items:[usize;k]}
        remaining[j] = k;
        for x in items {
            boxes[x - 1].push(j);
        }
    }
    let mut empty = remaining.iter().filter(|&&x| x == 0).count();
    for _ in 0..n {
        input! {x:usize}
        for &j in &boxes[x - 1] {
            remaining[j] -= 1;
            if remaining[j] == 0 {
                empty += 1;
            }
        }
        println!("{empty}");
    }
}
