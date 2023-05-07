//
//  Remove Duplicates from Sorted Array.swift
//  Problem-Solving
//
//  Created by eden on 2023/05/06.
//

import Foundation

class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        let inValidNum = -101
        
        for index in (0..<nums.count) {
            let num = nums[index]
            guard num != inValidNum else { continue }
            
            var newIndex = index + 1
            while newIndex < nums.count && nums[newIndex] == num {
                nums[newIndex] = inValidNum
                newIndex += 1
            }
        }
        
        var index = 0
        
        while index < nums.count {
            guard nums[index] == inValidNum
            else {
                index += 1
                continue
            }
            nums.remove(at: index)
        }
        
        return nums.count
    }
}
