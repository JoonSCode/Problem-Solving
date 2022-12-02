//
//  Search Insert Position.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/12/02.
//

import Foundation

class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        var start = 0
        var end = nums.count - 1
        var mid = 0
        
        while start <= end {
            mid = (start + end) / 2

            if target > nums[mid] {
                start = mid + 1
            } else if target < nums[mid] {
                end = mid - 1
            } else {
                return mid
            }
        }
        return start
    }
}
