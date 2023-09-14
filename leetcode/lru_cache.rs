
use std::{collections::VecDeque, cmp::Ordering, f32::consts::E};

#[derive(Debug)]
struct LRUCache {
  bucket: VecDeque<State>,
  capacity: usize
}

#[derive(Copy, Clone, Eq, PartialEq,Debug)]
struct State {
  key: i32,
  value: i32
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {

    fn new(capacity: i32) -> Self {
      let capacity = capacity as usize;
      return Self { bucket: VecDeque::with_capacity(capacity),capacity }
    }
    
    fn get(&mut self, key: i32) -> i32 {
      match self.bucket.iter().position(|x| { x.key == key}) {
        Some(v) => {
          let result = *self.bucket.get(v).unwrap();

          self.bucket.remove(v);
          self.bucket.push_front(result);

          result.value
        },
        None => -1
      }
    }
    
    fn put(&mut self, key: i32, value: i32) {
        
        match self.bucket.iter().position(|x| { x.key == key }) {
          None => {
            if self.bucket.len() == self.capacity {
              self.bucket.pop_back();
            }
            
            self.bucket.push_front(State { key, value });

          },
          Some(idx) => {
            if let Some(s) = self.bucket.get(idx) {
              let mut s = s.clone();
              s.value = value;
              self.bucket.remove(idx);
              self.bucket.push_front(s);

            }
          }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */