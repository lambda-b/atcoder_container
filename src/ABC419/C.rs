use proconio::input;
fn main() {
    input! {n:usize,p:[(i64,i64);n]}
    let (mut minx, mut maxx, mut miny, mut maxy) = (i64::MAX, i64::MIN, i64::MAX, i64::MIN);
    for (x, y) in p {
        minx = minx.min(x);
        maxx = maxx.max(x);
        miny = miny.min(y);
        maxy = maxy.max(y);
    }
    println!("{}", ((maxx - minx + 1) / 2).max((maxy - miny + 1) / 2));
}
