//
//  Jump Game.swift
//  Problem-Solving
//
//  Created by eden on 2023/09/29.
//

import Foundation

class Solution {
    func canJump(_ nums: [Int]) -> Bool {
        var maxJump = 0
        for (i, num) in nums.enumerated() {
            guard i <= maxJump else { return false }
            maxJump = max(maxJump, i + num)
        }
        
        return maxJump >= nums.count - 1
    }
}
