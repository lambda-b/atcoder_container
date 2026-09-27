use proconio::input;
fn main() {
    input! { n: usize, a: [i64; n] }
    println!("{}", a.iter().step_by(2).sum::<i64>());
}
