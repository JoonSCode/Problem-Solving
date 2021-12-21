//
//  LeetCode - Generate Parentheses .swift
//  Problem-Solving
//
//  Created by 윤준수 on 2021/12/21.
//

import Foundation

class Solution {
    //n개의 괄호 쌍을 가진 것들을 찾아 반환
    
    //1: ()
    //2: ()(), (())
    //1+1, 2
    //3: ()()(), (())(), ()(()), (()()), ((()))
    // 1+1+1, 1+2+, 2+1, 3
    //4: 1+1+1+1, 1+2+1, 2+1+1, 3+1
    // 1+1+1+1, 1+1+2, 1+2+1, 1+3
    // 크게 둘러싸는 케이스 하나 더 추가
    
    var pairSet: [String] = [""]
    var parenthesis: [Set<String>] = Array(repeating: [], count: 9)
    
    func generateParenthesis(_ n: Int) -> [String] {
        pairSet.append("()")
        for i in 2...8 {
            pairSet.append("(\(pairSet[i-1]))")
        }
        parenthesis[1].insert(pairSet[1])
        
        return getParenthesis(n)
    }
    
    func getParenthesis(_ n: Int) -> [String] {
        if !parenthesis[n].isEmpty {
            return Array(parenthesis[n])
        }
        
        for i in 1...n-1 {
            let first = getParenthesis(i)
            let second = getParenthesis(n-i)
            first.forEach({ value in
                second.forEach({
                    parenthesis[n].insert(value+$0)
                })
            })
        }
        let before = getParenthesis(n-1)
        before.forEach({
            parenthesis[n].insert("(\($0))")
        })
        
        return Array(parenthesis[n])
    }
}
