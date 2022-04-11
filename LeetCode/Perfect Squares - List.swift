//
//  Perfect Squares.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/04/11.
//

import Foundation

class Solution {
    
    var squares: [Int] = []
    var isVisited: [Bool] = Array(repeating: false, count: 10001)
    
    func numSquares(_ n: Int) -> Int {
        squares = (1...100).reversed().map {
            $0 * $0
        }
        
        return _numSquared(n)
    }
    
    func _numSquared(_ n: Int) -> Int {
        var count = 0
        
        //start
        let numQueue = Queue<Int>()
        numQueue.push(n)
        
        while !numQueue.isEmpty {
            let queueCount = numQueue.count
            count += 1
            
            for _ in 0..<queueCount {
                let number = numQueue.pop()!
                isVisited[number] = true
                for square in squares {
                    let newNumber = number - square
                    guard newNumber >= 0 else { continue }
                    if newNumber == 0 {
                        while !numQueue.isEmpty {
                            numQueue.pop()
                        }
                        return count
                    }
                    if !isVisited[newNumber] {
                        numQueue.push(newNumber)
                    }
                }
            }
        }
        
        return count
    }
}

class Queue<T> {
    private var first: Node<T>?
    private var last: Node<T>?
    var count = 0
    
    var isEmpty: Bool {
        return count == 0
    }
    
    @discardableResult
    func pop() -> T? {
        let tmp = first?.value
        first = first?.next
        count -= 1
        if isEmpty {
            last = nil
        }
        return tmp
    }
    
    func push(_ value: T) {
        push(node: Node(value: value))
        count += 1
    }
    
    private func push(node: Node<T>) {
        if first == nil {
            first = node
            last = node
            return
        }
        last?.next = node
        last = node
    }
}

class Node<T> {
    var value: T
    var before: Node?
    var next: Node?
    
    init(value: T) {
        self.value = value
    }
    
    func appendBefore(node: Node) {
        let beforeNode = before
        beforeNode?.next = node
        node.next = self
        before = node
    }
    
    func appendBefore(value: T) {
        appendBefore(node: Node(value: value))
    }
    
    func appendNext(node: Node) {
        let nextNode = next
        node.next = nextNode
        node.before = self
        next = node
    }
    
    func appendNext(value: T) {
        appendNext(node: Node(value: value))
    }
}
