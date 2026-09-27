use proconio::input;
fn main() {
    input! { x: String, y: String }
    let rank = |s: &str| match s {
        "Ocelot" => 0,
        "Serval" => 1,
        _ => 2,
    };
    println!("{}", if rank(&x) >= rank(&y) { "Yes" } else { "No" });
}
