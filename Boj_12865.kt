//Main idea: backtracking 말고 dp사용
import java.lang.Integer.max
import java.util.*

fun main() {
    var st = StringTokenizer(readLine(), " ").toList()
    val numOfObject = st[0].toString().toInt()
    val affordableWeight = st[1].toString().toInt()
    val objectArray = Array(numOfObject){Object()}
    val dp = Array(100){Array(100001){-1} }

    for(i in 0 until numOfObject) {
        st = StringTokenizer(readLine(), " ").toList()
        objectArray[i] = Object(st[0].toString().toInt(),st[1].toString().toInt())
    }
    
    fun knapSack(idx : Int, weight: Int) : Int{
        if(idx == numOfObject) return 0
        if(dp[idx][weight] != -1) return dp[idx][weight]
        dp[idx][weight] = knapSack(idx+1, weight)
        if(weight-objectArray[idx].weight >=0)
            dp[idx][weight] = max(dp[idx][weight], knapSack(idx+1, weight-objectArray[idx].weight) + objectArray[idx].value)
        return dp[idx][weight]
    }
    
    knapSack(0,affordableWeight)
    println(dp[0][affordableWeight])
}
class Object(var weight : Int = 0, var value : Int = 0)
