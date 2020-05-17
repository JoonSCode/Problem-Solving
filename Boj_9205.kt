//Main idea: 플로이드 워셜 알고리즘 활용
import java.lang.Math.abs
import java.util.*

fun main() {
    for(q in 1..readLine()!!.toInt()) {
        var beer = 20
        val numOfConvenienceStore = readLine()!!.toInt()
        val pointList = mutableListOf<Coordinates>()
        for(i in 1..numOfConvenienceStore + 2){
            var st = StringTokenizer(readLine(), " ").toList()
            pointList.add(Coordinates(st[0].toString().toInt(), st[1].toString().toInt()))
        }
        var arr = Array(numOfConvenienceStore + 2){Array(numOfConvenienceStore+2){0} }
        for(i in 0 until numOfConvenienceStore + 2){
            for(j in 0 until numOfConvenienceStore + 2) {
                if (i == j || (pointList[i] - pointList[j]) > 1000) continue
                arr[i][j] = 1
                arr[j][i] = 1
            }
        }
        for(k in 0 until numOfConvenienceStore + 2){//플로이드 워셜 알고리즘
            for(i in 0 until numOfConvenienceStore + 2){
                if(i == k) continue
                for(j in 0 until numOfConvenienceStore + 2) {
                    if (j == i || j == k) continue
                    if(arr[i][k] == 1 && arr[k][j] == 1) arr[i][j] = 1
                }
            }
        }
        println(if(arr[0][numOfConvenienceStore + 1] == 1) "happy" else "sad")
    }
}
class Coordinates(var y: Int = 0, var x : Int = 0){
    operator fun minus(other: Coordinates) :Int {//연산자 오버로딩
        return kotlin.math.abs(x - other.x) + kotlin.math.abs(y - other.y)
    }
}
