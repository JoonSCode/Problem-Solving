//Main idea: x를 고정시키고 y를 m만큼 증가시킨다.
import java.util.*

fun main() {
    for(i in 1..readLine()!!.toInt()){
        val st = StringTokenizer(readLine(), " ").toList()
        var m = st[0].toString().toInt()
        var n = st[1].toString().toInt()
        var x = st[2].toString().toInt()
        var y = st[3].toString().toInt()
        var day = x
        var sx = x
        var sy = if(x%n == 0) n else x % n

        while(y != sy) {
            if (day > m * n) {
                day = -1
                break
            }
            day += m
            sy += m
            sy = if(sy % n == 0) n else sy % n
        }
        println(day)
    }
}
