//
//  LeetCode - 3Sum.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2021/12/16.
//

import Foundation

class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        let nums = nums.sorted()
        var answer:[[Int]] = []
        if nums.count < 3 { return answer }
        
        for i in 0..<nums.count - 2 {
            guard i == 0 || nums[i] != nums[i-1] else { continue }
            
            var low = i + 1
            var high = nums.count - 1
            let sum = -nums[i]
            
            while(low < high){
                let lowHighSum = nums[low] + nums[high]
                
                if  lowHighSum == sum {
                    answer.append([nums[i], nums[low], nums[high]])
                    while low < high, nums[low] == nums[low + 1] {
                        low += 1
                    }
                    
                    while low < high, nums[high] == nums[high - 1] {
                        high -= 1
                    }
                    low += 1
                    high -= 1
                } else if lowHighSum > sum {
                    high -= 1
                } else {
                    low += 1
                }
            }
        }
        return answer
    }
}
