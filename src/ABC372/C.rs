use proconio::input;
fn main() {
    input! { n: usize, q: usize, mut s: String, queries: [(usize,char);q] }
    let mut a = s.into_bytes();
    let mut count = a.windows(3).filter(|w| *w == b"ABC").count() as i64;
    for (x, c) in queries {
        let i = x - 1;
        let start = i.saturating_sub(2);
        for j in start..=i.min(n.saturating_sub(3)) {
            if j + 2 < n && &a[j..j + 3] == b"ABC" {
                count -= 1;
            }
        }
        a[i] = c as u8;
        for j in start..=i.min(n.saturating_sub(3)) {
            if j + 2 < n && &a[j..j + 3] == b"ABC" {
                count += 1;
            }
        }
        println!("{count}");
    }
}
