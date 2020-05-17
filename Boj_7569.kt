//Main idea: 3차원 bfs
import java.util.*

fun main() {
    val arr = Array(100){Array(100){Array(100){0} } }
    val hArr = arrayOf(1,-1,0,0,0,0)
    val yArr = arrayOf(0,0,1,-1,0,0)
    val xArr = arrayOf(0,0,0,0,1,-1)
    val que = LinkedList<Tomato>()

    var st = StringTokenizer(readLine()!!," ").toList()

    val m = st[0].toString().toInt()
    val n = st[1].toString().toInt()
    val h = st[2].toString().toInt()
    var cnt = 0
    var day = 0

    for(floor in 0 until h){
        for(y in 0 until n){
            st = StringTokenizer(readLine()!!," ").toList()
            for(x in 0 until m) {
                arr[floor][y][x] = st[x].toString().toInt() - 1
                if(arr[floor][y][x] == 0)
                    que.add(Tomato(floor,y,x))
                if(arr[floor][y][x] == -1)
                    cnt++
            }
        }
    }
    while (que.isNotEmpty() && cnt != 0) {
        val tom = que.first()
        que.removeAt(0)
        val f = tom.floor
        val y = tom.y
        val x = tom.x
        for (i in 0..5) {
            val nf = f + hArr[i]
            val ny = y + yArr[i]
            val nx = x + xArr[i]
            if (nf < 0 || ny < 0 || nx < 0 || nf >= h || ny >= n || nx >= m) continue
            if (arr[nf][ny][nx] == -1) {
                arr[nf][ny][nx] = arr[f][y][x] + 1
                day = arr[nf][ny][nx]
                que.add(Tomato(nf, ny, nx))
                cnt--
            }
        }
    }
    if(cnt != 0)
        println(-1)
    else
        println(day)
}
class Tomato(var floor :Int, var y:Int, var x:Int){
}
