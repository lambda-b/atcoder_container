use proconio::input;
fn main() {
    input! { mut a: i64, mut b: i64, mut c: i64 }
    if a == b && b == c {
        println!("Yes");
        return;
    }
    let mut values = [a, b, c];
    values.sort_unstable_by(|x, y| y.cmp(x));
    a = values[0];
    b = values[1];
    c = values[2];
    println!("{}", if a == b + c { "Yes" } else { "No" });
}
