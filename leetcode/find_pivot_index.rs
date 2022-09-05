use std::vec;

struct Solution {}
impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let mut r_sum: i32 = nums.iter().sum();
        let mut l_sum: i32 = 0;
        for i in 0..nums.len() {
            r_sum -= nums[i];
            l_sum = if i != 0 { l_sum + nums[i - 1] } else { l_sum };
            if l_sum == r_sum {
                return (i as i32);
            }
        }
        -1
    }
}

#[test]
fn case1() {
    let res = Solution::pivot_index(vec![1, 7, 3, 6, 5, 6]);
    assert_eq!(3, res);
}

#[test]
fn case2() {
    let res = Solution::pivot_index(vec![1, 2, 3]);
    assert_eq!(-1, res);
}

#[test]
fn case3() {
    let res = Solution::pivot_index(vec![2, 1, -1]);
    assert_eq!(0, res);
}
