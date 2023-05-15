//
//  Majority Element.swift
//  Problem-Solving
//
//  Created by eden on 2023/05/15.
//

import Foundation

class Solution {
    
    /*Time: O(nlogN) 103 ms, Space: O(N) 15.7 MB
    func majorityElement(_ nums: [Int]) -> Int {
        var nums = nums.sorted(by: <)
        return nums[nums.count/2]
    }
    */
    
    /*Time: O(n) 103 ms, Space: O(n), 15.7 MB
    func majorityElement(_ nums: [Int]) -> Int {
        var dict: [Int: Int] = [:]
        var majorCount = 0
        var majorNum = Int.max
        
        for num in nums {
            dict[num, default: 0] += 1
            if let count = dict[num], majorCount < count {
                majorCount = count
                majorNum = num
            }
        }
        
        return majorNum
    }
    */
    
    /*Time: O(n) 106 ms, Space: O(n), 15.9 MB
    func majorityElement(_ nums: [Int]) -> Int {
        var dict: [Int: Int] = [:]
        
        for num in nums {
            dict[num, default: 0] += 1
            if let count = dict[num], count > nums.count / 2 {
                return num
            }
        }
        
        return -1
    }
     */
    
    //Time: O(n) 103 ms, Space: O(1), 15.7 MB
    func majorityElement(_ nums: [Int]) -> Int {
        var now = 0
        var count = 0
        
        for num in nums {
            if count == 0 {
                now = num
                count = 1
            } else {
                count += (now == num ? 1: -1)
            }
        }
        
        return now
    }
}
