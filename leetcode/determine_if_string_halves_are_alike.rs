
static VOWELS: [char; 5] = ['a', 'e', 'i', 'o', 'u'];

struct Solution{}
impl Solution {
    pub fn count_vowels(s: &str) -> i32 {
        let mut count = 0;
        for (i,item) in s.chars().enumerate() {
            if VOWELS.contains(&item.to_lowercase().next().unwrap()) {
                count += 1;
            }
        }
        count
    }

    pub fn halves_are_alike(s: String) -> bool {
        let len = s.len();
        return Solution::count_vowels(&s[0..(len/2)]) == Solution::count_vowels(&s[(len/2)..]);
    }
}

#[test]
fn case1() {
    let solution = Solution::halves_are_alike(String::from("book"));
    assert_eq!(true,solution);
}

#[test]
fn case2() {
    let solution = Solution::halves_are_alike(String::from("textbook"));

    assert_eq!(false,solution);
}


fn main(){

}

