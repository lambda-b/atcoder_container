use proconio::input;
fn main() {
    input! {n:usize,w:usize,blocks:[(usize,i64);n]}
    let mut columns = vec![Vec::new(); w];
    for (i, (x, y)) in blocks.into_iter().enumerate() {
        columns[x - 1].push((y, i));
    }
    let mut order = vec![0; n];
    let mut min_count = usize::MAX;
    for col in &mut columns {
        col.sort_unstable();
        min_count = min_count.min(col.len());
        for (j, &(_, id)) in col.iter().enumerate() {
            order[id] = j;
        }
    }
    let mut disappear = vec![0i64; min_count];
    for i in 0..min_count {
        disappear[i] = columns.iter().map(|c| c[i].0).max().unwrap();
    }
    input! {q:usize}
    for _ in 0..q {
        input! {t:i64,a:usize}
        let level = order[a - 1];
        println!(
            "{}",
            if level < min_count && disappear[level] <= t {
                "No"
            } else {
                "Yes"
            }
        );
    }
}
