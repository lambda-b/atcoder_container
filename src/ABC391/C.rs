use proconio::input;
fn main() {
    input! { n: usize, q: usize }
    let (mut bird, mut count) = (vec![0; n], vec![1usize; n]);
    let mut doubles = 0;
    for _ in 0..q {
        input! { t: u8 }
        if t == 1 {
            input! { p: usize, h: usize }
            let (p, h) = (p - 1, h - 1);
            let old = bird[p];
            if count[old] == 2 {
                doubles -= 1;
            }
            count[old] -= 1;
            bird[p] = h;
            count[h] += 1;
            if count[h] == 2 {
                doubles += 1;
            }
        } else {
            println!("{doubles}");
        }
    }
}
