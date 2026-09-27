use proconio::input;
fn main() {
    input! { h: usize, w: usize }
    for i in 0..h {
        let vertical = if h == 1 {
            0
        } else if i == 0 || i + 1 == h {
            1
        } else {
            2
        };
        let row: Vec<_> = (0..w)
            .map(|j| {
                let horizontal = if w == 1 {
                    0
                } else if j == 0 || j + 1 == w {
                    1
                } else {
                    2
                };
                (vertical + horizontal).to_string()
            })
            .collect();
        println!("{}", row.join(" "));
    }
}
