//
//  Perfect Squares - Array.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/04/11.
//

import Foundation

class Solution {
    
    var squares: [Int] = []
    var isVisited: [Bool] = Array(repeating: false, count: 10001)
    
    func numSquares(_ n: Int) -> Int {
        squares = (1...100).map {
            $0 * $0
        }
        
        return _numSquares(n)
    }
    
    func _numSquares(_ n: Int) -> Int {
        var count = 0
        
        //start
        var numArray: [Int] = [n]
        
        while !numArray.isEmpty {
            count += 1
            var tmpArray: [Int] = []
            
            for number in numArray {
                isVisited[number] = true
                
                for index in (0...getStartIndex(number)).reversed() {
                    let newNumber = number - squares[index]
                    
                    
                    guard newNumber >= 0 else { continue }
                    if newNumber == 0 {
                        return count
                    }
                    
                    if !isVisited[newNumber] {
                        tmpArray.append(newNumber)
                    }
                }
            }
            
            numArray = tmpArray
        }
        
        return count
    }
    
    func getStartIndex(_ number: Int) -> Int {
        var start = 0
        var end = squares.count - 1
        var mid = (end + start) / 2
        
        while start <= end {
            mid = (end + start) / 2
            
            if squares[mid] > number {
                end = mid - 1
            } else if squares[mid] == number {
                return mid
            }
            else {
                start = mid + 1
            }
        }
        
        return mid
    }
}
