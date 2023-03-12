//
//  Multiply Strings.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/12.
//

import Foundation

/*
 Runtime
 160 ms
 
 Memory
 14.8 MB
 
 class Solution {
     func multiply(_ num1: String, _ num2: String) -> String {
         guard num1 != "0" && num2 != "0" else { return "0"}
         
         var answer: [Character] = []
         let chars1: [Character] = Array(num1).reversed()
         let chars2: [Character] = Array(num2).reversed()
         
         var carry: Int = 0
         for (index, leftChar) in chars1.enumerated() {
             var result: [Character] = []
             carry = 0
             for rightChar in chars2 {
                 let val = leftChar.wholeNumberValue! * rightChar.wholeNumberValue! + carry
                 carry = val / 10
                 result.append(contentsOf: Array(String(val % 10).reversed()))
             }
             result.insert(contentsOf: [Character].init(repeating: "0", count: index), at: 0)
             if carry != 0 {
                 result.append(contentsOf: Array(String(carry)))
                 carry = 0
             }
             result.reverse()
             
             answer = plus(answer, result)
         }
         
         return String(answer)
     }
     
     func plus (_ left: [Character],_ right: [Character]) -> [Character] {
         var result: [Character] = []
         let leftReversed: [Character] = left.count >= right.count ? left.reversed() : right.reversed()
         let rightReversed: [Character] = left.count < right.count ? left.reversed() : right.reversed()
         
         var carry = 0
         for index in 0..<leftReversed.count {
             let leftChar = leftReversed[index]
             var sum = leftChar.wholeNumberValue! + carry
             carry = 0
             
             guard rightReversed.count > index
             else {
                 carry = sum / 10
                 result.append(contentsOf: Array(String(sum % 10)).reversed())
                 continue
             }
             
             let rightChar = rightReversed[index]
             sum += rightChar.wholeNumberValue!
             
             carry = sum / 10
             result.append(contentsOf: Array(String(sum % 10)).reversed())
         }
         
         if carry != 0 {
             result.append(contentsOf: Array(String(carry)))
         }
         return result.reversed()
     }
 }
 */

/*
 Runtime
 20 ms
 Memory
 14.8 MB
 */

class Solution {
    func multiply(_ num1: String, _ num2: String) -> String {
        guard num1 != "0" && num2 != "0" else { return "0"}
        
        var answer: [Int] = []
        let nums1 = num1.compactMap({
            $0.wholeNumberValue!
        }).reversed()
        let nums2 = num2.compactMap({
            $0.wholeNumberValue!
        }).reversed()
        
        var carry: Int = 0
        for (index, leftNum) in nums1.enumerated() {
            var result: [Int] = []
            carry = 0
            for rightNum in nums2 {
                let val = leftNum * rightNum + carry
                carry = val / 10
                result.append(val % 10)
            }
            result.insert(contentsOf: [Int].init(repeating: 0, count: index), at: 0)
            if carry != 0 {
                result.append(carry)
                carry = 0
            }
            result.reverse()
            
            answer = plus(answer, result)
        }
        
        return answer.reduce("") { (before, value) in
            before + String(value)
        }
    }
    
    func plus (_ left: [Int],_ right: [Int]) -> [Int] {
        var result: [Int] = []
        let leftReversed: [Int] = left.count >= right.count ? left.reversed() : right.reversed()
        let rightReversed: [Int] = left.count < right.count ? left.reversed() : right.reversed()
        
        var carry = 0
        for index in 0..<leftReversed.count {
            let leftChar = leftReversed[index]
            var sum = leftChar + carry
            carry = 0
            
            guard rightReversed.count > index
            else {
                carry = sum / 10
                result.append(sum % 10)
                continue
            }
            
            let rightChar = rightReversed[index]
            sum += rightChar
            
            carry = sum / 10
            result.append(sum % 10)
        }
        
        if carry != 0 {
            result.append(carry)
        }
        return result.reversed()
    }
}
