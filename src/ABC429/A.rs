use proconio::input;
fn main() {
    input! { n: usize, m: usize }
    for i in 0..n {
        println!("{}", if i < m { "OK" } else { "Too Many Requests" });
    }
}
