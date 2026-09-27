use proconio::input;
fn main() {
    input! {n:usize,m:usize,e:[(usize,usize);m]}
    let mut answer = m;
    for mask in 0..(1usize << (n - 1)) {
        let cut = e
            .iter()
            .filter(|&&(u, v)| ((mask >> (u - 1)) & 1) != ((mask >> (v - 1)) & 1))
            .count();
        answer = answer.min(cut);
    }
    println!("{answer}");
}
