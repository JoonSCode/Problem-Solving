//
//  Permutations.swift
//  Problem-Solving
//
//  Created by eden on 2023/10/03.
//

import Foundation

class Solution {
    func permute(_ nums: [Int]) -> [[Int]] {
        var nums = nums.sorted()
        var answer: [[Int]] = [nums]
        while nextPermutation(&nums) {
            answer.append(nums)
        }
        
        return answer
    }
    
    func nextPermutation(_ nums: inout [Int]) -> Bool {
        var peak = nums.count - 1
        
        while 0 < peak && nums[peak - 1] >= nums[peak] {
            peak -= 1
        }
        guard peak != 0 else { return false } // doesnt have next permutation
        peak -= 1
        
        var valueToSwap = nums.count - 1
        while peak < valueToSwap, nums[peak] > nums[valueToSwap] {
            valueToSwap -= 1
        }
        nums.swapAt(peak, valueToSwap)
        peak += 1
        var last = nums.count - 1
        
        while peak < last {
            nums.swapAt(peak, last)
            peak += 1
            last -= 1
        }
        
        return true
    }
}
