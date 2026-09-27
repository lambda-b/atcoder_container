use proconio::input;
fn main() {
    input! { n: usize, q: usize, queries: [(char, usize); q] }
    let (mut left, mut right, mut moves) = (0usize, 1usize, 0usize);
    for (hand, pos) in queries {
        let t = pos - 1;
        if hand == 'L' {
            let r0 = (right + n - left) % n;
            let t0 = (t + n - left) % n;
            moves += if r0 < t0 { (n - t0) % n } else { t0 };
            left = t;
        } else {
            let l0 = (left + n - right) % n;
            let t0 = (t + n - right) % n;
            moves += if l0 < t0 { (n - t0) % n } else { t0 };
            right = t;
        }
    }
    println!("{moves}");
}
