use proconio::input;
fn main() {
    input! { n: usize, mut a: [i64; n] }
    a.sort_unstable();
    a.dedup();
    println!("{}", a.len());
    println!(
        "{}",
        a.iter().map(i64::to_string).collect::<Vec<_>>().join(" ")
    );
}
