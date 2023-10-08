//
//  Binary Tree Right Side View.swift
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
    func rightSideView(_ root: TreeNode?) -> [Int] {
        var answer: [Int] = []
        var queue: [TreeNode] = []
        if let root = root {
            queue.append(root)
        }
        
        while !queue.isEmpty {
            var newQueue: [TreeNode] = []
            
            for i in 0..<queue.count {
                let item = queue[i]
                if let leftChild = item.left {
                    newQueue.append(leftChild)
                }
                if let rightChild = item.right {
                    newQueue.append(rightChild)
                }
                
                if i == queue.count - 1 {
                    answer.append(item.val)
                }
            }
            
            queue = newQueue
        }
        
        return answer
    }
}
