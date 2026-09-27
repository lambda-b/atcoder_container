use proconio::input;
fn main() {
    input! { n: usize, m: usize, a: [usize; n] }
    let mut seen = vec![false; m];
    let mut count = 0;
    for (i, x) in a.into_iter().enumerate() {
        if !seen[x - 1] {
            seen[x - 1] = true;
            count += 1;
        }
        if count == m {
            println!("{}", n - i);
            return;
        }
    }
    println!("0");
}
