use proconio::input;
fn main() {
    input! { a: [usize; 7] }
    let mut c = [0; 13];
    for x in a {
        c[x - 1] += 1;
    }
    let triples = c.iter().filter(|&&x| x >= 3).count();
    let pairs = c.iter().filter(|&&x| x >= 2).count();
    println!(
        "{}",
        if triples >= 1 && pairs >= 2 {
            "Yes"
        } else {
            "No"
        }
    );
}
