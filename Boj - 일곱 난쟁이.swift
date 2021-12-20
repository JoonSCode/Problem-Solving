//
//  Boj - 일곱 난쟁이.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2021/12/20.
//

import Foundation

// Problem: select seven dwarf from nine, sum of selceted dwart's tall is 100

class Solution {
    func main() {
        input()
        solve()
    }
    
    var tallOfDwarfs: [Int] = []
    
    func input() {
        for _ in 0..<9 {
            tallOfDwarfs.append(Int(readLine()!)!)
        }
    }
    
    func solve() {
        var sumOfAllTall = 0
        tallOfDwarfs.forEach({
            sumOfAllTall += $0
        })
        
        let numToFind = sumOfAllTall - 100
        findTwoDwart(sumOfTall: numToFind)
        
        let answer = tallOfDwarfs
        answer.forEach({
            print($0)
        })
    }
    
    func findTwoDwart(sumOfTall: Int) {
        tallOfDwarfs.sort()
        
        var start = 0
        var end = tallOfDwarfs.count - 1
        while start < end {
            guard tallOfDwarfs[start] + tallOfDwarfs[end] != sumOfTall
            else {
                tallOfDwarfs.remove(at: end)
                tallOfDwarfs.remove(at: start)
                return
            }
            
            if tallOfDwarfs[start] + tallOfDwarfs[end] > sumOfTall {
                end -= 1
            } else {
                start += 1
            }
        }
    }
}
