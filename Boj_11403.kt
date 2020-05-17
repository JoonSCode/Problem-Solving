//Main idea: 사이클도 측정하는 플로이드 워셜
import java.util.*

fun main() {
    var numOfVertex = readLine()!!.toInt()
    var arr = Array(numOfVertex){Array(numOfVertex){0} }
    for(i in 0 until numOfVertex){
        val str = StringTokenizer(readLine(), " ").toList()
        for(x in 0 until numOfVertex)
            arr[i][x] = str[x].toString().toInt()
    }
    for(k in 0 until numOfVertex){
        for(i in 0 until numOfVertex){
            for(j in 0 until numOfVertex){
                if(arr[i][k] == 1 && arr[k][j] == 1)
                    arr[i][j] = 1
            }
        }
    }
    for(y in 0 until numOfVertex)
        println(arr[y].joinToString(" "))
}
