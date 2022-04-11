//
//  Combination Sum .swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/04/01.
//

import Foundation

class Solution {
    var cache: [Int: Set<[Int]>] = [:]
    var candidates: [Int] = []
    
    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        self.candidates = candidates.sorted()
        return combinationSum(target)
    }
    
    func combinationSum(_ target: Int) -> [[Int]] {
        if let cachedAnswer = cache[target] {
            return Array(cachedAnswer)
        }
        
        var answer: [[Int]] = []
        
        for candidate in candidates {
            let newTarget = target - candidate
            
            if newTarget == 0 {
                answer.append([candidate])
            }
            
            guard newTarget > 0 else { break }
            answer.append(contentsOf: combinationSum(newTarget).map({
                var tmpAnswer = $0
                tmpAnswer.append(candidate)
                return tmpAnswer.sorted()
            }))
        }
        
        addCache(target: target, values: answer)
        return Array(cache[target]!)
    }
    
    func addCache(target: Int, values: [[Int]]) {
        if cache[target] == nil {
            cache[target] = []
        }
        
        for value in values {
            cache[target]?.insert(value)
        }
    }
}
