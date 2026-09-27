use proconio::input;
fn main() {
    input! {s:String}
    let mut chars = s.bytes().map(|x| (x - b'0') as i32).collect::<Vec<_>>();
    chars.push(0);
    let mut answer = 0;
    for i in 0..chars.len() - 1 {
        answer += 1 + (10 + chars[i] - chars[i + 1]) % 10;
    }
    println!("{answer}");
}
