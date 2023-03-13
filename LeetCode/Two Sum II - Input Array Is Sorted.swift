//
//  Two Sum II - Input Array Is Sorted.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/13.
//

import Foundation

/* BinarySearch
 Runtime
 65 ms
 Memory
 14.7 MB
 
class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        for (index, number) in numbers.enumerated() {
            let result = binarySearch(numbers, start: index + 1, end: numbers.count - 1, target: target - number)
            if result != -1 {
                return [index + 1, result + 1]
            }
        }
        
        return []
    }
    
    func binarySearch(_ numbers: [Int], start: Int, end: Int, target: Int) -> Int {
        var start = start
        var end = end
        var mid = 0
        repeat {
            mid = (start + end) / 2
            if numbers[mid] < target {
                start = mid + 1
            } else {
                end = mid - 1
            }
        } while numbers[mid] != target && start <= end
                
        return numbers[mid] == target ? mid : -1
    }
}

*/

/*
 Two Pointer
 Runtime
 67 ms
 Memory
 14.9 MB
 */

class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        var start = 0
        var end = numbers.count - 1
        
        var sum = 0
        repeat {
            sum = numbers[start] + numbers[end]
            if sum > target {
                end -= 1
            } else if sum < target {
                start += 1
            }
        } while sum != target
        
        return [start + 1, end + 1]
    }
}
