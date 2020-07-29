//Main idea: 사방탐색 응용
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;

	private static int[][] paper = new int[101][101];
	private static int[] dy = {0,0,-1,1}, dx = {1,-1,0,0};
	public static void main(String[] args) throws IOException {
		alphabet();
	}

	private static void alphabet() throws IOException {
		int numOfPaper = Integer.parseInt(in.readLine());
		int answer = 0;
		for(int i = 0; i < numOfPaper; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			int y = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			for(int a = y; a < y + 10; a++) {
				for(int b = x; b < x + 10; b++)
					paper[a][b] = 1;
			}
		}
		for(int y = 1; y < 101; y++) {
			for(int x = 1; x < 101; x++) {
				if(paper[y][x] == 1) answer += getNumOfborder(y, x);
			}
		}
		System.out.println(answer);
	}
	
	private static int getNumOfborder(int y, int x) {
		int sz = 101;
		int answer = 0;
		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(!isInBoundary(ny, nx, sz)) continue;
			if(paper[ny][nx] == 0) answer++;
		}
		return answer;
	}
	private static boolean isInBoundary(int y, int x, int sz) {
		if(y < 0 || x < 0 || y >= sz || x >= sz) return false;
		return true;
	}
}
