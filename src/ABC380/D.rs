use proconio::input;
fn main() {
    input! {s:String,q:usize,k:[u64;q]}
    let n = s.len() as u64;
    let b = s.as_bytes();
    let out = k
        .iter()
        .map(|&x| {
            let x = x - 1;
            let block = x / n;
            let ch = b[(x % n) as usize] as char;
            if block.count_ones() % 2 == 0 {
                ch.to_string()
            } else {
                ch.to_ascii_uppercase().to_string()
            }
        })
        .collect::<Vec<_>>();
    println!("{}", out.join(" "));
}
