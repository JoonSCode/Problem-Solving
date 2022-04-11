//
//  Game of Life.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/04/12.
//

import Foundation

class Solution {
    func gameOfLife(_ board: inout [[Int]]) {
        let offsets = [(0,-1),(0,1),(1,-1),(1,0),(1,1),(-1,-1),(-1,0),(-1,1)]
        
        
        for y in 0..<board.count {
            for x in 0..<board[y].count {
                var aroundLiveCount = 0
                for offset in offsets {
                    let ny = y + offset.0
                    let nx = x + offset.1
                    
                    guard isInBoundary(board: &board, y: ny, x: nx) else { continue }
                    let around = board[ny][nx] % 10
                    aroundLiveCount += around
                }
                
                if board[y][x] == 1 {
                    if 2...3 ~= aroundLiveCount {
                        board[y][x] = 111
                    } else {
                        board[y][x] = 101
                    }
                } else {
                    board[y][x] = aroundLiveCount == 3 ? 110 : 100
                }
            }
        }
        
        for y in 0..<board.count {
            for x in 0..<board[y].count {
                board[y][x] -= 100
                board[y][x] /= 10
            }
        }
    }
    
    func isInBoundary(board: inout [[Int]], y: Int, x: Int) -> Bool {
        return (0..<board.count) ~= y && (0..<board[y].count) ~= x
    }
}
