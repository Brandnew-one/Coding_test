import Foundation

func findN(_ ref: Int, _ times: [Int]) -> Int {
    var n = 0
    for i in 0..<times.count {
        n += ref / times[i]
    }
    return n
}

func solution(_ n:Int, _ times:[Int]) -> Int64 {
    var start = 1
    var end = times.max()! * n
    var answer = end, mid = 0
    
    while start <= end {
        var mid = (start + end) / 2
        var temp = findN(mid, times)
        
        if temp < n {
            start = mid + 1
        } else {
            if mid <= answer {
                answer = mid
            }
            end = mid - 1
        }
    }
    
    return Int64(answer)
}