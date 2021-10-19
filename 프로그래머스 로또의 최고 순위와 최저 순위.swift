import Foundation

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var count = 0
    var zeroCount = 0

    for value in lottos {
        guard value != 0
        else {
            zeroCount += 1
            continue
        }

        if win_nums.contains(value) {
            count -= 1
        }
    }

    let maxRating = min(count - zeroCount + 7, 6)
    let minRating = min(count + 7, 6)

    return [maxRating, minRating]
}
