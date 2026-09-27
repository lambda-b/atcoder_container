use proconio::input;
fn main() {
    input! { n: usize, q: usize, values: [i64; n] }
    let size = n.next_power_of_two();
    let mut tree = vec![0i64; 2 * size];
    tree[size..size + n].copy_from_slice(&values);
    for i in (1..size).rev() {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    for _ in 0..q {
        input! { t: u8, l: usize, r: i64 }
        if t == 1 {
            let mut a = l + size;
            let mut b = r as usize + size;
            let mut sum = 0;
            while a < b {
                if a % 2 == 1 {
                    sum += tree[a];
                    a += 1;
                }
                if b % 2 == 1 {
                    b -= 1;
                    sum += tree[b];
                }
                a /= 2;
                b /= 2;
            }
            println!("{sum}");
        } else {
            let p = l + size;
            tree[p] += r;
            let mut i = p / 2;
            while i > 0 {
                tree[i] = tree[i * 2] + tree[i * 2 + 1];
                i /= 2;
            }
        }
    }
}
