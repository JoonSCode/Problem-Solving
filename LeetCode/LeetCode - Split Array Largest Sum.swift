//
//  LeetCode - Split Array Largest Sum.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/03/31.
//

import Foundation

class Solution {
    func splitArray(_ nums: [Int], _ m: Int) -> Int {
        var minSum = 0
        var maxSum = 0
        
        for num in nums {
            minSum = max(minSum, num)
            maxSum += num
        }
        
        var answer = 0
        while minSum <= maxSum {
            let mid = (maxSum + minSum) / 2
            if isPossible(sum: mid, nums: nums, m: m) {
                answer = mid
                maxSum = mid - 1
            } else {
                minSum = mid + 1
            }
        }
        return answer
    }
    
    private func isPossible(sum: Int, nums: [Int], m: Int) -> Bool {
        var subArrayCount = 1
        var currentSum = 0
        for num in nums {
            currentSum += num
            if currentSum > sum {
                currentSum = num
                subArrayCount += 1
            }
        }
        return subArrayCount <= m
    }
}
