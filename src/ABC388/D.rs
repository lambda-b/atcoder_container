use proconio::input;
fn main() {
    input! {n:usize,a:[i64;n]}
    let mut events = vec![0i64; n];
    let mut pending = 0i64;
    let mut ans = Vec::new();
    for i in 0..n {
        let given = pending;
        pending -= events[i];
        let have = given + a[i];
        let take = have.min((n - 1 - i) as i64);
        let at = i + take as usize;
        if at > i {
            events[at] += 1;
            pending += 1;
        }
        ans.push((have - take).to_string());
    }
    println!("{}", ans.join(" "));
}
