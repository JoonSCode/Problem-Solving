//
//  Boj - 분해합.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2021/12/20.
//

import Foundation

class Solution {
    func main() {
        input()
        solve()
    }
    
    var targetNumber: String = ""
    var answer = 0
    
    func input() {
        targetNumber = readLine()!
    }
    
    func solve() {
        let minNumber = Int(targetNumber)! - targetNumber.count * 9
        
        for number in minNumber...Int(targetNumber)! {
            var newNumber = number
            var tmpNumber = number
            
            while tmpNumber != 0 {
                newNumber += tmpNumber % 10
                tmpNumber /= 10
            }
            
            
            if newNumber == Int(targetNumber)! {
                answer = number
                break
            }
        }
        
        print(answer)
    }
}
