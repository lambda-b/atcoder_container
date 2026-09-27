use proconio::input;
fn main() {
    input! {n:usize,s:String}
    let mut pos = Vec::new();
    for (i, c) in s.bytes().enumerate() {
        if c == b'1' {
            pos.push(i as i64);
        }
    }
    let k = pos.len() as i64;
    let mut cur: i64 = pos.iter().enumerate().map(|(i, &x)| x - i as i64).sum();
    let mut best = cur;
    let mut left = 0i64;
    for c in s.bytes() {
        if c == b'1' {
            left += 1;
        } else {
            cur += 2 * left - k;
            best = best.min(cur);
        }
    }
    let _ = n;
    println!("{best}");
}
