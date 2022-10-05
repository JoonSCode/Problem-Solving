//
//  Add One Row to Tree ver2.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/10/05.
//

import Foundation

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() { self.val = 0; self.left = nil; self.right = nil; }
    public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
}

class Solution {
    func addOneRow(_ root: TreeNode?, _ val: Int, _ depth: Int) -> TreeNode? {
        guard depth != 1 else {
            return TreeNode(val, root, nil)
        }
        
        insert(node: root, val: val, depth: depth - 1)
        
        return root
    }
    
    func insert(node: TreeNode?, val: Int, depth: Int) {
        guard let node = node else { return }
        if depth == 1 {
            let newLeftChild = TreeNode(val, node.left, nil)
            let newRightChild = TreeNode(val, nil, node.right)
            
            node.left = newLeftChild
            node.right = newRightChild
        } else {
            insert(node: node.left, val: val, depth: depth - 1)
            insert(node: node.right, val: val, depth: depth - 1)
        }
    }
}
