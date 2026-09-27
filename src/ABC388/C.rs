use proconio::input;
fn main() {
    input! {n:usize,mut a:[i64;n]}
    a.sort_unstable();
    let mut answer = 0i64;
    for i in 0..n {
        let twice = 2 * a[i];
        let j = a.partition_point(|&x| x < twice);
        answer += (n - j) as i64;
    }
    println!("{answer}");
}
