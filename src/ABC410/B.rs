use proconio::input;
fn main() {
    input! { n: usize, q: usize, x: [usize; q] }
    let mut counts = vec![0usize; n];
    let mut answer = Vec::new();
    for v in x {
        let i = if v > 0 {
            v - 1
        } else {
            (0..n).min_by_key(|&i| (counts[i], i)).unwrap()
        };
        counts[i] += 1;
        answer.push(i + 1);
    }
    println!(
        "{}",
        answer
            .iter()
            .map(usize::to_string)
            .collect::<Vec<_>>()
            .join(" ")
    );
}
