use std::cmp;
struct Solution {}

impl Solution {
    pub fn max_value(n: i32, index: i32, max_sum: i32) -> i32 {
        println!("start values: {} {} {}", n, index, max_sum);
        let left = index;
        let right = n - (index + 1);
        let mut val = max_sum;
        let mut max = cmp::max(n - index, index);
        let mut left_count = left;
        let mut right_count = right;
        let mut pivot = (max_sum / n) + cmp::max(left_count, right_count);
        let mut sum = max_sum;

        println!();
        println!("{} {} {}", left_count, right_count, pivot);
        println!("start_sum");
        while sum <= max_sum {
            pivot += 1;
            let left_sum = (1..left_count).map(|v| pivot - v).sum::<i32>();
            let right_sum = (1..right_count).map(|v| pivot - v).sum::<i32>();
            sum = left_sum + right_sum + pivot;
            println!("{} {} {} {}", left_sum, right_sum, sum, pivot);
        }

        return pivot;
    }

    pub fn sum(max_count: i32, max: i32) -> (i32, i32) {
        let mut max = max;
        let mut res: i32 = 0;
        let mut count = 1;
        println!("start");
        while count <= max_count && max > 0 {
            println!("{} {} ", max, count);
            res += max;
            max -= 1;
            count += 1;
        }
        return res;
    }
}

#[test]
fn case1() {
    let res = Solution::max_value(6, 0, 10);

    assert_eq!(res, 3);
}

#[test]
fn case2() {
    let res = Solution::max_value(4, 2, 6);

    assert_eq!(res, 2);
}

#[test]
fn case3() {
    let res = Solution::max_value(7, 5, 20);

    assert_eq!(res, 5);
}

#[test]
fn case4() {
    let res = Solution::max_value(8, 5, 14);

    assert_eq!(res, 4);
}

#[test]
fn case5() {
    let res = Solution::max_value(6, 4, 100);

    assert_eq!(res, 18);
}
