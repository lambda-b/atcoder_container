use proconio::input;
use std::collections::HashSet;
fn main() {
    input! { board: [String; 8] }
    let mut rows = HashSet::new();
    let mut cols = HashSet::new();
    for (i, row) in board.iter().enumerate() {
        for (j, cell) in row.bytes().enumerate() {
            if cell == b'#' {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    println!("{}", (8 - rows.len()) * (8 - cols.len()));
}
