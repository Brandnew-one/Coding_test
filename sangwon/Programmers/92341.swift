// [프로그래머스] 주차 요금 계산
import Foundation

typealias SplitType = (String, String, String)

var map: [String: Int] = [:] // 자동차별 분단위 시간을 저장할 딕셔너리
var inOut: [String: String] = [:] // 자동차별 입/출차 시간을 저장할 딕셔너리

// 문자열을 시간, 차, 입/출차 기준으로 나눠주는 함수
func splitString(_ record: String) -> SplitType {
    let splitRecord = record.components(separatedBy: " ")
    let time = splitRecord[0]
    let car = splitRecord[1]
    let mode = splitRecord[2]
    return (time, car, mode)
}

//해시맵을 초기화 해주는 함수
func setHashMap(_ records:[String]) {
    for record in records {
        let s = splitString(record)
        map[s.1] = 0
//        inOut[s.1] = ""
    }
}

//입, 출차 시간을 기준으로 분단위 시간을 계산하는 함수
func calTime(_ inTime: String, _ outTime: String) -> Int {
    let splitIn = inTime.components(separatedBy: ":")
    let splitOut = outTime.components(separatedBy: ":")
    let inH = Int(splitIn[0])!
    let inM = Int(splitIn[1])!
    let outH = Int(splitOut[0])!
    let outM = Int(splitOut[1])!
    let time = (outH - inH) * 60 + (outM - inM)
    return time
}

// 분단위 시간을 기준으로 요금을 계산하는 함수
func calMoney(_ time: Int, _ fees: [Int]) -> Int {
    if time <= fees[0] {
        return fees[1]
    } else {
        let remainTime = time - fees[0]
        var unitTimes = remainTime / fees[2]
        if remainTime % fees[2] != 0 {
            unitTimes += 1
        }
        return (unitTimes * fees[3]) + fees[1]
    }
}

func solution(_ fees:[Int], _ records:[String]) -> [Int] {
    setHashMap(records)
    for record in records {
        let s: SplitType = splitString(record)
        if s.2 == "IN" {
            inOut[s.1] = s.0 // 입차하는 경우에는 시간을 넣어주기만 하면 된다.
        } else {
            map[s.1]! += calTime(inOut[s.1]!, s.0) // 츌차하는 경우 기존 입차시간과의 차를 통해 갱신
            inOut[s.1] = ""
        }
    }
    
    // 다 돌고 난 이후에 출차하지 않은 경우에는 23:59을 기준으로 출차를 시켜준다.
    for e in inOut {
        if e.value != "" { // 출차되지 않은 경우
            map[e.key]! += calTime(e.value, "23:59")
            inOut[e.key] = ""
        }
    }
    
    let keySortedDict = map.sorted(by: {$0.0 < $1.0}) // sort 함수의 시간복잡도는 보장되겠지??
    var answer: [Int] = []
    for key in keySortedDict {
        answer.append(calMoney(key.value, fees))
    }
    
    return answer
}
