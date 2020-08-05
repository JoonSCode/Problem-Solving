//Main idea: bfs
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int[][] map;
	private static int N, M;
	private static int[] dy = { 0, 0, 1, -1, 1, 1, -1, -1 }, dx = { -1, 1, 0, 0, 1, -1, 1, -1 };
	private static Queue<Point> que;

	public static void main(String[] args) throws IOException {
		String str = "";
		while (!(str = in.readLine()).equals("0 0"))
			tomato(str);
		out.flush();
		out.close();
	}

	private static void tomato(String str) throws IOException {
		input(str);
		int answer = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x] == 1) {
					bfs(y, x);
					answer++;
				}
			}
		}
		out.write(String.valueOf(answer));
		out.newLine();
	}

	private static void input(String str) throws IOException {
		st = new StringTokenizer(str, " ");
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		que = new LinkedList<Point>();
		for (int y = 0; y < N; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int x = 0; x < M; x++)
				map[y][x] = Integer.parseInt(st.nextToken());
		}
	}

	private static void bfs(int ay, int ax) {
		que.add(new Point(ay, ax));
		map[ay][ax] = 0;
		while (!que.isEmpty()) {
			Point now = que.poll();
			int y = now.y;
			int x = now.x;
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!isInBoundary(ny, nx))
					continue;
				if (map[ny][nx] == 1) {
					map[ny][nx] = 0;
					que.add(new Point(ny, nx));
				}
			}
		}
	}

	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= N || x >= M) ? false : true;
	}
}

class Point {
	int y, x;

	public Point(int y, int x) {
		super();
		this.y = y;
		this.x = x;
	}
}
