//
//  Same Tree.swift
//  Problem-Solving
//
//  Created by eden on 2023/10/03.
//

import Foundation

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() {
        self.val = 0;
        self.left = nil;
        self.right = nil;
    }
    public init(_ val: Int) {
        self.val = val;
        self.left = nil;
        self.right = nil;
    }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
}
 
class Solution {
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        return p == q
    }
}

extension TreeNode: Equatable {
    public static func == (lhs: TreeNode, rhs: TreeNode) -> Bool {
        return (lhs.val == rhs.val && lhs.left == rhs.left && lhs.right == rhs.right)
    }
}
