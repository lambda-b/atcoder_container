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
    input! { n: usize, q: usize, a: [i32; n] }
    let mut seg = Segtree::<Max>::from(a);
    for _ in 0..q {
        input! { t: u8, x: usize, v: i32 }
        match t {
            1 => seg.set(x - 1, v),
            2 => println!("{}", seg.prod(x - 1..v as usize)),
            3 => println!("{}", seg.max_right(x - 1, |a| *a < v) + 1),
            _ => unreachable!(),
        }
    }
}
