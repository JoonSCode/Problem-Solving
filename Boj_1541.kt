//Main idea: -가 한번이라도 나온 경우, 안나온 경우를 비교
import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    var str = readLine()
    var strNum = ""
    var ans = 0
    var isSub = false
    var op = '+'
    for(a in str){
        if(a == '+' || a == '-'){
            if(op == '+'){
                if(isSub)
                    ans -=strNum.toInt()
                else
                    ans += strNum.toInt()
            }
            else{
                isSub = true
                ans -= strNum.toInt()
            }
            op = a
            strNum = ""
        }
        else
            strNum += a
    }
    if(op == '+'){
        if(isSub)
            ans -=strNum.toInt()
        else
            ans += strNum.toInt()
    }
    else
        ans -= strNum.toInt()
    println(ans)
}
