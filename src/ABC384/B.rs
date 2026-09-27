use proconio::input;
fn main() {
    input! { n: usize, mut rating: i64, events: [(i32, i64); n] }
    for (division, change) in events {
        if (division == 1 && (1600..2800).contains(&rating))
            || (division == 2 && (1200..2400).contains(&rating))
        {
            rating += change;
        }
    }
    println!("{rating}");
}
