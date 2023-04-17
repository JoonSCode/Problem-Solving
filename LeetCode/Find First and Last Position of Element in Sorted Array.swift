//
//  Find First and Last Position of Element in Sorted Array.swift
//  Problem-Solving
//
//  Created by eden on 2023/04/11.
//

import Foundation

class Solution {
    var nums: [Int] = []
    
    func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        self.nums = nums
        guard !nums.isEmpty else { return [-1,-1] }
        
        let min = minBinarySearch(start: 0, end: nums.count - 1, target: target)
        let max = maxBinarySearch(start: 0, end: nums.count - 1, target: target)
        
        return [min, max]
    }
    
    func minBinarySearch(start: Int, end: Int, target: Int) -> Int {
        var start = start
        var end = end
        var mid = (start + end) / 2
        while start < end {
            mid = (start + end) / 2

            if nums[mid] == target {
                end = mid
            } else if nums[mid] < target {
                start = mid + 1
            } else {
                end = mid - 1
            }
        }
        mid = (start + end) / 2
        
        return nums[mid] == target ? mid : -1
    }
    
    func maxBinarySearch(start: Int, end: Int, target: Int) -> Int {
        var start = start
        var end = end
        var mid = (start + end) / 2
        
        while start < end {
            mid = (start + end) / 2
            guard start != mid
            else {
                if nums[end] == target {
                    start = end
                }
                break
            }
            
            if nums[mid] == target {
                start = mid
            } else if nums[mid] < target {
                start = mid + 1
            } else {
                end = mid - 1
            }

        }
        mid = (start + end) / 2
        
        return nums[mid] == target ? mid : -1
    }
}
