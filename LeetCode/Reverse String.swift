//
//  Reverse String.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/22.
//

import Foundation

class Solution {
    func reverseString(_ s: inout [Character]) {
        var startIndex = 0
        var endIndex = s.count - 1
        
        while startIndex <= endIndex {
            s.swapAt(startIndex, endIndex)
            startIndex += 1
            endIndex -= 1
        }
    }
}
