use std::vec;
use std::collections::HashMap;
struct Solution {}

fn word_compare(a:&char,b:&char) -> std::cmp::Ordering { b.cmp(a) }
// fn set_map(m:&mut HashMap<char,i32>,c:&'static char) -> HashMap<char,i32> {
//     m.insert(*c,match m.get(c) {
//         Some(x) => x+1,
//         None => 1
//     });

//     return m;
// }

impl Solution {
    pub fn close_strings(word1: String, word2: String) -> bool {
        if word1.len() != word2.len() { return false; }

        let mut word1: Vec<char> = word1[..].to_owned().chars().collect();
        word1.sort_by(word_compare);
        let mut word2: Vec<char> = word2[..].to_owned().chars().collect();
        word2.sort_by(word_compare);

        // let map1 = word1.iter().fold(HashMap::new(), set_map);
        // let map2 = word2.iter().fold(HashMap::new(), set_map);

        // map1.keys().eq(map2.keys());

        return true;
    }
}


#[test]
fn case1() 
{
    assert_eq!(Solution::close_strings(String::from("abc"),String::from("bca")),true);
}

#[test]
fn case2()
{
    assert_eq!(Solution::close_strings(String::from("a"),String::from("aa")),false);
}

#[test]
fn case3()
{
    assert_eq!(Solution::close_strings(String::from("aaabbbccc"),String::from("cbabcbaca")),true);
}

#[test]
fn case4()
{
    let mut m1 = HashMap::from([
        ('a',1),
        ('b',2),
        ('c',3)
    ]);

    let mut m2 = HashMap::from([
        ('a',2),
        ('b',3),
        ('c',4)
    ]);

    println!("{:?} {:?}",m1.keys().collect::<Vec<char>>().sort(),m2.keys().collect::<Vec<char>>().sort());
    assert_eq!(m1.keys().eq(m2.keys()),true);
}