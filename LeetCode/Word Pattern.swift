//
//  Word Pattern.swift
//  Problem-Solving
//
//  Created by eden on 2023/10/03.
//

import Foundation

class Solution {
    func wordPattern(_ pattern: String, _ s: String) -> Bool {
        var patternDict: [String: String] = [:]
        var wordDict: [String: String] = [:]
        
        let patternWords = pattern.map({String($0)})
        let words = s.split(separator: " ").map({String($0)})

        guard patternWords.count == words.count else { return false }
        
        for (index, patternWord) in patternWords.enumerated() {
            let word = words[index]
            
            
            if patternDict[patternWord] == nil {
                guard wordDict[word] == nil else { return false }
                patternDict[patternWord] = word
                wordDict[word] = patternWord
            } else {
                guard patternDict[patternWord] == word && wordDict[word] == patternWord else { return false }
            }
        }
        
        return true
    }
}
