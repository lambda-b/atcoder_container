use ac_library::{Monoid, Segtree};
use proconio::input;

struct Max;
impl Monoid for Max {
    type S = i32;
    fn identity() -> Self::S {
        -1
    }
    fn binary_operation(a: &Self::S, b: &Self::S) -> Self::S {
        (*a).max(*b)
    }
}

fn main() {
    input! { n: usize, h: [i32; n] }
    let mut seg = Segtree::<Max>::new(n);
    for (i, x) in h.iter().enumerate() {
        seg.set(i, x - 1);
    }
    let mut ans = vec![0usize; n];
    for i in (0..n.saturating_sub(1)).rev() {
        let height = seg.get(i + 1);
        let p = seg.max_right(i + 1, |x| *x <= height);
        ans[i] = ans[p - 1] + 1;
    }
    println!(
        "{}",
        ans.iter()
            .map(usize::to_string)
            .collect::<Vec<_>>()
            .join(" ")
    );
}
