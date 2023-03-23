//
//  Permutation in String.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/23.
//

import Foundation

class Solution {
    func checkInclusion(_ s1: String, _ s2: String) -> Bool {
        let s1Chars = Array(s1)
        var s1Dictionary: [Character: Int] = [:]
        let s2Chars = Array(s2)
        var answerDictionary: [Character: Int] = [:]
        
        guard s1Chars.count <= s2Chars.count else { return false }
        
        s1Chars.forEach({
            s1Dictionary[$0, default: 0] += 1
        })
        
        for i in 0..<s1Chars.count {
            answerDictionary[s2Chars[i], default: 0] += 1
        }
        
        for i in s1Chars.count..<s2Chars.count {
            if s1Dictionary == answerDictionary {
                return true
            }
            
            let indexToDelete = i - s1Chars.count
            answerDictionary[s2Chars[indexToDelete], default: 0] -= 1
            if answerDictionary[s2Chars[indexToDelete], default: 0] == 0 {
                answerDictionary.removeValue(forKey: s2Chars[indexToDelete])
            }
            answerDictionary[s2Chars[i], default: 0] += 1
        }
        
        return s1Dictionary == answerDictionary
    }
}
