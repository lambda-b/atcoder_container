use proconio::input;
fn main() {
    input! {h:usize,w:usize,d:i32,grid:[String;h]}
    let mut open = Vec::new();
    for i in 0..h {
        for j in 0..w {
            if grid[i].as_bytes()[j] == b'.' {
                open.push((i as i32, j as i32));
            }
        }
    }
    let mut best = 0;
    for x in 0..open.len() {
        for y in x + 1..open.len() {
            let covered = open
                .iter()
                .filter(|&&(i, j)| {
                    (i - open[x].0).abs() + (j - open[x].1).abs() <= d
                        || (i - open[y].0).abs() + (j - open[y].1).abs() <= d
                })
                .count();
            best = best.max(covered);
        }
    }
    println!("{best}");
}
