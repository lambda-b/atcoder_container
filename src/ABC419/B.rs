use proconio::input;
use std::cmp::Reverse;
use std::collections::BinaryHeap;
fn main() {
    input! { q: usize }
    let mut heap = BinaryHeap::new();
    for _ in 0..q {
        input! { t: u8 }
        if t == 1 {
            input! { x: i64 }
            heap.push(Reverse(x));
        } else if let Some(Reverse(x)) = heap.pop() {
            println!("{x}");
        }
    }
}
