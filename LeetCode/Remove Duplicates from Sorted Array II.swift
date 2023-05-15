//
//  Remove Duplicates from Sorted Array II.swift
//  Problem-Solving
//
//  Created by eden on 2023/05/15.
//

import Foundation

class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        var index = 0
        var duplicateNum = -1
        var duplicateCount = 0
        
        while index < nums.count {
            var num = nums[index]
            guard duplicateNum == num
            else {
                duplicateNum = num
                duplicateCount = 1
                index += 1
                continue
            }
            
            duplicateCount += 1
            
            if duplicateCount > 2 {
                nums.remove(at: index)
            } else {
                index += 1
            }
        }
        
        return nums.count
    }
}
