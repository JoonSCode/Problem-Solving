//
//  LeetCode - Regular Expression Matching.swift
//  Problem-Solving
//
//  Created by eden.joon on 2021/10/20.
//

import Foundation

class Solution {
    func isMatch(_ s: String, _ p: String) -> Bool {
        let sArr: [Character] = Array(s)
        let pArr: [Character] = Array(p)
        
        return compare(sArr, pArr)
    }
    
    func checkNextIsAsterisk(p: [Character], index: Int) -> Bool {
        return p[index + 1] == "*"
    }
    
    func isMatch(_ sChar: Character, _ pChar: Character) -> Bool {
        return pChar == "." || sChar == pChar
    }
    
    func compare(_ sArr: [Character], _ pArr: [Character]) -> Bool {
        var sIndex = 0
        var pIndex = 0
        
        while sIndex < sArr.count && pIndex < pArr.count {
            let sChar = sArr[sIndex]
            let pChar = pArr[pIndex]
  
            //MARK: 뒤에 *이 없는 경우
            guard pIndex + 1 < pArr.count
            else {
                if !isMatch(sChar, pChar) {
                    return false
                }
                sIndex += 1
                pIndex += 1
                continue
            }
            
            //MARK: 뒤에 *이 있는 경우
            
            if checkNextIsAsterisk(p: pArr, index: pIndex) {
                guard isMatch(sChar, pChar)
                else {
                    pIndex += 2
                    continue
                }
                
                if compare(Array(sArr[(sIndex)...]), Array(pArr[(pIndex+2)...])){
                    return true
                }
                
                while sIndex < sArr.count && isMatch(sArr[sIndex], pChar) {
                    if compare(Array(sArr[(sIndex + 1)...]), Array(pArr[(pIndex+2)...])){
                        return true
                    }
                    sIndex += 1
                }
                if sIndex >= sArr.count && (pArr.count - pIndex) % 2 == 0 {
                    pIndex += 1
                    while pIndex < pArr.count {
                        guard pArr[pIndex] == "*" else { return false }
                        pIndex += 2
                    }
                    return true
                }
                
                return false
            }
            
            if !isMatch(sChar, pChar) {
                return false
            }
            
            sIndex += 1
            pIndex += 1
            continue
        }
        
        
        if sIndex >= sArr.count && (pArr.count - pIndex) % 2 == 0 {
            pIndex += 1
            while pIndex < pArr.count {
                guard pArr[pIndex] == "*" else { return false }
                pIndex += 2
            }
            return true
        }
        
        return false
    }
}
