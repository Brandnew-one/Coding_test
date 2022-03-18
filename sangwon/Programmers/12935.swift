// [프로그래머스] 제일 작은 수 제거하기 -> 프로그래머스 LV1, LV2 전부 다 풀어보기!

func solution(_ arr:[Int]) -> [Int] {
    var minValue = arr[0]
    var minIndex = 0
    
    for i in 0..<arr.count {
        if(arr[i] < minValue) {
            minValue = arr[i]
            minIndex = i
        }
    }
    
    var answer: [Int] = []
    for i in 0..<arr.count {
        if i == minIndex {
            continue
        }
        answer.append(arr[i])
    }
    
    if answer.isEmpty {
        return [-1]
    } else {
        return answer
    }
}