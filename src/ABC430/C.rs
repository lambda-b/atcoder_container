use ac_library::{Monoid, Segtree};
use proconio::input;

struct Min;
impl Monoid for Min {
    type S = i32;
    fn identity() -> Self::S {
        i32::MAX
    }
    fn binary_operation(a: &Self::S, b: &Self::S) -> Self::S {
        (*a).min(*b)
    }
}

fn main() {
    input! { n: usize, a: usize, b: usize, s: String }
    let bytes = s.as_bytes();
    let (mut ca, mut cb) = (0, 0);
    let (mut sa, mut sb) = (Segtree::<Min>::new(n), Segtree::<Min>::new(n));
    for (i, &ch) in bytes.iter().enumerate() {
        if ch == b'a' {
            ca += 1;
        }
        if ch == b'b' {
            cb += 1;
        }
        sa.set(i, ca);
        sb.set(i, cb);
    }
    let mut ans = 0i64;
    for i in 0..n {
        let xa = sa.get(i);
        if xa < a as i32 {
            continue;
        }
        let xb = sb.get(i);
        let l = sa.min_left(i + 1, |x| xa - *x < a as i32);
        let r = sb.min_left(i + 1, |x| xb - *x < b as i32);
        ans += l.saturating_sub(r) as i64;
    }
    println!("{ans}");
}
