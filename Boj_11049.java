//Main idea: 행렬의 곱은 항상 두개의 행렬끼리 곱하는 것이다.
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

	private static int[][] matrix;
	private static int[][] cache;
	private static int numOfMatrix;
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		init();
		run();
		System.out.println(sb.toString());
	}

	private static void init() throws IOException {
		numOfMatrix = Integer.parseInt(in.readLine());
		matrix = new int[numOfMatrix][2];
		cache = new int[numOfMatrix][numOfMatrix];

		for (int y = 0; y < numOfMatrix; y++) {
			st = new StringTokenizer(in.readLine()," ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			matrix[y] = (new int[] {a,b});
		}
		for(int y = 0;y < numOfMatrix; y++) {
			for(int x = 0; x < numOfMatrix; x++) {
				cache[y][x] = -1;
				if(y == x) cache[y][x] = 0;
			}
		}
	}
	
	private static void run() {
		sb.append(dp(0,numOfMatrix-1));
	}
	
	private static int dp(int s, int e) {
		//System.out.println("s: " + s  +"\te: " + e);
		if(cache[s][e] != -1) return cache[s][e];
		if(s + 1 == e) return cache[s][e] = mulMatrix(matrix[s], matrix[e]);
		int min = (int) (2e31-1);
		for(int i  = s; i < e; i++) {
			int tmp = dp(s,i) + dp(i+1,e) + matrix[s][0] * matrix[i][1] * matrix[e][1];		
			min = Math.min(min, tmp);
		}
		//System.out.println("s:"  +s  +"\te: " + e +  "\tans: "  + min);
		return cache[s][e] = min;		
	}
	
	private static int mulMatrix(int[] a, int []b) {
		return a[0] *a[1]*b[1];
	}
}
