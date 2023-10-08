//
//  Binary Tree Zigzag Level Order Traversal.swift
//  Problem-Solving
//
//  Created by eden on 2023/10/08.
//

import Foundation

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func zigzagLevelOrder(_ root: TreeNode?) -> [[Int]] {
        guard let root = root else { return [] }

        var answer: [[Int]] = []
        var queue: [TreeNode] = [root]
        
        while !queue.isEmpty {
            var newQueue: [TreeNode] = []
            var values: [Int] = []
            for item in queue {
                values.append(item.val)
                
                if let leftChild = item.left {
                    newQueue.append(leftChild)
                }
                if let rightChild = item.right {
                    newQueue.append(rightChild)
                }
            }
            if answer.count % 2 != 0 {
                values.reverse()
            }
            answer.append(values)
            queue = newQueue
        }
        
        return answer
    }
}
