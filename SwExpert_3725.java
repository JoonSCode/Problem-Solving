//Main idea: 
import java.io.*;
import java.util.*;


public class Solution {

	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int N;
	private static int[] points;
	private static boolean[] isVisited;
	private static int ans, sum;
	public static void main(String[] args) throws NumberFormatException, IOException {
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; i++) {
			out.write("#" + (i + 1) + " ");
			test();
			out.newLine();
		}
		out.flush();
		out.close();
	}

	private static void test() throws IOException {
		init();
		isVisited[0] = true;
		run(0);
		out.write(String.valueOf(ans));
	}

	private static void init() throws IOException {
		N = Integer.parseInt(in.readLine());
		points = new int[N];
		ans = 0;
		sum = 0;
		st = new StringTokenizer(in.readLine()," ");
	
		for(int i = 0; i < N; i++) {
			points[i] = Integer.parseInt(st.nextToken());
			sum += points[i];
		}
		isVisited = new boolean[sum+1];
	}
	
	private static void run(int idx) {
		if(idx >= N) {
			for(int i = 0; i <= sum; i++) {
				if(!isVisited[i]) continue;
				ans++;
			}
			return;
		}
		for(int i = sum-1; i >= 0; i--) {
			if(!isVisited[i]) continue;
			isVisited[i + points[idx]] = true;
		}
		run(idx+1);
	}
}
