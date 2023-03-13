//
//  Remove Nth Node From End of List.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/14.
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
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        var nodes: [ListNode] = []
        var now = head
        
        while let tmp = now {
            nodes.append(tmp)
            now = tmp.next
        }
        
        let nodeToDelete = nodes[nodes.count - n]
        if nodes.count == n {
            return nodeToDelete.next
        } else {
            nodes[nodes.count - n - 1].next = nodeToDelete.next
        }
        
        return nodes.first
    }
}
