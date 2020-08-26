//Main idea: dp
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int height, width, answer;
	private static int[][] map, cache;
	private static int[] dy = { 0, 0, -1, 1 }, dx = { 1, -1, 0, 0 };

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		cache[height-1][width-1] = 1;
		System.out.println(dp(0,0));
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		height = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		map = new int[height][width];
		cache = new int[height][width];
		answer = 0;
		for (int y = 0; y < height; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int x = 0; x < width; x++) {
				map[y][x] = Integer.parseInt(st.nextToken());
				cache[y][x] = -1;
			}
		}
	}

	private static int dp(int y, int x) {
		if(cache[y][x] != -1)
			return cache[y][x];
		int val = map[y][x];
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!isInBoundary(ny, nx) || map[ny][nx] >= val) continue;
			sum += dp(ny,nx);
		}
		return cache[y][x] = sum;
	}

	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= height || x >= width) ? false : true;
	}
}
