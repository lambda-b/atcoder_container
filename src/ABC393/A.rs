use proconio::input;
fn main() {
    input! { s1: String, s2: String }
    let answer = match (s1 == "sick", s2 == "sick") {
        (true, true) => 1,
        (true, false) => 2,
        (false, true) => 3,
        _ => 4,
    };
    println!("{answer}");
}
