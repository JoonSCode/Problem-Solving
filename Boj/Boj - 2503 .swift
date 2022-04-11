//
//  Boj - 2503.swift
//  Problem-Solving
//
//  Created by 윤준수 on 2022/01/05.
//

import Foundation

func boj2503() {
    
    var candidates = Array(repeating: [1,2,3,4,5,6,7,8,9], count: 3)
    var numOfQuestion = 0
    var questionAnswers: [(String, Int, Int)] = []
    
    func input() {
        numOfQuestion = Int(readLine()!)!
        
        (1...numOfQuestion).forEach({ _ in
            let input = readLine()!.split(separator: " ").map({
                String($0)
            })
            questionAnswers.append((input[0], Int(input[1])!, Int(input[2])!))
        })
        
    }
    
    
    func solve() {
        
    }
}
