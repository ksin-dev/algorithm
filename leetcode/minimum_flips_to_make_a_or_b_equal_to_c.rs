struct Solution {}

impl Solution {
    pub fn min_flips(a: i32, b: i32, c: i32) -> i32 {
        let mut c = c;
        let mut a = a;
        let mut b = b;

        let mut count = 0;
        while a > 0 || b > 0 || c > 0 {
            let c_mod = c & 1;
            let a_mod = a & 1;
            let b_mod = b & 1;

            c = c >> 1;
            a = a >> 1;
            b = b >> 1;

            if c_mod == 0 && a_mod == 1 && b_mod == 1 {
                count += 2;
            } else {
                count += (b_mod | a_mod) ^ c_mod;
            }
        }

        count
    }
}

#[test]
fn case1() {
    let res = Solution::min_flips(2, 6, 5);
    assert_eq!(3, res);
}

#[test]
fn case2() {
    let res = Solution::min_flips(4, 2, 7);
    assert_eq!(1, res);
}

#[test]
fn case3() {
    let res = Solution::min_flips(1, 2, 3);
    assert_eq!(0, res);
}

#[test]
fn case4() {
    let res = Solution::min_flips(1, 2, 7);
    assert_eq!(1, res);
}

#[test]
fn case5() {
    let res = Solution::min_flips(1, 1, 1);
    assert_eq!(0, res);
}

#[test]
fn case6() {
    let res = Solution::min_flips(9, 1, 1);
    assert_eq!(1, res);
}
