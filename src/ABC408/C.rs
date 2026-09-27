use proconio::input;
fn main() {
    input! {n:usize,m:usize,lr:[(usize,usize);m]}
    let mut diff = vec![0i64; n + 1];
    for (l, r) in lr {
        diff[l - 1] += 1;
        diff[r] -= 1;
    }
    let mut active = 0;
    let mut answer = i64::MAX;
    for x in diff.iter().take(n) {
        active += x;
        answer = answer.min(active);
    }
    println!("{answer}");
}
