//
//  Move Zeroes.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/13.
//

import Foundation

class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var lastIndexOfNonZero = -1
        
        for index in 0..<nums.count {
            let num = nums[index]
            
            if num == 0 {
                continue
            } else {
                lastIndexOfNonZero += 1
                nums[lastIndexOfNonZero] = num
            }
        }
        
        for index in (lastIndexOfNonZero + 1)..<nums.count {
            nums[index] = 0
        }
    }
}
