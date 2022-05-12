//
//  main.swift
//  Problem-Solving
//
//  Created by eden.joon on 2021/10/20.
//

import Foundation

let sol = Solution()
var arr = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
sol.rotate(&arr)
arr.forEach({
    print($0)
})
//print()
