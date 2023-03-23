//
//  Flood Fill.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/23.
//

import Foundation

class Solution {
    var maxY: Int = 0
    var maxX: Int = 0
    
    func floodFill(_ image: [[Int]], _ sr: Int, _ sc: Int, _ color: Int) -> [[Int]] {
        let offsets = [(y: 0, x: 1), (y: 0, x: -1), (y: 1, x: 0), (y: -1, x: 0)]
        var answer = image
        maxY = image.count - 1
        maxX = image[0].count - 1
        var floodQueue: [(y: Int, x: Int)] = [(y: sr, x: sc)]
        let originalColor = answer[sr][sc]
        
        
        while !floodQueue.isEmpty {
            let start = floodQueue.removeLast()
            guard answer[start.y][start.x] != color else { continue }
            answer[start.y][start.x] = color

            for offset in offsets {
                let ny = start.y + offset.y
                let nx = start.x + offset.x
                guard isInBoundary(y: ny, x: nx), answer[ny][nx] == originalColor else { continue }
                floodQueue.append((y: ny, x: nx))
            }
        }
        return answer
    }
    
    private func isInBoundary(y: Int, x: Int) -> Bool {
        return (0...maxY) ~= y && (0...maxX) ~= x
    }
}
