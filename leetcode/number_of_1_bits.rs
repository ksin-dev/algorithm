

struct Solution {}


impl Solution {
  pub fn hammingWeight (n: u32) -> i32 {
    let mut n = n;

    let cnt = (0..32).fold(0, |cnt,_| {
      let cnt = cnt + (n & 1);
      n = n >> 1;
      return cnt;
    });
    
    return cnt as i32;
  }
}


#[test]
fn case1() {
    let res = Solution::hammingWeight(0b00000000000000000000000000001011);

    assert_eq!(res, 3);
}

#[test]
fn case2() {
    let res = Solution::hammingWeight(0b00000000000000000000000010000000);

    assert_eq!(res, 1);
}

#[test]
fn case3() {
    let res = Solution::hammingWeight(0b11111111111111111111111111111101);

    assert_eq!(res, 31);
}