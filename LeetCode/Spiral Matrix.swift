//
//  Spiral Matrix.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/11.
//

import Foundation

class Solution {
    let offsets = [Position(x: 1, y: 0), Position(x: 0, y: 1), Position(x: -1, y: 0), Position(x: 0, y: -1)]
    var currentOffsetIndex = 0
    var matrix: [[Int]] = []
    var answer: [Int] = []
    var visitedPositions: [Position: Int] = [:]
    
    var currentPosition = Position(x: 0, y: 0)
    
    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        self.matrix = matrix
        
        answer.append(matrix[0][0])
        visitedPositions[currentPosition] = 1
        
        while canMove(currentPosition) {
            move(currentPosition)
        }
        
        return answer
    }
    
    private func canMove(_ position: Position) -> Bool {
        return getNextOffsetIndex(position) != -1
    }
    
    private func getNextOffsetIndex(_ position: Position) -> Int {
        var checkCount = 0
        
        var offsetIndex = currentOffsetIndex
        while checkCount < 4 {
            let offset = offsets[offsetIndex]
            let newPosition = position + offset
            
            guard !isValidate(newPosition)
            else {
                return offsetIndex
            }
            
            checkCount += 1
            offsetIndex = offsetIndex + 1 == offsets.count ? 0 : offsetIndex + 1
        }
        
        return -1
    }
    
    private func isValidate(_ position: Position) -> Bool {
        return (0..<matrix[0].count) ~= position.x && (0..<matrix.count) ~= position.y && !isVisited(position)
    }
    
    private func isVisited(_ position: Position) -> Bool {
        return visitedPositions[position] != nil
    }
    
    private func move(_ position: Position)  {
        let nextIndex = getNextOffsetIndex(position)
        let newPosition = position + offsets[nextIndex]
        
        currentOffsetIndex = nextIndex
        currentPosition = newPosition
        answer.append(matrix[currentPosition.y][currentPosition.x])
        visitedPositions[currentPosition] = 1
    }
}

struct Position: Hashable {
    let x: Int
    let y: Int
    
    static func + (left: Position, right: Position) -> Position {
        return Position(x: left.x + right.x, y: left.y + right.y)
    }
}
