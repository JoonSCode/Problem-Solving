//
//  LeetCode - Valid Sudoku.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/01/04.
//

import Foundation

class Solution {
//    var validRowCache = Array(repeating: false, count: 9)
//    var validColumnCache = Array(repeating: false, count: 9)
//    var validSectionCache = Array(repeating: false, count: 9)
//
//    func isValidSudoku(_ board: [[Character]]) -> Bool {
//        for row in 0..<9 {
//            for column in 0..<9 {
//                guard board[row][column] != "." else { continue }
//                guard isValidSudokuRow(board: board, row: row),
//                      isValidSudokuColumn(board: board, column: column),
//                      isValidSudokuSection(board: board, row: row, column: column)
//                else {
//                    return false
//                }
//            }
//        }
//        return true
//    }
//
//    private func isValidSudokuRow(board: [[Character]], row: Int) -> Bool {
//        if validRowCache[row] {
//            return true
//        }
//        var dictionary: [Character: Int] = [:]
//
//        for column in 0..<9 {
//            let number = board[row][column]
//
//            if number == "." {
//                continue
//            }
//
//            if dictionary[number] == nil {
//                dictionary[number] = 1
//            } else {
//                return false }
//        }
//
//        validRowCache[row] = true
//        return validRowCache[row]
//    }
//
//    private func isValidSudokuColumn(board: [[Character]], column: Int) -> Bool {
//        if validColumnCache[column] {
//            return true
//        }
//
//        var dictionary: [Character: Int] = [:]
//
//        for row in 0..<9 {
//            let number = board[row][column]
//            if number == "." {
//                continue
//            }
//
//            if dictionary[number] == nil {
//                dictionary[number] = 1
//            } else {
//                return false }
//        }
//
//        validColumnCache[column] = true
//        return validColumnCache[column]
//    }
//
//    private func isValidSudokuSection(board: [[Character]], row: Int, column: Int) -> Bool {
//        let startRow = row / 3 * 3
//        let endRow = startRow + 2
//        let startColumn = column / 3 * 3
//        let endColumn = startColumn + 2
//
//        let section = startRow + startColumn / 3
//        if validSectionCache[section] {
//            return true
//        }
//
//        var dictionary: [Character: Int] = [:]
//
//        for row in startRow...endRow {
//            for column in startColumn...endColumn{
//                let number = board[row][column]
//                if number == "." {
//                    continue
//                }
//
//                if dictionary[number] == nil {
//                    dictionary[number] = 1
//                } else {
//                    return false }
//            }
//        }
//
//        validSectionCache[section]  = true
//        return validSectionCache[section]
//    }
    
    
    func isValidSudoku(_ board: [[Character]]) -> Bool {
        for row in 0..<9 {
            if !isValidSudokuRow(board: board, row: row) { return false }
        }
        
        for column in 0..<9 {
            if !isValidSudokuColumn(board: board, column: column) { return false }
        }
        
        for row in stride(from: 0, to: 7, by: 3) {
            for column in stride(from: 0, to: 7, by: 3){
                if !isValidSudokuSection(board: board, row: row, column: column) { return false }
            }
        }
        
    
        return true
    }
    
    private func isValidSudokuRow(board: [[Character]], row: Int) -> Bool {
        var dictionary: [Character: Int] = [:]
        
        for column in 0..<9 {
            let number = board[row][column]
            
            if number == "." {
                continue
            }
            
            if dictionary[number] == nil {
                dictionary[number] = 1
            } else { return false }
        }
        
        return true
    }
    
    private func isValidSudokuColumn(board: [[Character]], column: Int) -> Bool {
        var dictionary: [Character: Int] = [:]
        
        for row in 0..<9 {
            let number = board[row][column]
            if number == "." {
                continue
            }
            
            if dictionary[number] == nil {
                dictionary[number] = 1
            } else { return false }
        }
        
        return true
    }
    
    private func isValidSudokuSection(board: [[Character]], row: Int, column: Int) -> Bool {
        let endRow = row + 2
        let endColumn = column + 2
        
        var dictionary: [Character: Int] = [:]
        
        for row in row...endRow {
            for column in column...endColumn{
                let number = board[row][column]
                if number == "." {
                    continue
                }
                
                if dictionary[number] == nil {
                    dictionary[number] = 1
                } else {
                    return false }
            }
        }
        
        return true
    }
}
