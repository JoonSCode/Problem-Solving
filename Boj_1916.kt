//Main idea: 다익스트라, 같은 경로 소모값 다른 버스 들어올 수 있음
import java.util.*

fun main() {
    val numOfCity = readLine()!!.toInt()
    val numOfBus = readLine()!!.toInt()
    val arr = Array(numOfCity){Array(numOfCity){-1} }
    for(i in 1..numOfBus){
        val st = StringTokenizer(readLine(), " ").toList()
        //새롭게 버스 지나는 경우 or 지금 경로보다 짧은 버스 들어오는 경우
        if(arr[st[0].toString().toInt() - 1][st[1].toString().toInt() - 1] == -1 || arr[st[0].toString().toInt() - 1][st[1].toString().toInt() - 1] > st[2].toString().toInt())
            arr[st[0].toString().toInt() - 1][st[1].toString().toInt() - 1] = st[2].toString().toInt()
    }
    val st = StringTokenizer(readLine(), " ").toList()
    val start = st[0].toString().toInt() - 1
    val dest = st[1].toString().toInt() - 1
    val pq = PriorityQueue<Vertex>{ a, b -> a.value - b.value}
    for(i in 0 until numOfCity){
        if(arr[start][i] != -1)
            pq.add(Vertex(i, arr[start][i]))
    }
    while(pq.isNotEmpty()){
        val idx = pq.first().idx
        val value = pq.first().value
        pq.remove(pq.first())
        if(idx == dest) break
        for(i in 0 until numOfCity){
            if(arr[idx][i] != -1 && (arr[start][i] == -1 || arr[idx][i] + value < arr[start][i])) {
                arr[start][i] = value + arr[idx][i]
                pq.add(Vertex(i, arr[start][i]))
            }
        }
    }
    println(arr[start][dest])
}
class Vertex(var idx : Int, var value : Int)
