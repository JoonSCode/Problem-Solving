//
//  Word Ladder.swift
//  Problem-Solving
//
//  Created by eden on 2023/10/05.
//

import Foundation

//1543ms, 19MB
//class Solution {
//    func ladderLength(_ beginWord: String, _ endWord: String, _ wordList: [String]) -> Int {
//        var candidates: [String] = [beginWord]
//        var wordPath: [String: [String]] = [:]
//        var isVisited: [String: Bool] = [:]
//
//        wordList.forEach({ word in
//            for i in 0..<word.count {
//                let newWord = String(word.prefix(i) + "*" + word.suffix(word.count - 1 - i))
//                wordPath[newWord, default: []].append(word)
//            }
//        })
//
//
//        var answer = 1
//        while !candidates.isEmpty {
//            answer += 1
//            var nextCandidates: [String] = []
//            for candidate in candidates {
//                isVisited[candidate, default: false] = true
//
//                for i in 0..<candidate.count {
//                    let newWord = String(candidate.prefix(i) + "*" + candidate.suffix(candidate.count - 1 - i))
//                    for nextWord in wordPath[newWord, default: []] {
//                        if nextWord == endWord {
//                            return answer
//                        } else if !isVisited[nextWord, default: false] {
//                            nextCandidates.append(nextWord)
//                        }
//                    }
//                }
//            }
//
//            candidates = nextCandidates
//        }
//
//        return 0
//    }
//}

//852ms, 19MB
//class Solution {
//    func ladderLength(_ beginWord: String, _ endWord: String, _ wordList: [String]) -> Int {
//        var candidates: [String] = [beginWord]
//        var wordPath: [String: [String]] = [:]
//        var isVisited: [String: Bool] = [:]
//        
//        wordList.forEach({ word in
//            for i in 0..<word.count {
//                let newWord = String(word.prefix(i) + "*" + word.suffix(word.count - 1 - i))
//                wordPath[newWord, default: []].append(word)
//            }
//        })
//        
//        print(wordPath)
//        
//        var answer = 1
//        while !candidates.isEmpty {
//            answer += 1
//            var nextCandidates: [String] = []
//            for candidate in candidates {
//                isVisited[candidate, default: false] = true
//                
//                for i in 0..<candidate.count {
//                    let newWord = String(candidate.prefix(i) + "*" + candidate.suffix(candidate.count - 1 - i))
//                    for nextWord in wordPath[newWord, default: []] {
//                        if nextWord == endWord {
//                            return answer
//                        } else if !isVisited[nextWord, default: false] {
//                            nextCandidates.append(nextWord)
//                        }
//                    }
//                }
//            }
//            
//            candidates = nextCandidates
//        }
//
//        return 0
//    }
//}

//137ms
class Solution {
    func ladderLength(_ beginWord: String, _ endWord: String, _ wordList: [String]) -> Int {
        var candidates: [String] = [beginWord]
        var wordPath: [String: [String]] = [:]
        var isVisited: [String: Bool] = [:]

        wordList.forEach({ word in
            for i in 0..<word.count {
                let newWord = String(word.prefix(i) + "*" + word.suffix(word.count - 1 - i))
                wordPath[newWord, default: []].append(word)
            }
        })

        var answer = 1
        isVisited[beginWord] = true
        while !candidates.isEmpty {
            answer += 1
            var nextCandidates: [String] = []
            for candidate in candidates {
                for i in 0..<candidate.count {
                    let newWord = String(candidate.prefix(i) + "*" + candidate.suffix(candidate.count - 1 - i))
                    for nextWord in wordPath[newWord, default: []] {
                        if nextWord == endWord {
                            return answer
                        } else if !isVisited[nextWord, default: false] {
                            isVisited[nextWord] = true
                            nextCandidates.append(nextWord)
                        }
                    }
                }
            }

            candidates = nextCandidates
        }

        return 0
    }
}
