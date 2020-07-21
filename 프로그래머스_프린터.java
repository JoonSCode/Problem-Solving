//Main idea: 자바로 다시 구현해 보는 것에 주안점을 둠. 
import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        LinkedList<Integer> list = new LinkedList<Integer>();
        for(int i = 0; i < priorities.length; i++)
            list.add(i);
        
        while(!list.isEmpty()){
            int now = list.get(0);
            Boolean isPrime = false;
            for(int a : list){
                if(priorities[a] > priorities[now]){
                    isPrime = true;     
                    break;
                }
            }
            if(!isPrime){
                answer++;
                list.removeFirst();
                if(now == location)
                    break;        
            }
            else{
                list.add(now);
                list.removeFirst();
            }
        }
        return answer;
    }
}
