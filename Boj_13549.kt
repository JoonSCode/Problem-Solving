//Main idea: Top down이 경우의 수가 더 적다.
import java.lang.Integer.min
import java.util.*

fun main() {
    var st = StringTokenizer(readLine(), " ").toList()
    var subin = st[0].toString().toInt()
    var sis = st[1].toString().toInt()
    if (subin >= sis) {
        println(subin - sis)
        return
    }
    var arr= Array(100001){-1}
    var list = LinkedList<Int>()
    list.add(sis)
    arr[sis] = 0
    while(list.isNotEmpty()) {
        var i = list.first
        list.removeFirst()
        if(i == subin)
            break
        var tmpArr = listOf(i+1, i-1)
        for(a in tmpArr){
            if(a < 0 || a > 100000) continue
            if(arr[a]== -1 || arr[a] > arr[i] + 1){
                arr[a] = arr[i] + 1
                list.add(a)
            }
        }
        if(i%2 == 0 && (arr[i/2] == -1 || arr[i/2] > arr[i])){
            arr[i/2] = arr[i]
            list.add(i/2)
        }
    }
    println(arr[subin])
}
