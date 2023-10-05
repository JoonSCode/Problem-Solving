//
//  main.swift
//  Problem-Solving
//
//  Created by eden.joon on 2021/10/20.
//

import Foundation

let sol = Solution()

var head = ListNode()
var now: ListNode? = head
[1,2,3,4,5].forEach({
    now?.next = .init($0)
    now = now?.next
})

print("__________________________________")
var answer = sol.rotateRight(head.next, 2)
while answer != nil {
    print(answer?.val)
    answer = answer?.next
}

