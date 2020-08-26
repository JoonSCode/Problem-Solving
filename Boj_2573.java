//Main idea: BFS, 시뮬레이션
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int height, width, answer;
	private static int[][] map;
	private static Queue<int[]> que = new LinkedList<int[]>();
	private static int[] dy = { 0, 0, -1, 1 }, dx = { 1, -1, 0, 0 };

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		run();
		System.out.println(answer);
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		height = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		answer = 0;
		map = new int[height][width];
		for (int y = 0; y < height; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int x = 0; x < width; x++) {
				int num = Integer.parseInt(st.nextToken());
				if (num != 0)
					que.add(new int[] { y, x });
				else
					num = -1;
				map[y][x] = num;
			}
		}
	}

	private static void run() {
		int day = -1;
		while (!que.isEmpty()) {
			day++;

			if (!bfs(que.peek()[0], que.peek()[1])) {
				answer = day;
				return;
			}

			int size = que.size();
			while (--size >= 0) {
				int[] now = que.poll();
				int y = now[0];
				int x = now[1];
				int val = map[y][x];
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (!isInBoundary(ny, nx))
						continue;
					if (map[ny][nx] == -1)
						val--;
				}
				map[y][x] = Math.max(0, val);
				if (map[y][x] != 0)
					que.add(new int[] { y, x });
			}
			refresh();
		}
	}

	private static boolean bfs(int a, int b) {
		int size = que.size();
		int cnt = 1;
		Queue<int[]> tmp = new LinkedList<int[]>();
		boolean[][] isVisited = new boolean[height][width];
		tmp.add(new int[] { a, b });
		isVisited[a][b] = true;
		while (!tmp.isEmpty()) {
			int[] now = tmp.poll();
			int y = now[0];
			int x = now[1];
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (!isInBoundary(ny, nx) || map[ny][nx] == -1 || isVisited[ny][nx])
					continue;
				cnt++;
				isVisited[ny][nx] = true;
				tmp.add(new int[] { ny, nx });
			}
		}
		return (cnt == size) ? true : false;
	}

	private static void refresh() {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (map[y][x] != 0)
					continue;
				map[y][x] = -1;
			}
		}
	}

	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= height || x >= width) ? false : true;
	}
}
