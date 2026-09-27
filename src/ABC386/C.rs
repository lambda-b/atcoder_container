use proconio::input;
fn main() {
    input! {_k:usize,s:String,t:String}
    let a = s.as_bytes();
    let b = t.as_bytes();
    let (mut i, mut j, mut edits) = (0, 0, 0);
    while i < a.len() && j < b.len() {
        if a[i] == b[j] {
            i += 1;
            j += 1;
        } else {
            edits += 1;
            if edits > 1 {
                break;
            }
            if a.len() >= b.len() {
                i += 1;
            }
            if b.len() >= a.len() {
                j += 1;
            }
        }
    }
    edits += (a.len() - i) + (b.len() - j);
    println!("{}", if edits <= 1 { "Yes" } else { "No" });
}
