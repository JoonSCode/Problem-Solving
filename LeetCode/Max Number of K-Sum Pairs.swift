//
//  Max Number of K-Sum Pairs.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/05/04.
//

import Foundation

class Solution {
    func maxOperations(_ nums: [Int], _ k: Int) -> Int {
        var answer = 0
        guard k != 1 else { return answer }
        
        var numDictionary: [Int: Int] = [:]

        for num in nums {
            numDictionary[num, default: 0] += 1
        }

        for key in numDictionary.keys {
            guard key <= k/2, let first = numDictionary[key], let second = numDictionary[k-key] else { continue }
            answer += min(first, second)
        }

        if k%2 == 0, let first = numDictionary[k/2] {
            answer -= (first - first/2)
        }

        return answer
    }
}
