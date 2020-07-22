//Main idea: kmp 알고리즘 
fun main() {
    var st = readLine().toString()
    var idx = getMatchSuffixIdx(st)
    print(st.length+idx)

}
fun getMatchSuffixIdx(str : String) : Int {
    var reversedStr = str.reversed()
    for(s in str.indices){
        for(a in 0 until str.length-s){
            if(reversedStr[a] != str[s+a])
                break;
            if(a == str.length-s-1)
                return s
        }
    }
    return str.length
}
