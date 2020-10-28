//
import java.io.*;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		int T = Integer.parseInt(in.readLine());
		for (int i = 1; i <= T; i++) {
			sb.append("#");
			sb.append(i);
			sb.append("\n");
			test();
		}
		System.out.println(sb.toString());
	}

	static int[][] map;
	static boolean[][] isSummed;
	static int[] dy = { 0, 0, -1, 1 }, dx = { -1, 1, 0, 0 };
	static int sizeOfMap;

	static void test() throws NumberFormatException, IOException {
		st = new StringTokenizer(in.readLine(), " ");
		sizeOfMap = Integer.parseInt(st.nextToken());
		map = new int[sizeOfMap][sizeOfMap];
		isSummed = new boolean[sizeOfMap][sizeOfMap];
		String or = st.nextToken();
		for (int y = 0; y < sizeOfMap; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int x = 0; x < sizeOfMap; x++)
				map[y][x] = Integer.parseInt(st.nextToken());
		}

		if (or.equals("right"))
			right();
		else if (or.equals("up"))
			up();
		else if (or.equals("down"))
			down();
		else
			left();

		for (int y = 0; y < sizeOfMap; y++) {
			for (int x = 0; x < sizeOfMap; x++) {
				sb.append(map[y][x]);
				sb.append(" ");
			}
			sb.append("\n");
		}
	}

	static void left() {
		for (int y = 0; y < sizeOfMap; y++) {
			boolean flag = true;
			while (flag) {
				flag = false;
				for (int x = 0; x < sizeOfMap - 1; x++) {
					if (map[y][x] == 0) {
						if(map[y][x + 1] == 0) continue;
						map[y][x] = map[y][x + 1];
						map[y][x+1] = 0;
						isSummed[y][x] = isSummed[y][x + 1];
						flag = true;
					}
					if (map[y][x] != map[y][x + 1])
						continue;
					if (isSummed[y][x] || isSummed[y][x + 1])
						continue;
					map[y][x] += map[y][x + 1];
					map[y][x + 1] = 0;
					isSummed[y][x] = true;
					flag = true;
				}
			}
		}
	}

	static void right() {
		for (int y = 0; y < sizeOfMap; y++) {
			boolean flag = true;
			while (flag) {
				flag = false;
				for (int x = sizeOfMap - 1; x > 0; x--) {
					if (map[y][x] == 0) {
						if(map[y][x - 1] == 0) continue;
						map[y][x] = map[y][x - 1];
						map[y][x-1] = 0;
						isSummed[y][x] = isSummed[y][x - 1];
						flag = true;
					}
					if (map[y][x - 1] != map[y][x])
						continue;
					if (isSummed[y][x] || isSummed[y][x - 1])
						continue;
					map[y][x] += map[y][x - 1];
					isSummed[y][x] = true;
					map[y][x - 1] = 0;
					flag = true;
				}
			}
		}
	}

	static void up() {
		for (int x = 0; x < sizeOfMap; x++) {
			boolean flag = true;
			while (flag) {
				flag = false;
				for (int y = 0; y < sizeOfMap - 1; y++) {
					if (map[y][x] == 0) {
						if(map[y+1][x] == 0) continue;
						map[y][x] = map[y + 1][x];
						map[y+1][x] = 0;
						isSummed[y][x] = isSummed[y + 1][x];
						flag = true;
					}
					if (map[y][x] != map[y + 1][x])
						continue;
					if (isSummed[y][x] || isSummed[y + 1][x])
						continue;
					map[y][x] += map[y + 1][x];
					isSummed[y][x] = true;
					map[y + 1][x] = 0;
					flag = true;
				}
			}
		}
	}

	static void down() {
		for (int x = 0; x < sizeOfMap; x++) {
			boolean flag = true;
			while (flag) {
				flag = false;
				for (int y = sizeOfMap - 1; y > 0; y--) {
					if (map[y][x] == 0) {
						if(map[y - 1][x] == 0) continue;
						map[y][x] = map[y - 1][x];
						map[y-1][x] = 0;
						isSummed[y][x] = isSummed[y - 1][x];
						flag = true;
					}
					if (map[y][x] != map[y - 1][x])
						continue;
					if (isSummed[y][x] || isSummed[y - 1][x])
						continue;
					map[y][x] += map[y - 1][x];
					isSummed[y][x] = true;
					map[y - 1][x] = 0;
					flag = true;
				}
			}
		}
	}
}
