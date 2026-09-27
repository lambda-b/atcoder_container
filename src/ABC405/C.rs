use proconio::input;
fn main() {
    input! {n:usize,a:[i64;n]}
    let (mut prefix, mut answer) = (0i64, 0i64);
    for x in a {
        answer += prefix * x;
        prefix += x;
    }
    println!("{answer}");
}
