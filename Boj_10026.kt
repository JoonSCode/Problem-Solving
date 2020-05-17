//Main idea: bfs
import java.util.*

fun main() {
    val paint = MutableList(100){ MutableList(100){'a'} }
    val xArr = arrayOf(0,0,1,-1)
    val yArr = arrayOf(1,-1,0,0)
    val size = readLine()!!.toInt()
    for(i in 0 until size) {
        val str = readLine().toString()
        for (x in 0 until size)
            paint[i][x] = str[x]
    }
    var normalCnt = 0
    var cnt = 0
    val list = LinkedList<Point>()
    fun bfs1(){
        while(list.isNotEmpty()){//대문자를 소문자로바꿈
            val y = list[0].y
            val x = list[0].x
            val color = paint[y][x].toUpperCase()
            list.removeAt(0)
            for(i in 0..3){
                val nx = x + xArr[i]
                val ny = y + yArr[i]
                if(nx<0 ||ny<0||nx>=size ||ny>=size) continue
                if(paint[ny][nx] == color){
                    paint[ny][nx] = color.toLowerCase()
                    list.add(Point(ny,nx))
                }
            }
        }
    }
    fun bfs2(){//소문자를 대문자로 바꿈
        while(list.isNotEmpty()){
            val y = list[0].y
            val x = list[0].x
            val color = paint[y][x].toLowerCase()
            list.removeAt(0)
            for(i in 0..3) {
                val nx = x + xArr[i]
                val ny = y + yArr[i]
                if (nx < 0 || ny < 0 || nx >= size || ny >= size) continue
                if ((color != 'b' && (paint[ny][nx] == 'r' || paint[ny][nx] == 'g')) || (paint[ny][nx] == color)) {
                    paint[ny][nx] = color.toUpperCase()
                    list.add(Point(ny, nx))
                }
            }
        }
    }
    for(y in 0 until size){
        for(x in 0 until size){
            if(paint[y][x].isUpperCase()){
                normalCnt++
                paint[y][x] = paint[y][x].toLowerCase()
                list.add(Point(y,x))
                bfs1()
            }
        }
    }
    for(y in 0 until size){
        for(x in 0 until size){
            if(paint[y][x].isLowerCase()){
                cnt++
                paint[y][x] = paint[y][x].toUpperCase()
                list.add(Point(y,x))
                bfs2()
            }
        }
    }
    println("$normalCnt $cnt")
}
class Point(var y: Int = 0,var x: Int = 0)
