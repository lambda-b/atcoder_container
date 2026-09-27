use proconio::input;
fn main() {
    input! {n:usize,q:usize}
    let mut a: Vec<i64> = (1..=n as i64).collect();
    let mut head = 0usize;
    for _ in 0..q {
        input! {t:u8}
        match t {
            1 => {
                input! {p:usize,x:i64}
                a[(head + p - 1) % n] = x;
            }
            2 => {
                input! {p:usize}
                println!("{}", a[(head + p - 1) % n]);
            }
            _ => {
                input! {k:usize}
                head = (head + k) % n;
            }
        }
    }
}
