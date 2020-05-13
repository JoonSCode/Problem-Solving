import java.util.*

fun main() = with(Scanner(System.`in`)){
    var N = nextInt()
    var list = mutableListOf<Int>()
    for(i in 0 until N) {
        var num = nextInt()
        list.add(num)
    }
    stack(list,N)
}
fun stack(list : MutableList<Int>, N : Int){
    var idx = 0
    var num = 1
    var ans = mutableListOf<Char>()
    var st = mutableListOf<Int>()

    while(num <= N || st.isNotEmpty()){
        while(st.isNotEmpty() && list[idx] == st[st.lastIndex]) {
            st.removeAt(st.lastIndex)
            ans.add('-')
            idx++
        }
        if(st.isNotEmpty() && list[idx] < st[st.lastIndex]){
            println("NO")
            return
        }
        else if(num <= N){
            ans.add('+')
            st.add(num)
            num++
        }
    }
    for(ch in ans)
        println(ch)
}
