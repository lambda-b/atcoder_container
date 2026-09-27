use proconio::input;
fn main() {
    input! { r: i32, x: i32 }
    let yes = if x == 1 {
        (1600..3000).contains(&r)
    } else {
        (1200..2400).contains(&r)
    };
    println!("{}", if yes { "Yes" } else { "No" });
}
