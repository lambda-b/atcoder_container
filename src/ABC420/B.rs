use proconio::input;
fn main() {
    input! { n: usize, m: usize, s: [String; n] }
    let mut score = vec![0; n];
    for j in 0..m {
        let ones = s.iter().filter(|x| x.as_bytes()[j] == b'1').count();
        let loser = if ones > n / 2 { b'1' } else { b'0' };
        for i in 0..n {
            if s[i].as_bytes()[j] != loser {
                score[i] += 1;
            }
        }
    }
    let best = *score.iter().max().unwrap();
    println!(
        "{}",
        score
            .iter()
            .enumerate()
            .filter(|(_, x)| **x == best)
            .map(|(i, _)| (i + 1).to_string())
            .collect::<Vec<_>>()
            .join(" ")
    );
}
