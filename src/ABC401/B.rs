use proconio::input;
fn main() {
    input! { n: usize, commands: [String; n] }
    let (mut logged, mut private) = (false, 0);
    for c in commands {
        match c.as_str() {
            "login" => logged = true,
            "logout" => logged = false,
            "private" if !logged => private += 1,
            _ => {}
        }
    }
    println!("{private}");
}
