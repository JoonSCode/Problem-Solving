//
//  Integer to Roman.swift
//  Problem-Solving
//
//  Created by eden on 2023/10/03.
//

import Foundation

// 23ms, 13.6MB
//class Solution {
//    func intToRoman(_ num: Int) -> String {
//        //동일한 숫자는 4번 나오면 안된다.
//        //4번 하지 않고 하나 높은 것에서 뺀다
//        var answer = ""
//        var num = num
//
//        while num != 0 {
//            if 1000 <= num {
//                let value = num / 1000
//                for _ in 0..<value {
//                    answer.append("M")
//                }
//
//                num %= 1000
//            } else if 500 <= num {
//                let value = num / 100
//                num %= 100
//                if value == 9 {
//                    answer.append("CM")
//                } else {
//                    answer.append("D")
//                    for _ in 5..<value {
//                        answer.append("C")
//                    }
//                }
//            }
//            else if 100 <= num {
//                let value = num / 100
//                num %= 100
//                if value == 4 {
//                    answer.append("CD")
//                } else {
//                    for _ in 0..<value {
//                        answer.append("C")
//                    }
//                }
//            } else if 50 <= num {
//                let value = num / 10
//                num %= 10
//                if value == 9 {
//                    answer.append("XC")
//                } else {
//                    answer.append("L")
//                    for _ in 5..<value {
//                        answer.append("X")
//                    }
//                }
//            } else if 10 <= num {
//                let value = num / 10
//                num %= 10
//                if value == 4 {
//                    answer.append("XL")
//                } else {
//                    for _ in 0..<value {
//                        answer.append("X")
//                    }
//                }
//            } else if 5 <= num {
//                if num == 9 {
//                    answer.append("IX")
//                } else {
//                    answer.append("V")
//                    for _ in 5..<num {
//                        answer.append("I")
//                    }
//                }
//                num %= 1
//            } else {
//                if num == 4 {
//                    answer.append("IV")
//                } else {
//                    for _ in 0..<num {
//                        answer.append("I")
//                    }
//                }
//
//                num %= 1
//            }
//        }
//
//        return answer
//    }
//}

// 17ms, 13.68MB
class Solution {
    func intToRoman(_ num: Int) -> String {
        var arr = [(1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"), (90, "XC"), (50, "L"), (40, "XL"), (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")]
        //동일한 숫자는 4번 나오면 안된다.
        //4번 하지 않고 하나 높은 것에서 뺀다
        var answer = ""
        var sum = 0
        
        for roman in arr {
            while num - sum >= roman.0 {
                answer.append(roman.1)
                sum += roman.0
            }
        }
        
        return answer
    }
}
