use proconio::input;
fn main() {
    input! {n:usize,x:[i64;n],p:[i64;n],q:usize}
    let mut pref = vec![0i64; n + 1];
    for i in 0..n {
        pref[i + 1] = pref[i] + p[i];
    }
    for _ in 0..q {
        input! {l:i64,r:i64}
        let a = x.partition_point(|&v| v < l);
        let b = x.partition_point(|&v| v <= r);
        println!("{}", pref[b] - pref[a]);
    }
}
