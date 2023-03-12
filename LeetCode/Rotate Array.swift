//
//  Rotate Array.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/12.
//

import Foundation

//Point: Use Inout

//doubled Array Ver
/*
 Runtime
 233 ms
 Memory
 21.8 MB

class Solution {
    func rotate(_ nums: inout [Int], _ k: Int) {
        var doubledArray: [Int] = []
        doubledArray.append(contentsOf: nums)
        doubledArray.append(contentsOf: nums)
        
        let rotateCount = k % nums.count
        nums = Array(doubledArray[nums.count-rotateCount...(2 * nums.count - rotateCount - 1)])
    }
}
 */

/*
 class Solution {
     func rotate(_ nums: inout [Int], _ k: Int) {
         let rotateCount = k % nums.count
         for _ in 0..<rotateCount {
             nums.insert(nums.removeLast(), at: 0)
         }
     }
 }
 */

/*
 Runtime
 227 ms
 Memory
 21.9 MB
 */

class Solution {
    func rotate(_ nums: inout [Int], _ k: Int) {
        let rotateCount = nums.count - k % nums.count
        nums = Array(nums[rotateCount...]) + Array(nums[..<rotateCount])
    }
}
