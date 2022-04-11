//
//  Boj - 유레카 이론.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/01/05.
//

import Foundation

class Solution {
    
    var sizeOfTestCase = 0
    var testCases:[Int] = []
    
    var cacheTwoSumTriangularNumber = Array(repeating: false, count: 1000)
    var triangularNumbers: [Int] = []
    
    func main() {
        input()
        solve()
    }
    
    func input() {
        sizeOfTestCase = Int(readLine()!)!
        for _ in 0..<sizeOfTestCase {
            testCases.append(Int(readLine()!)!)
        }
    }
    
    //approach: Make cache of numbers which is sum of two triangular number
    func solve() {
        for i in 1...45 {
            triangularNumbers.append(i * (i+1) / 2)
        }
        
        makeToSumCache()
        
        for testCase in testCases {
            print(isTriangularNumber(testCase) ? "1" : "0")
        }
    }
    
    //O(n^2)
    func makeToSumCache() {
        for i in 0 ..< triangularNumbers.endIndex {
            for j in i ..< triangularNumbers.endIndex {
                let number = triangularNumbers[i] + triangularNumbers[j]
                if number >= 1000 { break }
                cacheTwoSumTriangularNumber[number] = true
            }
        }
    }
    
    func isTriangularNumber(_ number: Int) -> Bool {
        var index = 0
        while triangularNumbers[index] < number {
            if cacheTwoSumTriangularNumber[number - triangularNumbers[index]] {
                return true
            }
            index += 1
        }
        
        return false
    }
}
