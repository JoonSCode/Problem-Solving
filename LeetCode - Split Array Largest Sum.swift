//
//  LeetCode - Split Array Largest Sum.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/03/31.
//

import Foundation

class Solution {
    var cache: [[Int]] = []
    var summedNum: [Int] = []
    func splitArray(_ nums: [Int], _ m: Int) -> Int {
        cache = Array(repeating: Array(repeating: -1, count: m), count: nums.count)
        _ = nums.reduce(0) {
            summedNum.append($0 + $1)
            return $0 + $1
        }
        
        return dp(y: nums.count-1, x: m-1)
    }
    
    private func dp(y: Int, x: Int) -> Int {
        if cache[y][x] != -1 {
            return cache[y][x]
        }
        if x == 0 {
            cache[y][x] = summedNum[y]
            return cache[y][x]
        }
        
        var answer = Int.max
        for i in (x-1 ... y-1).reversed() {
            let sum = sumArray(start: i + 1, end: y)
            let dpAnswer = dp(y: i, x: x-1)
            let tmpAnswer = max(sum, dpAnswer)
            answer = min(answer,tmpAnswer)
            if tmpAnswer == sum {
                break
            }
        }
        cache[y][x] = answer
        return answer
    }
    
    private func sumArray(start: Int, end: Int) -> Int {
        return summedNum[end] - summedNum[start - 1]
    }
}
