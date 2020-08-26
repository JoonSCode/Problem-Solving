//Main idea: 벽 부순 것의 우선순위를 정하는게 중요! bfs
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int height, width, answer;
	private static int[][] map;
	private static Point[][] isVisited;
	private static int[] dy = { 0, 1, 0, -1 }, dx = { 1, 0, -1, 0 };

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		run();
		System.out.println(isVisited[height - 1][width - 1].val);
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		height = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		map = new int[height][width];
		isVisited = new Point[height][width];
		answer = (int) 2e31 - 1;
		for (int y = 0; y < height; y++) {
			char[] arr = in.readLine().toCharArray();
			for (int x = 0; x < width; x++) {
				map[y][x] = arr[x] - '0';
				isVisited[y][x] = new Point();
			}
		}
	}

	private static void run() {

		Queue<int[]> que = new LinkedList<int[]>();
		que.add(new int[] { 0, 0 });
		isVisited[0][0].val = 1;
		while (!que.isEmpty()) {
			int[] now = que.poll();
			int y = now[0];
			int x = now[1];
			int val = isVisited[y][x].val;
			boolean isBreak = isVisited[y][x].isBreak;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (!isInBoundary(ny, nx))
					continue;
				Point point = isVisited[ny][nx];
				if (point.val != -1 && (isBreak || !point.isBreak))
					continue;
				if (isBreak && map[ny][nx] == 1)
					continue;
				if (point.val != -1 && point.isBreak && map[ny][nx] == 1)
					continue;
				que.add(new int[] { ny, nx });
				point.val = val + 1;
				if (map[ny][nx] == 1)
					point.isBreak = true;
				else
					point.isBreak = isBreak;
				if (ny + nx == height + width - 2)
					return;
			}
		}
	}

	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= height || x >= width) ? false : true;
	}
}

class Point {
	int val;
	boolean isBreak;

	public Point() {
		val = -1;
		isBreak = false;
	}
}
