//
//  Longest Substring Without Repeating Characters.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/23.
//

import Foundation

class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var chars = Array(s)
        var charSet = Set<Character>()
        var startIndex = 0
        var maxCount = 0
        
        for (index, char) in chars.enumerated() {
            while charSet.contains(char) && startIndex <= index {
                charSet.remove(chars[startIndex])
                startIndex += 1
            }
            charSet.insert(char)
            maxCount = max(charSet.count, maxCount)
        }
        
        return maxCount
    }
}
