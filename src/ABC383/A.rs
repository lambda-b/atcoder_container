use proconio::input;
fn main() {
    input! { n: usize, events: [(i64, i64); n] }
    let (mut volume, mut previous) = (0i64, 0i64);
    for (time, added) in events {
        volume = (volume - (time - previous)).max(0) + added;
        previous = time;
    }
    println!("{volume}");
}
