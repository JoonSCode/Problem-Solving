//
//  Average of Levels in Binary Tree.swift
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
    func averageOfLevels(_ root: TreeNode?) -> [Double] {
        var answer: [Double] = []
        var queue: [TreeNode] = []
        
        if let root = root {
            queue.append(root)
        }
        
        while !queue.isEmpty {
            var newQueue: [TreeNode] = []
            var sum: Double = 0
            var count: Double = Double(queue.count)
            
            for item in queue {
                sum += Double(item.val)
                
                if let leftChild = item.left {
                    newQueue.append(leftChild)
                }
                if let rightChild = item.right {
                    newQueue.append(rightChild)
                }
            }
            
            answer.append(sum / count)
            queue = newQueue
        }
        
        return answer
    }
}
