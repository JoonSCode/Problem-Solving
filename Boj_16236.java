//Main idea: depth별 bfs
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	static int answer;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		int N = in.nextInt();
		answer = 0;
		Queue<Point> que = new LinkedList<Main.Point>();
		int[][] map = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = in.nextInt();
				if (map[i][j] == 9)
					que.add(new Point(i, j));
			}
		}
		int[] dy = { -1, 0, 0, 1 };
		int[] dx = { 0, -1, 1, 0 };
		int size = 2;
		int eat = 0;
		boolean[][] isVisited = new boolean[N][N];
		int oy = que.peek().y;
		int ox = que.peek().x;
		int day = 0;
		while (!que.isEmpty()) {
			int s = que.size();
			int py,px;
			py = px = N;
			day++;
			while (--s >= 0) {
				Point now = que.poll();
				int y = now.y;
				int x = now.x;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (!isInBoundary(ny, nx, N) || isVisited[ny][nx] || map[ny][nx] > size)
						continue;
					if (map[ny][nx] == 0 || map[ny][nx] == size) {
						isVisited[ny][nx] = true;
						que.add(new Point(ny, nx));
						continue;
					}

					if(ny < py) {
						py = ny;
						px = nx;
					}
					else if(ny == py) {
						if(nx < px)
							px = nx;
					}
				}
			}
			if(py + px == 2 * N) continue;
			map[py][px] = 9;
			map[oy][ox] = 0;
			que.clear();
			for (int a = 0; a < N; a++)
				Arrays.fill(isVisited[a], false);
			
			isVisited[py][px] = true;
			answer += day;
			oy = py;
			ox = px;
			day = 0;
			que.add(new Point(oy, ox));
			if (++eat == size) {
				size++;
				eat = 0;
			}
		}
		System.out.println(answer);
	}

	static boolean isInBoundary(int y, int x, int N) {
		return (y < 0 || x < 0 || y >= N || x >= N) ? false : true;
	}

	static class Point {
		int y, x;

		public Point(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}
}

class InputReader extends BufferedReader {
	private StringTokenizer st;

	public InputReader(InputStream in) {
		super(new InputStreamReader(in));
	}

	public int nextInt() throws IOException {
		if (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine());
		return Integer.parseInt(st.nextToken());
	}

	public int nextInt(String delimiter) throws IOException {
		if (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine(), delimiter);
		return Integer.parseInt(st.nextToken());
	}
}
