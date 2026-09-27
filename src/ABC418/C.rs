use proconio::input;
fn main() {
    input! {n:usize,q:usize,mut a:[usize;n],queries:[usize;q]}
    a.sort_unstable();
    let m = *a.last().unwrap();
    let mut pref = vec![0i64; m + 1];
    pref[1] = 1;
    for i in 1..m {
        pref[i + 1] = pref[i] + a.partition_point(|&v| v >= i) as i64;
    }
    for b in queries {
        println!("{}", if b <= m { pref[b] } else { -1 });
    }
}
