use proconio::input;
fn main() {
    input! {s:String}
    let mut stack = Vec::new();
    let mut ok = true;
    for c in s.chars() {
        match c {
            '(' | '<' | '[' => stack.push(c),
            ')' | '>' | ']' => {
                let expected = match c {
                    ')' => '(',
                    '>' => '<',
                    _ => '[',
                };
                if stack.pop() != Some(expected) {
                    ok = false;
                    break;
                }
            }
            _ => {}
        }
    }
    println!("{}", if ok && stack.is_empty() { "Yes" } else { "No" });
}
