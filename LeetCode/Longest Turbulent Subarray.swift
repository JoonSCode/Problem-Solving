//
//  Longest Turbulent Subarray.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/12/04.
//

import Foundation

class Solution {
    func maxTurbulenceSize(_ arr: [Int]) -> Int {
        var maxSize = 1

        var increase = 1
        var decrease = 1

        for i in 0..<arr.count - 1 {
            if arr[i] < arr[i+1] {
                increase = decrease + 1
                decrease = 1
            } else if arr[i] > arr[i+1] {
                decrease = increase + 1
                increase = 1
            } else {
                increase = 1
                decrease = 1
            }
            maxSize = max(maxSize, increase, decrease)
        }

        return maxSize
    }
}
