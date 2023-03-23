//
//  Reverse Words in a String III.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/22.
//

import Foundation

class Solution {
    func reverseWords(_ s: String) -> String {
        let subStrings = s.split(separator: " ")
        var reversedSubStrings: [String] = []
        
        subStrings.forEach({
            reversedSubStrings.append(String(Array($0).reversed()))
        })
        
        return String(reversedSubStrings.joined(separator: " "))
    }
}
