use proconio::input;
fn root(parent: &mut [usize], x: usize) -> usize {
    if parent[x] != x {
        parent[x] = root(parent, parent[x]);
    }
    parent[x]
}
fn main() {
    input! { n: usize, q: usize }
    let (mut parent, mut size, mut black) =
        ((0..n).collect::<Vec<_>>(), vec![1usize; n], vec![0i64; n]);
    let mut color = vec![false; n];
    for _ in 0..q {
        input! { t: u8 }
        if t == 1 {
            input! { u: usize, v: usize }
            let (mut a, mut b) = (root(&mut parent, u - 1), root(&mut parent, v - 1));
            if a != b {
                if size[a] < size[b] {
                    std::mem::swap(&mut a, &mut b);
                }
                parent[b] = a;
                size[a] += size[b];
                black[a] += black[b];
            }
        } else {
            input! { v: usize }
            let v = v - 1;
            let r = root(&mut parent, v);
            if t == 2 {
                black[r] += if color[v] { -1 } else { 1 };
                color[v] = !color[v];
            } else {
                println!("{}", if black[r] > 0 { "Yes" } else { "No" });
            }
        }
    }
}
