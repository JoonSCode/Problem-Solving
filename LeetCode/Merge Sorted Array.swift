//
//  Merge Sorted Array.swift
//  Problem-Solving
//
//  Created by eden on 2023/05/06.
//

// Easy
import Foundation

class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        //while merge finish
        //compare first
        //append min value to array

        var mergedArray: [Int] = []
        
        var nums1Index = 0
        var nums2Index = 0

        var isMergeFinish: Bool {
            nums1Index == m  || nums2Index == n
        }

        while !isMergeFinish {
            let num1 = nums1[nums1Index]
            let num2 = nums2[nums2Index]

            mergedArray.append(min(num1, num2))

            if num1 == min(num1, num2) {
                nums1Index += 1
            } else {
                nums2Index += 1
            }
        }

        if nums1Index == m {
            mergedArray.append(contentsOf: nums2[nums2Index..<n])
        } else {
            mergedArray.append(contentsOf: nums1[nums1Index..<m])
        }
        print(mergedArray)
        nums1 = mergedArray
    }
}
