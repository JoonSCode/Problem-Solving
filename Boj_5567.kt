//Main idea:플로이드 워셜 느낌
import java.util.*

fun main() {
    var numOfPeers = readLine()!!.toInt()
    var lengthOfList = readLine()!!.toInt()
    var list = Array(numOfPeers){Array(numOfPeers){0}}

    for(i in 0 until lengthOfList){
        var st = StringTokenizer(readLine(), " ").toList()
        var a = st[0].toString().toInt()-1
        var b = st[1].toString().toInt()-1
        list[a][b] = 1
        list[b][a] = 1
    }
    for(k in 0 until numOfPeers){
        if(list[0][k] != 1) continue
        for(j in 0 until numOfPeers){
            if(j == 0) continue
            if(list[0][j] == 0 && list[k][j] == 1)
                list[0][j] = 2
        }
    }
    var num =0
    for(i in 0 until numOfPeers)
        if(list[0][i] == 2 || list[0][i] == 1) num++

    print(num)
}
