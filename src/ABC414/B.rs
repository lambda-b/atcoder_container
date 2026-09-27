use proconio::input;
fn main() {
    input! { n: usize, runs: [(char, usize); n] }
    let mut s = String::new();
    for (c, count) in runs {
        if s.len() + count > 100 {
            println!("Too Long");
            return;
        }
        s.extend(std::iter::repeat_n(c, count));
    }
    println!("{s}");
}
