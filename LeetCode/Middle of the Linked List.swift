//
//  Middle of the Linked List.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/23.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    
    public init() {
        self.val = 0
        self.next = nil
    }
    
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
    
    public init(_ val: Int, _ next: ListNode?) {
        self.val = val
        self.next = next
    }
}

class Solution {
    func middleNode(_ head: ListNode?) -> ListNode? {
        var startNode = head
        var endNode = head
        
        var moveCount = 0
        
        while endNode?.next != nil {
            if moveCount == 2 {
                startNode = startNode?.next
                moveCount = 0
                continue
            }
            
            endNode = endNode?.next
            moveCount += 1
        }
        
        if moveCount != 0 {
            startNode = startNode?.next
        }
        
        return startNode
    }
}
