use proconio::input;
fn solve(s: &[u8]) -> (u8, usize) {
    if s.len() == 1 {
        return (s[0], 1);
    }
    let k = s.len() / 3;
    let (a, x) = solve(&s[..k]);
    let (b, y) = solve(&s[k..2 * k]);
    let (c, z) = solve(&s[2 * k..]);
    if a == b && b == c {
        return (a, x + y + z - x.max(y).max(z));
    }
    if a == b {
        return (a, x.min(y));
    }
    if b == c {
        return (b, y.min(z));
    }
    (c, z.min(x))
}
fn main() {
    input! {_n:usize,s:String}
    let (_, count) = solve(s.as_bytes());
    println!("{count}");
}
