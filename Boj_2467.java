//Main idea: 삼분탐색
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int numOfLiquid, answer;
	private static int[] answerArr = new int[2];
	private static ArrayList<Integer> liquids;

	public static void main(String[] args) throws IOException {
		liquid();
	}

	private static void liquid() throws NumberFormatException, IOException {
		input();
		run();
		System.out.println(answerArr[0] +" " + answerArr[1]);
	}

	private static void input() throws IOException {
		numOfLiquid = Integer.parseInt(in.readLine());
		st = new StringTokenizer(in.readLine()," ");
		liquids = new ArrayList<Integer>();
		answer = (int)2e31-1;
		for (int i = 0; i < numOfLiquid; i++) 
			liquids.add(Integer.parseInt(st.nextToken()));
		Collections.sort(liquids);
	}

	private static void run() {
		for (int i = 0; i < numOfLiquid-1; i++) 
			ts(i+1, numOfLiquid-1, liquids.get(i));
	}
	
	private static void ts(int start, int end, int num) {
		int p1 = (start*2 +end)/3;//3분할 지점들
		int p2 = ((start+end*2))/3;
		
		int l1 = Math.abs(liquids.get(p1) + num);//3분할 지점들에서의 함수 값
		int l2 = Math.abs(liquids.get(p2) + num);
		
		if(start + 3 > end) {//더이상 삼분탐색 진행이 어려울 경우 남은 범위를 모두 연산하여 값을 도출한다.
			for(int i = start; i <= end; i++) {
				int tmp = Math.abs(liquids.get(i) + num);
				if(answer > tmp) {
					answer = tmp;
					answerArr[0] = num;
					answerArr[1] = liquids.get(i);
				}
			}
			return;
		}
		
		if(l1 > l2)
			 ts(p1, end, num);
		else if(l1 < l2)
			 ts(start, p2,  num);
		else
			 ts(p1, p2, num);
	}
}
