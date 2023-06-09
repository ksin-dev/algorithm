struct Solution {}

impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let mut col = 0;
        let mut row = grid[0].len();

        let mut count: usize = 0;
        while row > 0 {
            while col < grid.len() && grid[col][row - 1] >= 0 {
                col += 1;
            }

            println!("{} {}", col, row);
            if col == grid.len() {
                return count as i32;
            }

            count += (grid.len() - col);
            row -= 1;
        }

        return count as i32;
    }
}

#[test]
fn case1() {
    let solution = Solution::count_negatives(vec![
        vec![4, 3, 2, -1],
        vec![3, 2, 1, -1],
        vec![1, 1, -1, -2],
        vec![-1, -1, -2, -3],
    ]);
    assert_eq!(8, solution);
}

#[test]
fn case2() {
    let solution = Solution::count_negatives(vec![vec![3, 2], vec![1, 0]]);
    assert_eq!(0, solution);
}

#[test]
fn case3() {
    let solution = Solution::count_negatives(vec![vec![3, 2], vec![1, 0], vec![-1, -1]]);
    assert_eq!(2, solution);
}

#[test]
fn case4() {
    let solution =
        Solution::count_negatives(vec![vec![3, -1, -1], vec![2, -1, -1], vec![-1, -1, -1]]);
    assert_eq!(7, solution);
}
