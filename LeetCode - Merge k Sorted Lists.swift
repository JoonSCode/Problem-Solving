//
//  LeetCode - Merge k Sorted Lists.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2021/12/22.
//

import Foundation

class Solution {
//        func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
//            let answer: ListNode = ListNode()
//
//            guard !lists.isEmpty else { return nil }
//
//            var minValueListIndex = -1
//            var lists = lists
//            var listNow: ListNode? = answer
//            while true {
//                var minValue = 100000
//                minValueListIndex = -1
//                for (index, list) in lists.enumerated() {
//                    if let val = list?.val, minValue > val {
//                        minValue = val
//                        minValueListIndex = index
//                    }
//                }
//
//                if minValueListIndex == -1 {
//                    break
//                }
//
//                let minList = lists[minValueListIndex]
//                listNow?.next = minList
//                listNow = minList
//                lists[minValueListIndex] = minList?.next
//            }
//
//            return answer.next
//        }
//
//        func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
//            let answer: ListNode = ListNode()
//
//            guard !lists.isEmpty else { return nil }
//
//            var values: [Int] = []
//            lists.forEach({
//                var tmp = $0
//                while tmp != nil {
//                    values.append(tmp!.val)
//                    tmp = tmp?.next
//                }
//            })
//            values.sort()
//            var now: ListNode? = answer
//            values.forEach({
//                now?.next = ListNode($0)
//                now = now?.next
//            })
//
//            return answer.next
//        }
    
    func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
        guard !lists.isEmpty else { return nil }

        var values: [ListNode] = []
        lists.forEach({
            var tmp = $0
            while tmp != nil {
                values.append(tmp!)
                tmp = tmp?.next
            }
        })
        values.sort()

        let answer: ListNode = ListNode()
        var now = answer
        for node in values {
            now.next = node
            now = node
        }

        return answer.next
    }
    
    
//    func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
//        guard !lists.isEmpty else { return nil }
//
//        let answer: ListNode = ListNode()
//        var now = answer
//
//        var minIndex = -1
//        var lists = lists
//        while true {
//            minIndex = -1
//            var minListNode = ListNode(1000000)
//            for (index, list) in lists.enumerated() {
//                guard let list = list else { continue}
//                if minListNode > list {
//                    minListNode = list
//                    minIndex = index
//                }
//            }
//
//            guard minIndex != -1 else { break }
//
//            now.next = minListNode
//            now = minListNode
//            lists[minIndex] = minListNode.next
//        }
//
//        return answer.next
//    }
    
}

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}

extension ListNode: Comparable {
    public static func < (lhs: ListNode, rhs: ListNode) -> Bool {
        lhs.val < rhs.val
    }
    
    public static func == (lhs: ListNode, rhs: ListNode) -> Bool {
        lhs.val == rhs.val
    }
}
