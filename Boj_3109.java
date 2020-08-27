//Main idea: 백트래킹 dfs
import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	private static int height, width, answer;
	private static char[][] map;
	private static int[] dy = { -1, 0, 1 };
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		init();
		run();
		System.out.println(answer);
	}

	private static void init() throws NumberFormatException, IOException {
		st = new StringTokenizer(in.readLine(), " ");
		height = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		answer = 0;
		map = new char[height][width];
		for (int y = 0; y < height; y++)
			map[y] = in.readLine().toCharArray();
	}

	private static void run() {
		for (int y = 0; y < height; y++) {
			if (map[y][1] != 'x') 
				dfs(y, 1);
		}
	}

	private static boolean dfs(int y, int x) {
		if (x == width - 1) {
			answer++;
			map[y][x] = 'x';
			return true;
		}
		for (int i = 0; i < 3; i++) {
			int ny = y + dy[i];
			int nx = x + 1;
			if (!canMove(ny, nx))
				continue;
			if (dfs(ny, nx)) {
				map[y][x] = 'x';
				return true;
			}
		}
		map[y][x] = 'x';
		return false;
	}

	private static boolean canMove(int y, int x) {
		return (isInBoundary(y, x) && map[y][x] == '.') ? true : false;
	}

	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= height || x >= width) ? false : true;
	}
}
