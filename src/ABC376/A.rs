use proconio::input;
fn main() {
    input! { n: usize, c: i64, t: [i64; n] }
    let mut count = 0;
    let mut previous = -c;
    for time in t {
        if time >= previous + c {
            count += 1;
            previous = time;
        }
    }
    println!("{count}");
}
