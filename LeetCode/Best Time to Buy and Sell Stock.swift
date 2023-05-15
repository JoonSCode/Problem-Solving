//
//  Best Time to Buy and Sell Stock.swift
//  Problem-Solving
//
//  Created by eden on 2023/05/15.
//

import Foundation

class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var profit = 0
        var buy = prices[0]
        
        for price in prices {
            if buy > price {
                buy = price
            } else {
                profit = max(profit, price - buy)
            }
        }
        
        return profit
    }
}
