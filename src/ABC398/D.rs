use proconio::input;
use std::collections::HashSet;
fn main() {
    input! {n:usize,r:i64,c:i64,s:String}
    let (mut smoke, mut person) = ((0i64, 0i64), (r, c));
    let mut seen = HashSet::from([smoke]);
    let mut out = String::new();
    for d in s.chars() {
        let (dr, dc) = match d {
            'N' => (1, 0),
            'S' => (-1, 0),
            'W' => (0, 1),
            _ => (0, -1),
        };
        smoke.0 += dr;
        smoke.1 += dc;
        person.0 += dr;
        person.1 += dc;
        seen.insert(smoke);
        out.push(if seen.contains(&person) { '1' } else { '0' });
    }
    let _ = n;
    println!("{out}");
}
