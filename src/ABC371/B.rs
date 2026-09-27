use proconio::input;
fn main() {
    input! { n: usize, m: usize, records: [(usize, String); m] }
    let mut seen = vec![false; n];
    for (person, kind) in records {
        let i = person.saturating_sub(1);
        let yes = kind == "M" && !seen[i];
        if yes {
            seen[i] = true;
        }
        println!("{}", if yes { "Yes" } else { "No" });
    }
}
