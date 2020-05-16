//Main idea: 1.String tokenizer를 이용한 것을 바로 list로 전환 가능 2. list를 , 등으로 분류한 string으로 변환가능
import java.util.*

fun main() {
    for(i in 1..readLine()?.toInt()!!) {
        var op = readLine()!!
        var sz = readLine()!!.toInt()
        var list = StringTokenizer(readLine()!!, "[],").toList().toMutableList()
        var isReversed = false
        var error = false
        for (i in op!!) {
            if (i == 'R')
                isReversed = !isReversed
            else if (list.size == 0) {
                error = true
                break
            } 
            else {
                if (isReversed) list.removeAt(list.lastIndex)
                else list.removeAt(0)
            }
        }
        if (error)
            println("error")
        else
            println((if (isReversed) list.reversed() else list).joinToString(",", "[", "]"))
    }
}
