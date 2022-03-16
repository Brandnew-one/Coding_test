import Foundation

// 소수 판별
func isPrime(_ num: Int64) -> Bool {
    if num == 1 {
        return false
    } else {
        var i: Int64 = 2
        while true {
            if i * i > num {
                break
            }
            if num % i == 0 {
                return false
            }
            i += 1
        }
    }
    return true
}

// k 진수로 변환
func makeKDigit(_ n: Int, _ k: Int) -> String {
    let kNumber = String(n, radix: k)
    // print(kNumber)
    return kNumber
}

func solution(_ n:Int, _ k:Int) -> Int {
    var answer = 0
    var kNumber = makeKDigit(n, k)
    let splitKNumber = kNumber.components(separatedBy: "0")
    for str in splitKNumber {
        if isPrime(Int64(str) ?? Int64(1)) {
            answer += 1
        }
    }
    return answer
}
