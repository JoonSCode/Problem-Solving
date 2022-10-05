//
//  Add One Row to Tree.swift
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
        var nodesAtCurrentDepth: [TreeNode] = []
        
        guard depth != 1 else {
            return TreeNode(val, root, nil)
        }
        
        guard let root = root else {
            return nil
        }
        
        nodesAtCurrentDepth = [root]

        for _ in (2..<depth) {
            var tmpNodesAtCurrentDepth: [TreeNode] = []
            
            for node in nodesAtCurrentDepth {
                if let leftChild = node.left {
                    tmpNodesAtCurrentDepth.append(leftChild)
                }
                if let rightChild = node.right {
                    tmpNodesAtCurrentDepth.append(rightChild)
                }
            }
            
            nodesAtCurrentDepth = tmpNodesAtCurrentDepth
        }
        
        for node in nodesAtCurrentDepth {
            let newLeftChild = TreeNode(val, node.left, nil)
            let newRightChild = TreeNode(val, nil, node.right)
            
            node.left = newLeftChild
            node.right = newRightChild
        }
        
        return root
    }
}
