//Main idea: BFS 사용하되 중복 처리 중요!!
import java.lang.Integer.min
import java.util.*

fun main() {
    var st = StringTokenizer(readLine(), " ").toList()
    var subin = st[0].toString().toInt()
    var sis = st[1].toString().toInt()
    if (subin >= sis) {
        println(subin - sis)
        println(1)
        return
    }
    var arr= Array(100001){Point()}

    var list = LinkedList<Int>()
    list.add(subin)
    arr[subin] = Point(0,1)
    while(list.isNotEmpty()) {
        var i = list.first
        list.removeFirst()
        if(arr[sis].value != -1 && arr[sis].value <= arr[i].value) break
        var tmp = arrayOf(i-1,i+1,i*2)
        for(num in tmp) {
            if(num > 100000) break
            if(num < 0) continue
            if (arr[num].value == -1 || arr[num].value > arr[i].value + 1) {
                arr[num] = Point(arr[i].value + 1, arr[i].cnt, hashSetOf(i))
                list.add(num)
            } else if (arr[num].value == arr[i].value + 1) {
                if(i != 1 && arr[num].set.contains(i)) continue//i값이 같은 value를 가진채로 한번 더 오는 경우 체크
                arr[num].cnt+= arr[i].cnt
                arr[num].set.add(i)
            }
        }
    }
    println(arr[sis].value)
    println(arr[sis].cnt)
}
class Point(var value : Int = -1, var cnt:Int = 0, var set: HashSet<Int> = hashSetOf<Int>())
