//
//  Longest Increasing Path in a Matrix.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/05/16.
//

import Foundation

class Solution {
    private var cache: [[Int]] = []
    private var width: Int {
        return cache[0].count
    }
    private var height: Int {
        return cache.count
    }
    private let offsets: [[Int]] = [[0,1], [0, -1], [-1, 0], [1, 0]]
    
    func longestIncreasingPath(_ matrix: [[Int]]) -> Int {
        cache = [[Int]](repeating: [Int](repeating: -1, count: matrix[0].count), count: matrix.count)
        var answer = 0
        
        for y in 0..<matrix.count {
            for x in 0..<matrix[0].count {
                answer = max(answer, longestIncreasingPath(matrix, startPosition: [y, x]))
                
            }
        }
        
        return answer
    }
    
    private func longestIncreasingPath(_ matrix: [[Int]], startPosition: [Int]) -> Int {
        let y = startPosition[0]
        let x = startPosition[1]
        let value = matrix[y][x]
        
        var longestPath = cache[y][x]
       
        guard longestPath == -1
        else { return longestPath }

        
        longestPath = 1
        for offset in offsets {
            let ny = y + offset[0]
            let nx = x + offset[1]
            
            guard isInBoundary(y: ny, x: nx), value < matrix[ny][nx] else { continue }
            longestPath = max(longestPath, longestIncreasingPath(matrix, startPosition: [ny, nx]) + 1)
        }
        cache[y][x] = longestPath
        
        return longestPath
    }
    
    private func isInBoundary(y: Int, x: Int) -> Bool {
        return 0..<height ~= y && 0..<width ~= x
    }
}
    
    
