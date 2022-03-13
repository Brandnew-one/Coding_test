import Foundation

var countMap: [String: Int] = [:] // 닉네임 별 신고횟수를 저장할 딕셔너리
var map: [String: Set<String>] = [:] // 닉네임 별 신고한 id를 저장할 딕셔너리

func makeHashMap(_ id_list:[String], _ report:[String]) {
    for id in id_list {
        countMap[id] = 0
        map[id] = Set()
    }
    for str in report {
        let endIndex = str.index(before: str.endIndex)
        let splitIndex = str.index(after: str.firstIndex(of: " ")!)
        let fUser = String(str[str.startIndex..<str.firstIndex(of: " ")!])
        let sUser = String(str[splitIndex..<str.endIndex])
        // print(fUser, sUser)
        if !map[fUser]!.contains(sUser) {
            map[fUser]?.insert(sUser)
            countMap[sUser]! += 1
        }
        
    }
    // for (key, value) in map {
    //     print("key:", key, "value:", value)
    // }
}

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    makeHashMap(id_list, report)
    var answer: [Int] = []
    
    // for (key, value) in countMap {
    //     print("key:", key, "value", value)
    // }
    
    for id in id_list {
        var cnt = 0
        for str in map[id]! {
            if countMap[str]! >= k {
                cnt += 1
            }
        }
        answer.append(cnt)
    }
    return answer
}