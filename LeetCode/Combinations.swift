//
//  Combinations.swift
//  Problem-Solving
//
//  Created by eden on 2023/10/08.
//

import Foundation

class Solution {
    var answer: [[Int]] = []

    func combine(_ n: Int, _ k: Int) -> [[Int]] {
        var selected: [Int] = []
        dfs(start: 1, n: n, k: k, selected: &selected)
        return answer
    }
    
    func dfs(start: Int, n: Int, k: Int, selected: inout [Int]) {
        guard k > 0 else {
            answer.append(selected)
            return
        }
        guard n - start + 1 >= k else { return }
            
        for i in start...n {
            selected.append(i)
            dfs(start: i+1, n: n, k: k-1, selected: &selected)
            selected.removeLast()
        }
    }
}
