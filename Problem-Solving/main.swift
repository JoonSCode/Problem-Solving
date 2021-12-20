//
//  main.swift
//  Problem-Solving
//
//  Created by eden.joon on 2021/10/20.
//

import Foundation

let sol = Solution()
//print(sol.isMatch("abcaaaaaaabaabcabac", ".*ab.a.*a*a*.*b*b*"))
//print(sol.isMatch("abcaaaaaaabaabcabac", ".*ab.a.*"))
//print(sol.isMatch("abcaaaaaaabaabcabac", ".*ab.a.*a*a*.*b*b*"))
//print(sol.isMatch("aab", "c*a*b"))
//print(sol.maxArea([4,3,2,1,4]))
//print(sol.threeSum([-1,0,1,2,-1,-4]))
//print(sol.threeSum([0,0]))
//print(sol.threeSum([]))
//sol.main()

var head = ListNode(1)
var tmpHead = head
for i in (2 ... 2) {
    tmpHead.next = ListNode(i)
    tmpHead = tmpHead.next!
}

var tmp: ListNode? = head
while tmp != nil {
    print(tmp?.val)
    tmp = tmp?.next
}

print("------------------------")

var ans = sol.removeNthFromEnd(head, 1)
while ans != nil {
    print(ans?.val)
    ans = ans?.next
}
