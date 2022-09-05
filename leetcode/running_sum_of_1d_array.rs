use std::vec;

struct Solution {}
impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let mut num = 0;
        nums.iter()
            .map(|x| {
                num += x;
                num
            })
            .collect()
    }
}

pub fn main() {
    let sol = Solution::running_sum(vec![2, 3]);

    print!("{:?}", sol);
}
