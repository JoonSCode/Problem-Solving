//
//  LeetCode - Divide Two Integers.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2021/12/26.
//

import Foundation

class Solution {
    //Problem:
    
    func divide(_ dividend: Int, _ divisor: Int) -> Int {

        var answerIsPositive: Bool = true
        
        if dividend.signum() != divisor.signum() {
            answerIsPositive = false
        }
        
        let dividend = dividend * dividend.signum()
        let divisor = divisor * divisor.signum()
        
        var shiftCount = 0
        var sum = divisor
        var answer = 0
        
        guard dividend != 0, dividend >= divisor
        else {
            return answer
        }
        
        let maxAnswer = Int(Int32.max)
        let minAnswer = Int(Int32.min)
        
        while dividend > sum, shiftCount <= 32 {
            sum = sum << 1
            shiftCount += 1
            print("shiftCount: \(shiftCount), sum: \(sum)")
        }
        
        if dividend != sum  {
            sum = sum >> 1
            shiftCount -= 1
            answer = Int(pow(2.0, Double(shiftCount))) + divide(dividend - sum, divisor)
        } else {
            answer = Int(pow(2.0, Double(shiftCount)))
        }
        
        answer = answerIsPositive ? min(answer, maxAnswer) : max(minAnswer, -answer)
        
        return answer
    }
}
