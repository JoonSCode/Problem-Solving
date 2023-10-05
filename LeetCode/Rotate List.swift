//
//  Rotate List.swift
//  Problem-Solving
//
//  Created by eden on 2023/10/05.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}

class Solution {
    func rotateRight(_ head: ListNode?, _ k: Int) -> ListNode? {
        guard let headNode = head else { return nil }
        
        var arr: [Int] = []
        var head: ListNode? = headNode
        while head != nil {
            arr.append(head!.val)
            head = head?.next
        }

        let totalCount = arr.count
        let rotate = k % arr.count
        arr.append(contentsOf: arr)
                   
        let answer: ListNode = ListNode()
        var now: ListNode? = answer

        for value in arr[totalCount - rotate..<(totalCount * 2 - rotate)] {
            now?.next = .init(value)
            now = now?.next
        }

        return answer.next
    }
}
//0 ,1 ,2 , 0, 1, 2

