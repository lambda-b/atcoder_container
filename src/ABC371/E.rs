use proconio::input;
fn main() {
    input! {n:usize,a:[usize;n]}
    let mut seen = vec![Vec::new(); n];
    for (i, &x) in a.iter().enumerate() {
        seen[x - 1].push(i);
    }
    let mut running = 0i64;
    let mut answer = 0i64;
    for i in 0..n {
        running += (i + 1) as i64;
        if let Some(&prev) = seen[a[i] - 1].iter().rev().find(|&&p| p < i) {
            running -= (prev + 1) as i64;
        }
        answer += running;
    }
    println!("{answer}");
}
