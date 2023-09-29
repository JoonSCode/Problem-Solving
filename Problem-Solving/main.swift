//
//  main.swift
//  Problem-Solving
//
//  Created by eden.joon on 2021/10/20.
//

import Foundation

let sol = Solution()
var testCases = [[2,3,1,1,4], [2,3,0,1,4], [2, 1]]
testCases.forEach({
    print(Solution().jump($0))
})

