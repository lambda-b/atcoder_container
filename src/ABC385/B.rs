use proconio::input;
fn main() {
    input! { h: usize, w: usize, mut x: usize, mut y: usize, grid: [String; h], moves: String }
    x -= 1;
    y -= 1;
    let mut visited = std::collections::HashSet::new();
    for d in moves.chars() {
        let (nx, ny) = match d {
            'U' => (x.wrapping_sub(1), y),
            'D' => (x + 1, y),
            'L' => (x, y.wrapping_sub(1)),
            _ => (x, y + 1),
        };
        if nx < h && ny < w && grid[nx].as_bytes()[ny] != b'#' {
            x = nx;
            y = ny;
            if grid[x].as_bytes()[y] == b'@' {
                visited.insert((x, y));
            }
        }
    }
    println!("{} {} {}", x + 1, y + 1, visited.len());
}
