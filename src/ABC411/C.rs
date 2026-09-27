use proconio::input;
fn main() {
    input! {n:usize,q:usize,queries:[usize;q]}
    let mut box_on = vec![false; n];
    let mut components = 0i64;
    for x in queries {
        let i = x - 1;
        let left = i > 0 && box_on[i - 1];
        let right = i + 1 < n && box_on[i + 1];
        if !left && !right {
            components += if box_on[i] { -1 } else { 1 };
        } else if left && right {
            components += if box_on[i] { 1 } else { -1 };
        }
        box_on[i] = !box_on[i];
        println!("{components}");
    }
}
