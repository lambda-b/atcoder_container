use proconio::input;
fn main() {
    input! {n:usize,x:usize,percent:[f64;n]}
    let p = percent.into_iter().map(|x| x / 100.).collect::<Vec<_>>();
    let mut prob = vec![0.0; n + 1];
    prob[0] = 1.0;
    for (i, &chance) in p.iter().enumerate() {
        for j in (0..=i + 1).rev() {
            let stay = if j <= i {
                prob[j] * (1.0 - chance)
            } else {
                0.0
            };
            let hit = if j > 0 { prob[j - 1] * chance } else { 0.0 };
            prob[j] = stay + hit;
        }
    }
    let mut expect = vec![0.0; x + 1];
    for i in 1..=x {
        let mut value = 1.0;
        for j in 1..=n {
            value += expect[i.saturating_sub(j)] * prob[j];
        }
        expect[i] = value / (1.0 - prob[0]);
    }
    println!("{:.16}", expect[x]);
}
