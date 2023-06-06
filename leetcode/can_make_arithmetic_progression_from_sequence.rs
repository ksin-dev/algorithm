use std::vec::Vec;
struct Solution {}

impl Solution {
    pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool {
        let mut sorted_arr = arr.clone();
        sorted_arr.sort();

        let gap: i32 = ((sorted_arr[1] - sorted_arr[0]) as i32).abs();
        let mut prev = sorted_arr[1];
        let sorted_arr = &sorted_arr[2..];
        let sorted_arr: Vec<i32> = Vec::from(sorted_arr);

        for next in sorted_arr.iter() {
            if gap != ((next - prev) as i32).abs() {
                return false;
            }
            prev = *next;
        }

        true
    }
}

#[test]
fn case1() {
    let result = Solution::can_make_arithmetic_progression(vec![1, 3, 5]);

    assert_eq!(true, result);
}

#[test]
fn case2() {
    let result = Solution::can_make_arithmetic_progression(vec![1, 2, 5]);

    assert_eq!(false, result);
}

#[test]
fn case3() {
    let result = Solution::can_make_arithmetic_progression(vec![3, 5, 1]);

    assert_eq!(true, result);
}

#[test]
fn case4() {
    let result = Solution::can_make_arithmetic_progression(vec![-68, -96, -12, -40, 16]);

    assert_eq!(true, result);
}
