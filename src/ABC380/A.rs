use proconio::input;
fn main() {
    input! { s: String }
    let yes = ['1', '2', '3']
        .into_iter()
        .enumerate()
        .all(|(i, c)| s.chars().filter(|&x| x == c).count() == i + 1);
    println!("{}", if yes { "Yes" } else { "No" });
}
