use proconio::input;
fn main() {
    input! { n: usize, m: usize, k: usize, submissions: [(usize, usize); k] }
    let mut count = vec![0; n];
    let mut completed = Vec::new();
    for (a, _) in submissions {
        count[a - 1] += 1;
        if count[a - 1] == m {
            completed.push(a);
        }
    }
    println!(
        "{}",
        completed
            .iter()
            .map(usize::to_string)
            .collect::<Vec<_>>()
            .join(" ")
    );
}
