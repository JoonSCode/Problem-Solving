//
//  Valid Palindrome.swift
//  Problem-Solving
//
//  Created by eden on 1/1/24.
//

import Foundation

class Solution {
    func isPalindrome(_ s: String) -> Bool {
        let s: [Character] = .init(s)
        var start = 0
        var end = s.count - 1
        
        while start < end {
            guard isAlphanumerics(s[start]) else {
                start += 1
                continue
            }
            
            guard isAlphanumerics(s[end]) else {
                end -= 1
                continue
            }
            
            guard s[start].lowercased() == s[end].lowercased() else { return false }
            start += 1
            end -= 1
        }
        
        return true
    }
    
    private func isAlphanumerics(_ character: Character) -> Bool {
        character.isLetter || character.isNumber
    }
}
