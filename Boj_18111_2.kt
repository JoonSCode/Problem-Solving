//Main idea: kotlin자체 readline보다 BufferedReader가 더 빠르다.
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.lang.Integer.min
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var st = StringTokenizer(readLine())
    var N = st.nextToken().toInt()
    var M = st.nextToken().toInt()
    var B = st.nextToken().toInt()

    var answer = Int.MAX_VALUE
    var maxHeight = 0
    var arr = Array(257){0}
    var minHeight = 257
    for(y in 0 until N) {
        st = StringTokenizer(readLine())
        for(x in 0 until M) {
            var tmp = st.nextToken().toInt()
            arr[tmp]++
            B += tmp
            minHeight = min(minHeight, tmp)
        }
    }
    B /= (M*N)
    for(i in min(256,B) downTo minHeight){
        var tmp = 0
        for (idx in 0..256) {
            tmp += if (idx > i) (idx - i) * 2 * arr[idx] else (i - idx) * arr[idx]
            if(tmp >= answer)
                break
        }
        if (answer <= tmp) continue
        answer = tmp
        maxHeight = i
    }
    println("$answer $maxHeight")
}
