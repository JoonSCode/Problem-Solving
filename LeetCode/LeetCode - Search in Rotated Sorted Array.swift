//
//  LeetCode - Search in Rotated Sorted Array.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2021/12/30.
//

import Foundation

class Solution {
    //Problem: Find pivot -> sort -> binary search
    func search(_ nums: [Int], _ target: Int) -> Int {
        var pivot = getPivot(nums, startIndex: 0, endIndex: nums.endIndex - 1, firstNumber: nums[0])
        var nums = nums
        let originNumsCount = nums.count
        var answer = -1
        if pivot == nums.count {
            pivot = 0
        }
        nums.append(contentsOf: nums[0..<pivot])
        answer = binarySearch(nums, startIndex: pivot, endIndex: nums.endIndex - 1, target: target)
     
        return answer >= originNumsCount ? answer - originNumsCount : answer
    }
    
    func getPivot(_ nums: [Int], startIndex: Int, endIndex: Int, firstNumber: Int) -> Int {
        let firstIndex = (startIndex * 2 + endIndex) / 3
        let secondIndex = (startIndex + endIndex * 2) / 3
        
        guard endIndex - startIndex > 3 else {
            for index in startIndex ..< endIndex {
                if nums[index] > nums[index + 1] {
                    return index + 1
                }
            }
            return endIndex + 1
        }
        
        if nums[firstIndex] > nums[secondIndex] {
            return getPivot(nums, startIndex: firstIndex, endIndex: secondIndex, firstNumber: firstNumber)
        }
        else if firstIndex == secondIndex {
            return firstIndex
        }
        else {
            if nums[firstIndex] < firstNumber {
                return getPivot(nums, startIndex: startIndex, endIndex: firstIndex, firstNumber: firstNumber)
            } else {
                return getPivot(nums, startIndex: secondIndex, endIndex: endIndex, firstNumber: firstNumber)
            }
        }
    }
    
    func binarySearch(_ nums: [Int], startIndex: Int, endIndex: Int, target: Int) -> Int {
        guard startIndex <= endIndex else { return -1 }
        if startIndex == endIndex {
            return nums[startIndex] == target ? startIndex : -1
        }
        if startIndex + 1 == endIndex {
            if nums[startIndex] == target {
                return startIndex
            } else if nums[endIndex] == target {
                return endIndex
            }
            return -1
        }
        
        let midIndex = (startIndex + endIndex) / 2
        if nums[midIndex] == target {
            return midIndex
        }
        
        if nums[midIndex] > target {
            return binarySearch(nums, startIndex: startIndex, endIndex: midIndex, target: target)
        } else {
            return  binarySearch(nums, startIndex: midIndex, endIndex: endIndex, target: target)
        }
    }
}
