use proconio::input;
fn main() {
    input! { n: usize, mut a: [i64;n], b: [i64;n-1] }
    a.sort_unstable_by(|x, y| y.cmp(x));
    let mut b = b;
    b.push(0);
    b.sort_unstable_by(|x, y| y.cmp(x));
    let mut j = 0;
    let mut answer = 0;
    for &x in &a {
        if j < n && x <= b[j] {
            j += 1;
        } else if answer == 0 {
            answer = x;
        } else {
            println!("-1");
            return;
        }
    }
    println!("{answer}");
}
