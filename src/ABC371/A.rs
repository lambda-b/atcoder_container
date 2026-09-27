use proconio::input;
fn main() {
    input! { ab: char, ac: char, bc: char }
    let a_lt_b = ab == '<';
    let a_lt_c = ac == '<';
    let b_lt_c = bc == '<';
    let answer = if a_lt_b == a_lt_c {
        "A"
    } else if a_lt_b == b_lt_c {
        "B"
    } else {
        "C"
    };
    println!("{answer}");
}
