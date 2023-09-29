//
//  Jump Game II.swift
//  Problem-Solving
//
//  Created by eden on 2023/09/29.
//

import Foundation

// Top Down Dynamic programming

//class Solution {
//    var nums: [Int] = []
//    var cache: [Int] = []
//    func jump(_ nums: [Int]) -> Int {
//        self.nums = nums
//        cache = .init(repeating: -1, count: nums.count)
//        cache[nums.count - 1] = 0
//        return jump(startPosition: 0)
//    }
//
//    func jump(startPosition: Int) -> Int {
//        guard cache[startPosition] == -1 else { return cache[startPosition] }
//        let maxJump = nums[startPosition] + startPosition
//        var minJumpCount = Int.max
//        if maxJump == startPosition {
//            cache[startPosition] = minJumpCount
//            return minJumpCount
//        }
//
//        for nextPosition in (startPosition + 1)...min(nums.count - 1, maxJump) {
//            let jumpCount = jump(startPosition: nextPosition)
//            guard jumpCount != Int.max else { continue }
//            minJumpCount = min(minJumpCount, jumpCount + 1)
//        }
//
//        cache[startPosition] = minJumpCount
//        return minJumpCount
//    }
//}

// Greedy
//class Solution {
//    var nums: [Int] = []
//    func jump(_ nums: [Int]) -> Int {
//        guard nums.count > 1 else { return 0 }
//        self.nums = nums
//        return jump(from: [0], count: 0)
//    }
//
//    func jump(from: [Int], count: Int) -> Int {
//        let maxFrom = from.last!
//        var maxNext = maxFrom
//
//        from.forEach({ start in
//            maxNext = max(maxNext, start + nums[start])
//        })
//
//        if maxNext >= nums.count - 1 {
//            return count + 1
//        }
//
//        return jump(from: Array(maxFrom + 1...maxNext), count: count + 1)
//    }
//}

// Greedy - while
class Solution {
    func jump(_ nums: [Int]) -> Int {
        guard nums.count > 1 else { return 0 }
        var count = 0
        var start = 0
        var end = 0
        
        repeat {
            var maxNext = end
            for i in start...end {
                maxNext = max(maxNext, i + nums[i])
            }
            
            start = end + 1
            end = maxNext
            count += 1
        } while end < nums.count - 1
        
        return count
    }
}
