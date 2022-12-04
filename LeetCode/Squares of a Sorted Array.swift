//
//  Squares of a Sorted Array.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/12/04.
//

import Foundation

class Solution {
    func sortedSquares(_ nums: [Int]) -> [Int] {
        var left = 0
        var right = nums.count - 1
        var answer = [Int].init(repeating: 0, count: nums.count)

        for i in stride(from: nums.count - 1, to: -1, by: -1) {
            let start = abs(nums[left])
            let end = abs(nums[right])
            if start <= end {
                answer[i] = end * end
                right -= 1
            } else {
                answer[i] = start * start
                left += 1
            }
        }
        return answer
    }
}
