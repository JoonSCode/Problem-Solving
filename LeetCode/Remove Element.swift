//
//  Remove Element.swift
//  Problem-Solving
//
//  Created by eden on 2023/05/06.
//

import Foundation

class Solution {
    // basic implementation
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
        nums = nums.filter({
            $0 != val
        })
        
        return nums.count
    }
}
