use proconio::input;
fn main() {
    input! { n:usize,k:usize,s:String }
    let mut runs = Vec::new();
    let mut start = 0;
    let b = s.as_bytes();
    while start < n {
        if b[start] == b'1' {
            let mut end = start + 1;
            while end < n && b[end] == b'1' {
                end += 1;
            }
            runs.push((start, end - start));
            start = end;
        } else {
            start += 1;
        }
    }
    let (st, len) = runs[k - 1];
    let prev = runs[k - 2];
    let mut out = String::new();
    out.push_str(&s[..prev.0]);
    out.push_str(&"1".repeat(prev.1 + len));
    out.push_str(&"0".repeat(n - st - len));
    println!("{out}");
}
