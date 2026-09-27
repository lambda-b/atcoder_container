use proconio::input;
fn main() {
    input! {h:usize,w:usize,a:[[i64;w];h],p:[i64;h+w-1]}
    let mut dp = vec![vec![0i64; w]; h];
    for i in (0..h).rev() {
        for j in (0..w).rev() {
            if i == h - 1 && j == w - 1 {
                continue;
            }
            let next = if i + 1 < h && j + 1 < w {
                dp[i + 1][j].min(dp[i][j + 1])
            } else if i + 1 < h {
                dp[i + 1][j]
            } else {
                dp[i][j + 1]
            };
            dp[i][j] = (next - (a[i][j] - p[i + j])).max(0);
        }
    }
    println!("{}", dp[0][0]);
}
