//
//  First Bad Version.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/12/02.
//

import Foundation

class Solution: VersionControl {
    func firstBadVersion(_ n: Int) -> Int {
        var start = 0
        var end = n

        while start <= end {
            let mid = (start + end) / 2
            if isBadVersion(mid) {
                end =  mid - 1
            } else {
                start = mid + 1
            }
        }

        return max(start, end)
    }
}
