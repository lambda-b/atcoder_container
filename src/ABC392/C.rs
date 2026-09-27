use proconio::input;
fn main() {
    input! {n:usize,p:[usize;n],q:[usize;n]}
    let mut answer = vec![0; n];
    for i in 0..n {
        answer[q[i] - 1] = q[p[i] - 1];
    }
    println!(
        "{}",
        answer
            .iter()
            .map(usize::to_string)
            .collect::<Vec<_>>()
            .join(" ")
    );
}
