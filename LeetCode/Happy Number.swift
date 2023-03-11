//
//  Happy Number.swift
//  Problem-Solving
//
//  Created by eden on 2023/03/11.
//

import Foundation

class Solution {
    var processResults: [Int: Int] = [:]

    func isHappy(_ n: Int) -> Bool {
        var number = n
        processResults[number] = 1

        while number != 1 {
            number = process(number)
            guard !isLooped(number)
            else {
                break
            }

            processResults[number] = 1
        }

        return number == 1
    }

    func isLooped(_ newResults: Int) -> Bool {
        return processResults[newResults] != nil
    }

    func process(_ number: Int) -> Int {
        var newNumber = 0
        var tmpNumber = number
        
        while tmpNumber != 0 {
            let digit = tmpNumber % 10
            tmpNumber /= 10
            
            newNumber += digit * digit
        }

        return newNumber
    }
}
