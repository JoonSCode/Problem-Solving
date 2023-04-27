//
//  Search a 2D Matrix.swift
//  Problem-Solving
//
//  Created by eden on 2023/04/27.
//

import Foundation

class Solution {
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        // selectRow
        var row = findRow(matrix, target)
        return binarySearch(matrix[row], target)
    }
    
    private func findRow(_ matrix: [[Int]], _ target: Int) -> Int {
        var start = 0
        var end = matrix.count - 1
        var row = 0
        while start < end  {
            let mid = (start + end) / 2
            if matrix[mid][0] > target {
                end = mid - 1
            } else if mid + 1 == matrix.count {
                row = mid
                break
            } else {
                if matrix[mid + 1][0] > target {
                    row = mid
                    break
                }
                start = mid + 1
            }
        }
        if start == end {
            row = start
        }
        
        return row
    }
    
    private func binarySearch(_ matrix: [Int], _ target: Int) -> Bool {
        var start = 0
        var end = matrix.count - 1
        while start <= end {
            let mid = (start + end) / 2
            
            if matrix[mid] == target {
                return true
            } else if matrix[mid] < target {
                start = mid + 1
            } else {
                end = mid - 1
            }
        }
        
        return false
    }
}
