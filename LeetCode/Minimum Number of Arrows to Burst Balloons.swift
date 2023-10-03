//
//  Minimum Number of Arrows to Burst Balloons.swift
//  Problem-Solving
//
//  Created by eden on 2023/10/02.
//

import Foundation

// Time: 4739ms
// Memory: 24.14MB

//class Solution {
//    func findMinArrowShots(_ points: [[Int]]) -> Int {
//        // sort by ending point
//        var points = points.sorted(by: {$0[1] < $1[1]})
//        var answer = 0
//
//        while !points.isEmpty {
//            let shootPoint = points[0][1]
//            for point in points {
//                guard point[0] <= shootPoint else { break }
//                let index = points.firstIndex(of: point)!
//                points.remove(at: index)
//            }
//            answer += 1
//            points = points.sorted(by: {$0[1] < $1[1]})
//        }
//
//        return answer
//    }
//}


// 1588ms, 23.94MB
//class Solution {
//    func findMinArrowShots(_ points: [[Int]]) -> Int {
//        // sort by ending point
//        var points = points.sorted(by: {
//            if $0[1] == $1[1] {
//                return $0[0] > $1[0]
//            }
//            return $0[1] > $1[1]
//        })
//        var answer = 0
//        while !points.isEmpty {
//            let shootPoint = points.last![1]
//
//            while !points.isEmpty, points.last![0] <= shootPoint {
//                points.removeLast()
//            }
//
//            answer += 1
//        }
//
//        return answer
//    }
//}

//1536ms, 23.76MB

class Solution {
    func findMinArrowShots(_ points: [[Int]]) -> Int {
        // sort by ending point
        let points = points.sorted(by: {
            if $0[1] == $1[1] {
                return $0[0] < $1[0]
            }
            return $0[1] < $1[1]
        })
        print(points)
        var answer = 0
        var index = 0
        
        while index < points.count {
            let shootPoint = points[index][1]
            var newIndex = index + 1
            
            while newIndex < points.count, points[newIndex][0] <= shootPoint {
                newIndex += 1
            }
            
            index = newIndex
            answer += 1
        }
        
        return answer
    }
}

