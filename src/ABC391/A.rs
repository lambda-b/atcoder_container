use proconio::input;
fn main() {
    input! { d: String }
    let answer: String = d
        .chars()
        .map(|c| match c {
            'N' => 'S',
            'S' => 'N',
            'W' => 'E',
            'E' => 'W',
            _ => c,
        })
        .collect();
    println!("{answer}");
}
