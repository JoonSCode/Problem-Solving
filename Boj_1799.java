//Main idea: 체스판 검은색 흰색 나누어서 처리하는 것이 좋다!
import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	private static int sizeOfMap, ans;
	private static int[][] map;
	private static ArrayList<Point> black, white;
	private static int[] dx = { -1, 1 };

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		init();
		System.out.println(run());
	}

	private static void init() throws NumberFormatException, IOException {
		sizeOfMap = Integer.parseInt(in.readLine());
		map = new int[sizeOfMap][sizeOfMap];
		black = new ArrayList<Point>();
		white = new ArrayList<Point>();
		for (int y = 0; y < sizeOfMap; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int x = 0; x < sizeOfMap; x++) {
				map[y][x] = Integer.parseInt(st.nextToken());
				if (map[y][x] == 0)
					continue;
				if ((y + x) % 2 == 0)
					black.add(new Point(y, x));
				else
					white.add(new Point(y, x));
			}
		}
	}

	private static int run() {
		return backtracking(black, new boolean[black.size()], 0, 0)
				+ backtracking(white, new boolean[white.size()], 0, 0);
	}

	private static int backtracking(ArrayList<Point> list, boolean[] isVisited, int cnt, int idx) {
		int tmp = cnt;
		for (int i = idx; i < list.size(); i++) {
			Point p = list.get(i);
			int y = p.y;
			int x = p.x;
			if (map[y][x] != 1 || !isPossible(list, isVisited, i))
				continue;
			isVisited[i] = true;
			tmp = Math.max(tmp, backtracking(list, isVisited, cnt + 1, i + 1));
			isVisited[i] = false;
		}
		return tmp;
	}

	static boolean isPossible(ArrayList<Point> list, boolean[] isVisited, int idx) {
		Point now = list.get(idx);
		for (int i = 0; i < idx; i++) {
			if (!isVisited[i])
				continue;
			Point p = list.get(i);
			if(Math.abs(now.y-p.y) == Math.abs(now.x - p.x))
				return false;
		}
		return true;
	}

}

class Point {
	int y, x;

	Point(int y, int x) {
		this.y = y;
		this.x = x;
	}
}
