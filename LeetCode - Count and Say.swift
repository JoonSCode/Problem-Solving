//
//  LeetCode - Count and Say.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/01/05.
//

import Foundation

class Solution {
    
    //Time: O(n*m) m: length of answer which means longest string
    //Space: O(m)
    func countAndSay(_ n: Int) -> String {
        var numberToSay = "1"
        
        for _ in 1..<n {
            numberToSay = countAndSay(number: numberToSay)
        }
        
        return numberToSay
    }
    
    private func countAndSay(number: String) -> String {
        var numberToSay = ""
        var countedNumber: Character = "0"
        var numberCount = 0
        
        number.forEach({
            if $0 != countedNumber {
                numberToSay += "\(numberCount)\(countedNumber)"
                numberCount = 1
                countedNumber = $0
            } else {
                numberCount += 1
            }
        })
        numberToSay += "\(numberCount)\(countedNumber)"
        let startIndex = numberToSay.index(numberToSay.startIndex, offsetBy: 2)
        return String(numberToSay[startIndex...])
    }
}
