//
//  Binary Search.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/12/02.
//

import Foundation

class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        var first = 0
        var last = nums.count - 1
        
        while first <= last {
            let mid = (first + last) / 2
            
            if nums[mid] == target {
                return mid
            } else if nums[mid] > target {
                last = mid - 1
            } else {
                first = mid + 1
            }
        }
        return -1
    }
}
