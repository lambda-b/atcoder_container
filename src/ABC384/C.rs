use proconio::input;
fn main() {
    input! { v:[i64;5] }
    let mut names = Vec::new();
    for mask in 1..32 {
        let mut name = String::new();
        let mut score = 0;
        for i in 0..5 {
            if mask >> i & 1 == 1 {
                name.push((b'A' + i as u8) as char);
                score += v[i];
            }
        }
        names.push((score, name));
    }
    names.sort_by(|a, b| b.0.cmp(&a.0).then(a.1.cmp(&b.1)));
    for (_, name) in names {
        println!("{name}");
    }
}
