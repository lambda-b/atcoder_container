use proconio::input;
use std::collections::HashSet;
fn main() {
    input! {_n:usize,m:usize,q:usize}
    let mut allowed = vec![HashSet::new(); _n];
    for _ in 0..q {
        input! {t:u8,x:usize}
        let x = x - 1;
        if t == 1 {
            input! {y:usize}
            allowed[x].insert(y - 1);
        } else if t == 2 {
            allowed[x].insert(m);
        } else {
            input! {y:usize}
            println!(
                "{}",
                if allowed[x].contains(&m) || allowed[x].contains(&(y - 1)) {
                    "Yes"
                } else {
                    "No"
                }
            );
        }
    }
}
