//Main idea: dp
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int[] arr;
	private static int[][] cache;
	private static int lengthOfSequence, numOfQuestion;
	private static ArrayList<int[]> questions = new ArrayList<int[]>();
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		init();
		run();
		System.out.println(sb.toString());
	}

	private static void init() throws IOException {
		lengthOfSequence = Integer.parseInt(in.readLine());
		arr = new int[lengthOfSequence];
		cache = new int[lengthOfSequence][lengthOfSequence];
		st = new StringTokenizer(in.readLine(), " ");
		for(int i =0; i < lengthOfSequence; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		
		numOfQuestion = Integer.parseInt(in.readLine());
		for (int y = 0; y < numOfQuestion; y++) {
			st = new StringTokenizer(in.readLine()," ");
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			questions.add(new int[] {a,b});
		}
		for(int i = 0; i < lengthOfSequence; i++) 
			cache[i][i] = 1;		
	}
	
	private static void run() {
		for(int[] question :questions) {
			int s = question[0];
			int e = question[1];
			sb.append((dp(s,e) == 1)? 1 : 0);
			sb.append("\n");
		}
	}
	
	private static int dp(int s, int e) {
		if(cache[s][e] != 0) return cache[s][e];
		if(s + 1 == e) return cache[s][e] = (arr[s] == arr[e])? 1 : -1;
		if(arr[s] != arr[e]) return cache[s][e] = -1;
		return cache[s][e] = dp(s+1, e-1);		
	}
}
