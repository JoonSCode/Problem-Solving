//Main idea: 플로이드 와셜 알고리즘 순서 중요!! for문은 k->i->j 뜻은 i->k로 갈 경로 있고 k-j있으면 i -> j 갱신
import java.lang.Integer.min
import java.util.*

fun main() {
    var st = StringTokenizer(readLine()!!," ")
    var num = st.nextToken().toInt()
    var arr = Array(100){Array(100){100} }
    for(i in 1..st.nextToken().toInt()) {
        st = StringTokenizer(readLine()!!," ")
        var num1 = st.nextToken().toInt()
        var num2 = st.nextToken().toInt()
        arr[num1-1][num2-1] = 1
        arr[num2-1][num1-1] = 1
    }
    for(k in 0 until num){
        for(i in 0 until num) {
            if(i == k) continue
            for(j in 0 until num){
                if(j == k || j == i) continue
                if(arr[i][k] != 100 && arr[k][j] != 100)
                    arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j])
            }
        }
    }
    var ans = 100
    var person = -1
    for(y in 0 until num){
        var tmp = 0
        for(x in 0 until num) {
            if(y == x) continue
            tmp += arr[y][x]
        }
        if(ans > tmp){
            ans = tmp
            person = y
        }
    }
    println(person+1)
}
