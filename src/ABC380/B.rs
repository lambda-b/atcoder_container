use proconio::input;
fn main() {
    input! { s: String }
    let bytes = s.as_bytes();
    let mut groups = Vec::new();
    let mut count = 0;
    for &c in &bytes[1..bytes.len() - 1] {
        if c == b'-' {
            count += 1;
        } else {
            groups.push(count);
            count = 0;
        }
    }
    groups.push(count);
    println!(
        "{}",
        groups
            .iter()
            .map(usize::to_string)
            .collect::<Vec<_>>()
            .join(" ")
    );
}
