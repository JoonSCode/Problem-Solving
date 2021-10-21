//
//  LeetCode Palindrome Number.swift
//  Problem-Solving
//
//  Created by eden.joon on 2021/10/19.
//

import Foundation

class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        guard x >= 0 else { return false }
        return String(x) == String(String(x).reversed())
    }
}
