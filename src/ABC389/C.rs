use proconio::input;
fn main() {
    input! {q:usize}
    let mut lengths = Vec::new();
    let mut removed = 0usize;
    for _ in 0..q {
        input! {t:u8}
        match t {
            1 => {
                input! {l:i64}
                lengths.push(l);
            }
            2 => {
                removed += 1;
            }
            _ => {
                input! {k:usize}
                println!("{}", lengths[removed..removed + k - 1].iter().sum::<i64>());
            }
        }
    }
}
