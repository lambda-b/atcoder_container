use proconio::input;
fn main() {
    input! { n: usize, m: usize, s: [String; n], t: [String; m] }
    for i in 0..=n - m {
        for j in 0..=n - m {
            if (0..m).all(|di| s[i + di][j..j + m] == t[di]) {
                println!("{} {}", i + 1, j + 1);
                return;
            }
        }
    }
}
