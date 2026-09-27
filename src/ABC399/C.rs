use proconio::input;
fn main() {
    input! {n:usize,m:usize,e:[(usize,usize);m]}
    let mut p: Vec<_> = (0..n).collect();
    fn root(p: &mut [usize], x: usize) -> usize {
        if p[x] != x {
            p[x] = root(p, p[x]);
        }
        p[x]
    }
    let mut cycles = 0;
    for (u, v) in e {
        let (a, b) = (root(&mut p, u - 1), root(&mut p, v - 1));
        if a == b {
            cycles += 1;
        } else {
            p[a] = b;
        }
    }
    println!("{cycles}");
}
