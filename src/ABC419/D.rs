use ac_library::{LazySegtree, MapMonoid, Monoid};
use proconio::input;
struct Or;
impl Monoid for Or {
    type S = bool;
    fn identity() -> bool {
        false
    }
    fn binary_operation(a: &bool, b: &bool) -> bool {
        *a || *b
    }
}
struct Xor;
impl MapMonoid for Xor {
    type M = Or;
    type F = bool;
    fn identity_map() -> bool {
        false
    }
    fn mapping(f: &bool, x: &bool) -> bool {
        *f ^ *x
    }
    fn composition(f: &bool, g: &bool) -> bool {
        *f ^ *g
    }
}
fn main() {
    input! { n:usize, m:usize, s: String, t:String, ranges:[(usize,usize);m] }
    let mut seg = LazySegtree::<Xor>::new(n);
    for (l, r) in ranges {
        seg.apply_range(l - 1..r, true);
    }
    let a = s.as_bytes();
    let b = t.as_bytes();
    let out = (0..n)
        .map(|i| if seg.get(i) { b[i] } else { a[i] } as char)
        .collect::<String>();
    println!("{out}");
}
