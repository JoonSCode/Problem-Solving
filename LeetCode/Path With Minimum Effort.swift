//
//  Path With Minimum Effort.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/04/28.
//

import Foundation

class Solution {
    
    private let offsets: [(y: Int,x: Int)] = [(1,0), (-1,0), (0,1), (0,-1)]
    private var minimumEffortCache: [[Int]] = []
    private var isVisited: [[Bool]] = []
    private var map: [[Int]] = []
    
    private var height: Int {
        map.count
    }
    private var width: Int {
        map[0].count
    }
    private var answer: Int {
        minimumEffortCache.last!.last!
    }
    
    func minimumEffortPath(_ heights: [[Int]]) -> Int {
        map = heights
        isVisited = Array(repeating: Array(repeating: false, count: width), count: height)
        minimumEffortCache = Array(repeating: Array(repeating: Int.max, count: width), count: height)
        
        dajik()
        return answer
    }
    
    private func dajik() {
        var adjList: [Node] = [Node(y: 0, x: 0, value: 0)]
        minimumEffortCache[0][0] = 0
        
        while !adjList.isEmpty {
            let now = adjList.removeFirst()
            let y = now.y
            let x = now.x
            guard !isVisited[y][x] else { continue }
            
            isVisited[now.y][now.x] = true
            if now.y == map.count - 1 && now.x == map[0].count - 1 {
                return
            }
            
            //adj찾기
            for offset in offsets {
                let ny = y + offset.y
                let nx = x + offset.x
                
                guard isInBoundary(y: ny, x: nx), !isVisited[ny][nx] else { continue }
                let distance = max(abs(map[now.y][now.x] - map[ny][nx]), now.value)
                
                if minimumEffortCache[ny][nx] > distance {
                    minimumEffortCache[ny][nx] = distance
                    insert(arr: &adjList, node: Node(y: ny, x: nx, value: distance))
                }
            }
        }
    }
    
    private func isInBoundary(y: Int, x: Int) -> Bool {
        return y >= 0 && y < height && x >= 0 && x < width
    }
    
    private func insert(arr: inout [Node], node: Node) {
        for (index, arrNode) in arr.enumerated() {
            if arrNode.value > node.value {
                arr.insert(node, at: index)
                return
            }
        }
        
        arr.append(node)
    }
}

struct Node {
    var y: Int
    var x : Int
    var value: Int
    
    init(y: Int, x: Int, value: Int) {
        self.y = y
        self.x = x
        self.value = value
    }
}
