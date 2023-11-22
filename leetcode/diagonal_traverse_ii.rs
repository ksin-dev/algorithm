
struct Solution {}


impl Solution {
  pub fn find_diagonal_order(nums: Vec<Vec<i32>>) -> Vec<i32> {
    let mut route: Vec<i32> = Vec::new();
    let mut y = 0;
    let mut x = 0;

    let max_x_len = nums.iter().fold(0 as usize, |acc,v| { acc.max(v.len())});

    while y < nums.len() && x < max_x_len {
      let mut moved_y: i64 = y as i64;
      let mut moved_x = x;
      while moved_y >= 0 {
        if moved_x < nums[moved_y as usize].len() {
          route.push(nums[moved_y as usize][moved_x]);
        }
        moved_x += 1;
        moved_y -= 1;
      } 

      if y < (nums.len()-1) {
        y=y+1;
      } else {
        x=x+1;
      }
    }
    route
  }

}


#[test]
fn case1() {
    let res = Solution::find_diagonal_order(vec![vec![1,2,3],vec![4,5,6],vec![7,8,9]]);

    let answer = vec![1,4,2,7,5,3,8,6,9];
    assert_eq!(answer, res);
}

#[test]
fn case2() {
    let res = Solution::find_diagonal_order(vec![vec![1,2,3,4,5],vec![6,7],vec![8],vec![9,10,11],vec![12,13,14,15,16]]);
    let answer = vec![1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16];
    assert_eq!(answer, res);

}



#[test]
fn case3() {
    let res = Solution::find_diagonal_order(vec![
      vec![14,12,19,16,9],
      vec![13,14,15,8,11],
      vec![11,13,1]
    ]);
    let answer = vec![14,13,12,11,14,19,13,15,16,1,8,9,11];
    assert_eq!(answer, res);

}