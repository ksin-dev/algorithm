struct Solution {}

impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        return match letters.iter().find(|&&x| x > target) {
            Some(&v) => v,
            None => letters[0],
        };
    }
}

#[test]
fn case1() {
    let solution = Solution::next_greatest_letter(vec!['c', 'f', 'j'], 'a');

    assert_eq!(solution, 'c');
}

#[test]
fn case2() {
    let solution = Solution::next_greatest_letter(vec!['c', 'f', 'j'], 'c');

    assert_eq!(solution, 'f');
}

#[test]
fn case3() {
    let solution = Solution::next_greatest_letter(vec!['x', 'x', 'y', 'y'], 'z');

    assert_eq!(solution, 'x');
}
