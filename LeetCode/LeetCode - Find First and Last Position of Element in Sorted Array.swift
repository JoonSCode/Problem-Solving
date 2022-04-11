//
//  LeetCode - Find First and Last Position of Element in Sorted Array.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/01/03.
//

import Foundation

class Solution {
    
    // Time: O(n) - 125ms
    // Space: O(n)
//        func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
//            var answer:[Int] = []
//            var nums = nums
//            var target = target
//
//            let firstFindNumber = binarySearch(&nums, startIndex: 0, endIndex: nums.endIndex - 1, target: &target)
//            guard firstFindNumber != -1 else {
//                return [-1,-1]
//            }
//
//            var low = firstFindNumber
//            var high = firstFindNumber
//
//            while low >= 0, nums[low] == target {
//                low -= 1
//            }
//            answer.append(low + 1)
//
//            while high < nums.endIndex, nums[high] == target {
//                high += 1
//            }
//            answer.append(high - 1)
//            return answer
//        }
//
//        func binarySearch( _ nums: inout [Int], startIndex: Int, endIndex: Int, target: inout Int) -> Int {
//
//            if startIndex > endIndex {
//                return -1
//            }
//
//            let midIndex = (startIndex + endIndex) / 2
//
//            if nums[midIndex] > target {
//                return binarySearch(&nums, startIndex: startIndex, endIndex: midIndex - 1, target: &target)
//            } else if nums[midIndex] < target {
//                return binarySearch(&nums, startIndex: midIndex + 1, endIndex: endIndex, target: &target)
//            }
//            return midIndex
//        }
    
    //Time: O(log(n)) - 48ms
    //Space: O(n)
    
    func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        var nums = nums
        var target = target
        
        guard !nums.isEmpty else {
            return [-1,-1]
        }
        
        let low = binarySearchWithDuplicates(&nums, startIndex: 0, endIndex: nums.endIndex - 1, target: &target, forSmallest: true)

        let high = binarySearchWithDuplicates(&nums, startIndex: 0, endIndex: nums.endIndex - 1, target: &target, forSmallest: false)
        
        return [low, high]
    }
    
    func binarySearchWithDuplicates( _ nums: inout [Int], startIndex: Int, endIndex: Int, target: inout Int, forSmallest: Bool) -> Int {
        
        if endIndex - startIndex < 2 {
            let firstNum = nums[startIndex]
            let secondNum = nums[endIndex]
            
            if firstNum == target, secondNum == target {
                return forSmallest ? startIndex : endIndex
            }else if firstNum == target {
                return startIndex
            }else if secondNum == target {
                return endIndex
            }else {
                return -1
            }
        }
        
        let midIndex = (startIndex + endIndex) / 2
        
        if nums[midIndex] > target {
            return binarySearchWithDuplicates(&nums, startIndex: startIndex, endIndex: midIndex - 1, target: &target, forSmallest: forSmallest)
        } else if  nums[midIndex] < target {
            return binarySearchWithDuplicates(&nums, startIndex: midIndex + 1, endIndex: endIndex, target: &target, forSmallest: forSmallest)
        } else {
            if forSmallest {
                return binarySearchWithDuplicates(&nums, startIndex: startIndex, endIndex: midIndex, target: &target, forSmallest: forSmallest)
            }
            return binarySearchWithDuplicates(&nums, startIndex: midIndex, endIndex: endIndex, target: &target, forSmallest: forSmallest)
        }
    }
}
