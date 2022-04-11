//
//  LeetCode - Remove Nth Node From End of List.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2021/12/20.
//

import Foundation

class Solution {
    
    //Problem linkedList 순차 탐색을 구현 가능한가(개념에 대한 이해를 하고 있는가)
    // 내가 풀려는 방식: 순차 탐색후 사이즈 알고 다시 앞에서 뒤로 탐색, 좀더 옵티멀 하게 하려면 갯 수 새고 doubly linkedList로 바꿔서 뒤에서 탐색해도 될 듯.
    
    // First Sol
    
//    var sizeOfList = 0
//
//    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
//
//        getSizeOfList(head)
//
//        let nodeToDelete = sizeOfList - n
//
//        switch nodeToDelete {
//        case 0:
//            return head?.next
//        case 1:
//            head?.next = head?.next?.next
//        default:
//            var node = head
//
//            for _ in 2...sizeOfList - n {
//                node = node?.next
//            }
//
//            node?.next = node?.next?.next
//        }
//
//        return head
//    }
//
//    func getSizeOfList(_ head: ListNode?) {
//        var node = head
//        while node != nil {
//            sizeOfList += 1
//            node = node?.next
//        }
//    }
    
    
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        let start: ListNode? = ListNode(0, head)
        var nodeBeforeDelete = start
        var tail = start
        
        for _ in 0 ... n {
            tail = tail?.next
        }
        
        while tail != nil {
            nodeBeforeDelete = nodeBeforeDelete?.next
            tail = tail?.next
        }
        
        nodeBeforeDelete?.next = nodeBeforeDelete?.next?.next
        return start?.next
    }
}

class ListNode {
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
