//Main idea: 스택 활용
import java.util.*

fun main() = with(Scanner(System.`in`)){
    var str : String = nextLine()
    while(str.length != 1 || str[0] != '.'){
        stack(str)
        str = nextLine()
    }
}
fun stack(str : String){
    var list = mutableListOf<Char>()
    val op = listOf<Char>('(','{','[')
    val cl = listOf<Char>(')','}',']')
    for(ch in str) {
        if (op.contains(ch))//여는 괄호 인경우
            list.add(ch)
        else if(cl.contains(ch)){
            if(list.size == 0 || op[cl.indexOf(ch)] != list.last()) {//여는 괄호가 앞에 없는데 닫는 괄호 나온 경우, 이전 여는 괄호랑 다른 닫는 괄호인경우
                println("no")
                return
            }
            else
                list.removeAt(list.lastIndex)
        }
    }
    if(list.isNotEmpty())//여는 괄호가 남은 경우
        println("no")
    else
        println("yes")
}
