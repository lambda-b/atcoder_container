use proconio::input;
fn main() {
    input! { n: usize, s: [String; n], t: [String; n] }
    let mut best = usize::MAX;
    for rotation in 0..4 {
        let mut diff = 0;
        for i in 0..n {
            for j in 0..n {
                let (r, c) = match rotation {
                    0 => (i, j),
                    1 => (n - 1 - j, i),
                    2 => (n - 1 - i, n - 1 - j),
                    _ => (j, n - 1 - i),
                };
                if s[r].as_bytes()[c] != t[i].as_bytes()[j] {
                    diff += 1;
                }
            }
        }
        best = best.min(diff + rotation);
    }
    println!("{best}");
}
