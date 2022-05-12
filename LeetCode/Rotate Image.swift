//
//  Rotate Image.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/05/12.
//

import Foundation

class Solution {
    func rotate(_ matrix: inout [[Int]]) {
        let diff = matrix.count - 1
        for i in 0...(matrix.count-1)/2 {
            for j in 0..<(matrix.count - 1 - i*2) {
                var position = [i,i + j]
                var cache = matrix[position[0]][position[1]]
                for _ in 0..<4 {
                    position.swapAt(0, 1)
                    position[1] = abs(position[1] - diff)
                    
                    let tempValue = matrix[position[0]][position[1]]
                    matrix[position[0]][position[1]] = cache
                    cache = tempValue
                }
            }
        }
    }
}
