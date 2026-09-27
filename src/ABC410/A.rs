use proconio::input;
fn main() {
    input! { n: usize, a: [i64; n], k: i64 }
    println!("{}", a.iter().filter(|&&x| x >= k).count());
}
