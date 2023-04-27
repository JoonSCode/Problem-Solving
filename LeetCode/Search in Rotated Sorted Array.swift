//
//  Search in Rotated Sorted Array.swift
//  Problem-Solving
//
//  Created by eden on 2023/04/17.
//

import Foundation

class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        return binarySearch(nums, startIndex: 0, endIndex: nums.count - 1, target: target)
    }
    
    func binarySearch(_ nums: [Int], startIndex: Int, endIndex: Int, target: Int) -> Int {
        let midIndex = (startIndex + endIndex) / 2
        let start = nums[startIndex]
        let end = nums[endIndex]
        let mid = nums[midIndex]
        guard target != mid else { return midIndex }
        guard start != mid else { return end == target ? endIndex : -1 }
        
        let isRotated = start > end
        
        guard isRotated
        else {
            if target < mid {
                return binarySearch(nums, startIndex: startIndex, endIndex: midIndex - 1, target: target)
            }
            return binarySearch(nums, startIndex: midIndex + 1, endIndex: endIndex, target: target)
        }
        
        let isTargetIsSmallerThanPivot = start <= target
        let isMidIndexIsSmallerThanPivot = start <= mid
        
        if target < mid {
            if !isTargetIsSmallerThanPivot && isMidIndexIsSmallerThanPivot {
                return binarySearch(nums, startIndex: midIndex + 1, endIndex: endIndex, target: target)
            }
            return binarySearch(nums, startIndex: startIndex, endIndex: midIndex - 1, target: target)
        } else {
            if isTargetIsSmallerThanPivot && !isMidIndexIsSmallerThanPivot {
                return binarySearch(nums, startIndex: startIndex, endIndex: midIndex - 1, target: target)
            }
            return binarySearch(nums, startIndex: midIndex + 1, endIndex: endIndex, target: target)
        }
    }
}
