//Main idea: Bottom up은 무조건 2가지 경우의 수 Top down은 1가지 경우의 수
import java.lang.Integer.min
import java.util.*

fun main(){
    val st = StringTokenizer(readLine()," ").toList()
    val a = st[0].toString().toInt()
    val b = st[1].toString().toInt()
    val map = mutableMapOf<Int,Int>()
    map[b] = 1
    for(idx in b downTo a){
        if(!map.containsKey(idx)) continue
        if(idx%2 == 0)
            map[idx/2] = if(map.containsKey(idx/2)) min(map[idx/2]!!, map[idx]!! + 1) else map[idx]!! + 1

        else if((idx-1)%10 == 0)
            map[(idx-1)/10] = if(map.containsKey((idx-1)/10)) min(map[(idx-1)/10]!!, map[idx]!! + 1) else map[idx]!! + 1
    }
    println(if(map.containsKey(a)) map[a] else -1)
}
