use proconio::input;
fn main() {
    input! { n: usize, s: i64, t: [i64; n] }
    let mut previous = 0;
    for time in t {
        if time - previous > s {
            println!("No");
            return;
        }
        previous = time;
    }
    println!("Yes");
}
