//
//  Boj - 사탕게임.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/01/03.
//

import Foundation
//TODO: 통과는 하지만 알고리즘이 개선이 필요
class Solution {
    
    func main() {
        input()
        solve()
    }
    
    //Problem:
    //Time:O(n^3)
    //Space:
    
    var sizeOfBox: Int = 0
    var candyBox: [[Character]] = []
    var answer = 0

    private func input() {
        sizeOfBox = Int(readLine()!)!
        candyBox = Array(repeating: [], count: sizeOfBox)
        for i in 0..<sizeOfBox {
            let candyRow = readLine()!
            candyRow.forEach({
                candyBox[i].append($0)
            })
        }
    }

    private func solve() {
        changeCandy()
        print(answer)
    }

    private func changeCandy() {
        for y in 0..<sizeOfBox {
            for x in 0..<sizeOfBox {
                let candyColor = candyBox[y][x]

                if !isOutOfBounds(y: y+1, x: x), candyColor != candyBox[y+1][x] {
                    changeCandy(firstX: x, firstY: y, secondX: x, secondY: y+1)

                    answer = max(answer, findLongestCandy(isRow: true, value: y))
                    answer = max(answer, findLongestCandy(isRow: true, value: y+1))
                    answer = max(answer, findLongestCandy(isRow: false, value: x))

                    changeCandy(firstX: x, firstY: y, secondX: x, secondY: y+1)
                }

                if !isOutOfBounds(y: y, x: x+1) {
                    changeCandy(firstX: x, firstY: y, secondX: x+1, secondY: y)
                    answer = max(answer, findLongestCandy(isRow: true, value: y))
                    answer = max(answer, findLongestCandy(isRow: false, value: x+1))
                    answer = max(answer, findLongestCandy(isRow: false, value: x))
                    changeCandy(firstX: x, firstY: y, secondX: x+1, secondY: y)
                }
            }
        }
    }

    private func isOutOfBounds(y: Int, x: Int) -> Bool {
        return y < 0 || y >= sizeOfBox || x < 0 || x >= sizeOfBox
    }

    private func changeCandy(firstX: Int, firstY: Int, secondX: Int, secondY: Int) {
        let tmp = candyBox[firstY][firstX]
        candyBox[firstY][firstX] = candyBox[secondY][secondX]
        candyBox[secondY][secondX] = tmp
    }
    
    //Time: O(n^2)
    private func eatCandy(isRow: Bool, value: Int) -> Int {
        var candyToEat = 0
        for i in 0..<sizeOfBox {
            candyToEat = max(candyToEat, findLongestCandy(isRow: isRow, value: value))
            candyToEat = max(candyToEat, findLongestCandy(isRow: isRow, value: value))
        }
        return candyToEat
    }
    
    //Time: O(n)
    private func findLongestCandy(isRow: Bool, value: Int) -> Int {
        var longestCandyCount = -1
        var nowCandyCount = 0
        var nowCandyColor: Character = "1"
        
        for i in 0..<sizeOfBox {
            let candyColor = isRow ? candyBox[value][i] : candyBox[i][value]
            
            guard nowCandyColor != candyColor
            else {
                nowCandyCount += 1
                continue
            }
            
            if longestCandyCount < nowCandyCount {
                longestCandyCount = nowCandyCount
            }
            nowCandyCount = 1
            nowCandyColor = candyColor
        }
        
        if longestCandyCount < nowCandyCount {
            longestCandyCount = nowCandyCount
        }
        return longestCandyCount
    }
}
