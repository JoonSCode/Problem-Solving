//
//  Find K Pairs with Smallest Sums.swift
//  Problem-Solving
//
//  Created by eden on 2023/09/29.
//

import Foundation

class Solution {
    func kSmallestPairs(_ nums1: [Int], _ nums2: [Int], _ k: Int) -> [[Int]] {
        var answer: [[Int]] = []
        var pairs: Set<[Int]> = [[0, 0]]
        var pairInAnswer: [[Int]: Bool] = [:]

        while answer.count < min(k, nums1.count * nums2.count) && !pairs.isEmpty {
            var minPair: [Int] = []
            var pairSum = Int.max

            pairs.forEach({ pair in
                let sum = nums1[pair[0]] + nums2[pair[1]]
                if sum < pairSum {
                    pairSum = sum
                    minPair = pair
                }
            })

            pairInAnswer[minPair, default: true] = true
            answer.append([nums1[minPair[0]], nums2[minPair[1]]])
            pairs.remove(minPair)
            if minPair[0] + 1 < nums1.count && !pairInAnswer[[minPair[0] + 1, minPair[1]], default: false] {
                pairs.insert([minPair[0] + 1, minPair[1]])
            }
            if minPair[1] + 1 < nums2.count && !pairInAnswer[[minPair[0], minPair[1] + 1], default: false]  {
                pairs.insert([minPair[0], minPair[1] + 1])
            }
        }

        return answer
    }
}
