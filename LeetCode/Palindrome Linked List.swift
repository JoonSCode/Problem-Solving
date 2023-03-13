//
//  Palindrome Linked List.swift
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
    func isPalindrome(_ head: ListNode?) -> Bool {
        var values: [Int] = []
        var now = head
        
        while let tmp = now {
            values.append(tmp.val)
            now = tmp.next
        }
        
        var start = 0
        var end = values.count - 1
        
        while start <= end  {
            if values[start] != values[end] {
                return false
            }
            start += 1
            end -= 1
        }
        
        return true
    }
}
