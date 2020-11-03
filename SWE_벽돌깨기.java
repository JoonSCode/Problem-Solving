//Main idea: 벽돌을 shift 하는 과정이 모든 속도를 좌우한다.
import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		int T = Integer.parseInt(in.readLine());
		for (int i = 1; i <= T; i++) {
			test();
			sb.append("#").append(i).append(" ").append(answer).append("\n");
		}
		System.out.println(sb.toString());
	}

	static int[] dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
	static int chanceToShoot, width, height;
	static int answer;
	static int[][][] map;

	static void test() throws NumberFormatException, IOException {
		st = new StringTokenizer(in.readLine(), " ");
		chanceToShoot = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		height = Integer.parseInt(st.nextToken());
		answer = Integer.MAX_VALUE;
		map = new int[chanceToShoot + 1][height][width];
		for (int y = 0; y < height; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int x = 0; x < width; x++)
				map[0][y][x] = Integer.parseInt(st.nextToken());
		}
		run(0);
	}

	private static void run(int cnt) {
		if (cnt == chanceToShoot) {
			answer = Math.min(answer, getLeftBlock());
			return;
		}
		for (int i = 0; i < width; i++) {
			simulate(i, cnt + 1);
			shiftBlock(cnt + 1);
			run(cnt + 1);
		}
	}

	private static void simulate(int k, int cnt) {
		copy(cnt);
		for (int y = 0; y < height; y++) {
			if (map[cnt][y][k] == 0)
				continue;
			boom(y, k, cnt);
			return;
		}
	}

	private static void boom(int y, int x, int cnt) {
		int val = map[cnt][y][x];
		map[cnt][y][x] = 0;
		for (int i = 0; i < 4; i++) {
			for (int dist = 1; dist < val; dist++) {
				int ny = y + dist * dy[i];
				int nx = x + dist * dx[i];
				if (!isInBoundary(ny, nx))
					break;
				if (map[cnt][ny][nx] != 0)
					boom(ny, nx, cnt);
			}
		}
	}

	private static void shiftBlock(int cnt) {
		for (int x = 0; x < width; x++) {
			int shiftPos = height - 1;
			for (int y = height - 1; y >= 0; y--) {
				if (map[cnt][y][x] != 0)
					map[cnt][shiftPos--][x] = map[cnt][y][x];
			}
			while (shiftPos >= 0)
				map[cnt][shiftPos--][x] = 0;
		}
	}

	private static int getLeftBlock() {
		int sum = 0;
		for (int x = 0; x < width; x++) {
			int y = height - 1;
			while (y >= 0 && map[chanceToShoot][y--][x] != 0)
				sum++;
		}
		return sum;
	}

	private static void copy(int cnt) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++)
				map[cnt][y][x] = map[cnt - 1][y][x];
		}
	}

	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= height || x >= width) ? false : true;
	}
}
