#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn prune_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        Solution::tree(root.as_ref());
        return root;
    }

    pub fn tree(root: Option<&Rc<RefCell<TreeNode>>>) {
        if root.is_none() {
            return;
        }

        let node = root.as_ref().unwrap().borrow();

        if node.left.is_some() {
            let left = node.left.as_ref().unwrap().borrow();
            if left.val == 0 && node.val == 0 {
                let mut node = root.as_ref().unwrap().borrow_mut();
                node.left = None;
            } else {
                Solution::tree(root.as_ref().unwrap().borrow_mut().left.as_ref());
            }
        }

        if node.right.is_some() {
            let right = node.right.as_ref().unwrap().borrow();
            if right.val == 0 && node.val == 0 {
                let mut node = root.as_ref().unwrap().borrow_mut();
                node.right = None;
            } else {
                Solution::tree(root.as_ref().unwrap().borrow_mut().right.as_ref());
            }
        }
    }
}

struct Solution {}

fn main() {
    let root = TreeNode {
        val: 1,
        left: None,
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(1)))),
        }))),
    };

    let root = Solution::prune_tree(Some(Rc::new(RefCell::new(root))));
    print!("{:#?}", root);
}

#[test]
fn case1() {
    let root = TreeNode {
        val: 1,
        left: None,
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(1)))),
        }))),
    };

    Solution::prune_tree(Some(Rc::new(RefCell::new(root))));
}

#[test]
fn case2() {
    let root = TreeNode {
        val: 1,
        left: Some(Rc::new(RefCell::new(TreeNode {
            val: 0,
            left: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
        }))),
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(1)))),
        }))),
    };

    Solution::prune_tree(Some(Rc::new(RefCell::new(root))));
}

#[test]
fn case3() {
    let root = TreeNode {
        val: 1,
        left: Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 0,
                left: None,
                right: None,
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(1)))),
        }))),
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(1)))),
        }))),
    };

    Solution::prune_tree(Some(Rc::new(RefCell::new(root))));
}
