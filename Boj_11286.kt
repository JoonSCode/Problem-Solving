//Main idea: 코틀린 힙 사용법
import java.lang.Math.abs
import java.util.*

fun main() {
    val heap = PriorityQueue<Int>{ a, b -> if(abs(a) == abs(b)) a - b else abs(a)-abs(b)}//코틀린에서는 이렇게 비교 연산자 사용 가능!
    for(q in 1..readLine()!!.toInt()) {
        val num = readLine()!!.toInt()
        if(num == 0) {
            if(heap.size == 0)
                println(0)
            else {
                println(heap.peek())
                heap.remove(heap.peek())
            }
        }
        else heap.add(num)
    }
}
