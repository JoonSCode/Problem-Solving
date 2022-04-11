//
//  LeetCode - Container With Most Water.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2021/12/13.
//

import Foundation

class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var maxAreaForNow: Int = 0
        
        var left = 0
        var right = height.count - 1
        while left < right {
            let distance = right - left
            let heightOfLine = min(height[left], height[right])
            
            maxAreaForNow = max(maxAreaForNow, distance * heightOfLine)
            
            if height[left] < height[right] {
                left += 1
            } else {
                right -= 1
            }
        }
        return maxAreaForNow
    }
}
