//
//  Longest Increasing Subsequence.swift
//  Problem-Solving
//
//  Created by eden on 2023/10/08.
//

import Foundation

class Solution {
    func lengthOfLIS(_ nums: [Int]) -> Int {
        var cache: [Int] = .init(repeating: 1, count: nums.count)
        
        for i in 0..<nums.count-1 {
            for j in i+1..<nums.count {
                guard nums[i] < nums[j] else { continue }
                cache[j] = max(cache[j], cache[i] + 1)
            }
        }

        return cache.max()!
    }
}
