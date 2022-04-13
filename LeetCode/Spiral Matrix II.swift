//
//  Spiral Matrix II.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/04/13.
//

import Foundation

class Solution {
    func generateMatrix(_ n: Int) -> [[Int]] {
        let offsets = [(0,1),(1,0),(0,-1),(-1,0)]
        var answer: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)
        var y = 0
        var x = 0
        var filledCount = 0
        var lastOffsetIndex = 0
        
        while filledCount < n * n  {
            filledCount += 1
            answer[y][x] = filledCount
                        
            for index in lastOffsetIndex..<4 {
                let offset = offsets[index]
                let ny = y + offset.0
                let nx = x + offset.1
                
                guard isInBoundary(n: n, y: ny, x: nx), answer[ny][nx] == 0
                else { continue }

                y = ny
                x = nx
                lastOffsetIndex = index
                
                break
            }
            
            guard answer[y][x] != 0 else { continue }
            
            for index in 0..<lastOffsetIndex {
                let offset = offsets[index]
                let ny = y + offset.0
                let nx = x + offset.1
                
                guard isInBoundary(n: n, y: ny, x: nx), answer[ny][nx] == 0
                else { continue }

                y = ny
                x = nx
                lastOffsetIndex = index
                
                break
            }
        }
        
        
        return answer
    }
    
    private func isInBoundary(n: Int, y: Int, x: Int) -> Bool {
        return (0..<n) ~= y && (0..<n) ~= x
    }
}
