//
//  Permutations II.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/05/12.
//

import Foundation

class Solution {
    func permuteUnique(_ nums: [Int]) -> [[Int]] {
        var nums = nums.sorted()
        var answer: [[Int]] = [nums]

        while true {//내림차순 될 때 까지
            nextPermutation(arr: &nums)
            guard answer.last != nums else { break }
            answer.append(nums)
        }
        
        return answer
    }
    
    private func nextPermutation(arr: inout [Int]) {
        var first = arr.count - 1
        
        while first > 0, arr[first - 1] >= arr[first] {//find peek
            first -= 1
        }
        guard first != 0 else { return }
        
        first -= 1

        for i in (first+1 ..< arr.count).reversed() {
            if arr[first] < arr[i] {
                arr.swapAt(first, i)
                break
            }
        }
        
        first += 1
        var last = arr.count - 1
        while first < last {
            arr.swapAt(first, last)
            first += 1
            last -= 1
        }
    }
}
