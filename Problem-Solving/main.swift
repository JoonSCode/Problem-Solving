//
//  main.swift
//  Problem-Solving
//
//  Created by eden.joon on 2021/10/20.
//

import Foundation

let sol = Solution()
//print(sol.generateParenthesis(3))
let a = ListNode(1, ListNode(4, ListNode(5)))
let b = ListNode(1, ListNode(3, ListNode(4)))
let c = ListNode(2, ListNode(6))

var ans = sol.mergeKLists([a,b,c])
while ans != nil {
    print(ans?.val)
    ans = ans?.next
}

