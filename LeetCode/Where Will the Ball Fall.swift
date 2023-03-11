//
//  Where Will the Ball Fall.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/11.
//

import Foundation

/*
Runtime
186 ms
 
Memory
14.2 MB
 
class Solution {
    var grid: [[Int]]!
    
    func findBall(_ grid: [[Int]]) -> [Int] {
        self.grid = grid
        
        var answer: [Int] = []
        for startX in (0..<grid[0].count) {
            answer.append(redirectBall(Position(x: startX, halfY: 0)))
        }
        
        return answer
    }
    
    func redirectBall(_ position: Position) -> Int {
        let isEnd = position.y == grid.count
        guard !isEnd else { return position.x }
        
        let directNow = getDirect(position)
        let newPosition = Position(x: position.x + (position.isUpper ? directNow : 0), halfY: position.halfY + 1)
        
        guard canMove(directBefore: directNow, newPosition) else {
            return -1
        }
        
        return redirectBall(newPosition)
    }
    
    func canMove(directBefore: Int, _ position: Position) -> Bool {
        let isRedirectToWall = !((0..<grid[0].count) ~= position.x)
        guard !isRedirectToWall else { return false }
        
        let isVShape = !position.isUpper && directBefore != getDirect(position)
        return !isVShape
    }
            
    func getDirect(_ position: Position) -> Int {
        return grid[position.y][position.x]
    }
}

 
class Position {
    var x: Int
    var halfY: Int
    var y: Int {
        halfY / 2
    }
    var isUpper: Bool {
        return halfY % 2 == 0
    }
    
    init(x: Int, halfY: Int) {
        self.x = x
        self.halfY = halfY
    }
} */

/*
 Runtime
 161 ms
 Memory
 14.5 MB
 */

class Solution {
    var grid: [[Int]]!
    
    func findBall(_ grid: [[Int]]) -> [Int] {
        self.grid = grid
        
        var answer: [Int] = []
        for startX in (0..<grid[0].count) {
            answer.append(redirectBall(Position(x: startX, halfY: 0)))
        }
        
        return answer
    }
    
    func redirectBall(_ position: Position) -> Int {
        var currentPosition = position
        var isEnd = currentPosition.y == grid.count
        
        while !isEnd && canMove(currentPosition) {
            let directNow = getDirect(currentPosition)
            currentPosition.x += (currentPosition.isUpper ? directNow : 0)
            currentPosition.halfY += 1
            isEnd = currentPosition.y == grid.count
        }
        
        return isEnd ? currentPosition.x : -1
    }
    
    func getNextPosition(_ position: Position) -> Position {
        let directNow = getDirect(position)
        let nextPosition = Position(x: position.x + (position.isUpper ? directNow : 0), halfY: position.halfY + 1)
        
        return nextPosition
    }
    
    func canMove(_ position: Position) -> Bool {
        let directNow = getDirect(position)
        let nextPosition = getNextPosition(position)
        
        let isRedirectToWall = !((0..<grid[0].count) ~= nextPosition.x)
        guard !isRedirectToWall else { return false }
        
        let isVShape = !nextPosition.isUpper && directNow != getDirect(nextPosition)
        return !isVShape
    }
            
    func getDirect(_ position: Position) -> Int {
        return grid[position.y][position.x]
    }
}

class Position {
    var x: Int
    var halfY: Int
    var y: Int {
        halfY / 2
    }
    var isUpper: Bool {
        return halfY % 2 == 0
    }
    
    init(x: Int, halfY: Int) {
        self.x = x
        self.halfY = halfY
    }
}
