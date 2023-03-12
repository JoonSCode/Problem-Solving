//
//  Longest Common Prefix.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/12.
//

import Foundation

class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        let charArrays = strs.map({
            Array($0)
        })
        var answer = charArrays[0]
        var isSuccess = true
        repeat {
            isSuccess = true
            for charArray in charArrays {
                guard charArray.starts(with: answer)
                else {
                    answer.removeLast()
                    isSuccess = false
                    break
                }
            }
        }
        while !isSuccess && !answer.isEmpty

        return String(answer)
    }
}
