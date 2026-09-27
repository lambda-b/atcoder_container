use proconio::input;
fn main() {
    input! { n: usize, d: usize, snakes: [(i64, i64); n] }
    for k in 0..d {
        println!(
            "{}",
            snakes
                .iter()
                .map(|&(t, l)| t * (l + k as i64 + 1))
                .max()
                .unwrap()
        );
    }
}
