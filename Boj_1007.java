//Main idea: 벡터들의 길이는 점 중에 절반은 좌표를 더하고 절반은 좌표를 뺀 값들을 가지고 구한 길이
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int numOfDot;
	private static long[][] coordinateOfDots;
	private static boolean[] isUsed;
	private static double answer;

	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; i++)
			test();
		System.out.println(sb.toString());
	}

	private static void test() throws IOException {
		input();
		search(0,0);
		sb.append(answer);
		sb.append("\n");
	}

	private static void input() throws IOException {
		numOfDot = Integer.parseInt(in.readLine());
		coordinateOfDots = new long[numOfDot][2];
		isUsed = new boolean[numOfDot];
		answer = 987654321;
		for (int i = 0; i < numOfDot; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			int y = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			coordinateOfDots[i] = new long[] { y, x };
		}
	}


	private static void search(int idx, int cnt) {
		if(cnt == numOfDot/2) {
			long sx = 0, sy = 0;
			for(int i = 0; i < numOfDot; i++) {
				if(isUsed[i]) {
					sy += coordinateOfDots[i][0];
					sx += coordinateOfDots[i][1];
				}
				else {
					sy -= coordinateOfDots[i][0];
					sx -= coordinateOfDots[i][1];		
				}
			}
			double len = Math.sqrt(sx*sx + sy*sy); 
			answer = Math.min(answer, len);
			return;
		}
    
		if(idx == numOfDot) return;
		for(int i = idx; i < numOfDot; i++) {
			if(isUsed[i]) continue;
			isUsed[i] = true;
			search(i+1, cnt + 1);
			isUsed[i] = false;
		}
	}
}
