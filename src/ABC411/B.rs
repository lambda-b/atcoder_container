use proconio::input;
fn main() {
    input! { n: usize, d: [i64; n-1] }
    for i in 0..n - 1 {
        let mut sum = 0;
        let row: Vec<_> = d[i..]
            .iter()
            .map(|&x| {
                sum += x;
                sum.to_string()
            })
            .collect();
        println!("{}", row.join(" "));
    }
}
