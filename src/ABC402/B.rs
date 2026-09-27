use proconio::input;
use std::collections::VecDeque;
fn main() {
    input! { q: usize }
    let mut queue = VecDeque::new();
    for _ in 0..q {
        input! { t: u8 }
        if t == 1 {
            input! { x: i64 }
            queue.push_back(x);
        } else {
            println!("{}", queue.pop_front().unwrap_or(-1));
        }
    }
}
