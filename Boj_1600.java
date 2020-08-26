//Main idea: bfs
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int height, width, K;
	private static int[][] map;
	private static Point[][] cache;
	private static int[] dy = { 0, 0, -1, 1, -1, -2, -2, -1, 1, 2, 2, 1 },
			dx = { 1, -1, 0, 0, -2, -1, 1, 2, 2, 1, -1, -2 };
	private static Queue<int[]> que = new LinkedList<int[]>();

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		run();
		System.out.println(cache[height-1][width-1].val);
	}

	private static void input() throws IOException {
		K = Integer.parseInt(in.readLine());
		st = new StringTokenizer(in.readLine(), " ");
		width = Integer.parseInt(st.nextToken());
		height = Integer.parseInt(st.nextToken());
		map = new int[height][width];
		cache = new Point[height][width];
		for (int y = 0; y < height; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int x = 0; x < width; x++) {
				map[y][x] = Integer.parseInt(st.nextToken());
				cache[y][x] = new Point(K);
			}
		}
	}

	private static void run() {
		que.add(new int[] { 0, 0 });
		cache[0][0].val = 0;
		while (!que.isEmpty()) {
			int now[] = que.poll();
			int y = now[0];
			int x = now[1];
			Point nowP = cache[y][x];
			int jmpCnt = nowP.jmpCnt;
			for (int i = 0; i < ((jmpCnt == 0) ? 4 : 12); i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				int type = 0;
				if(i >= 4)
					type = 1;
				if (!canMove(ny, nx, jmpCnt, type))
					continue;
				Point nextP = cache[ny][nx];
				nextP.val = nowP.val + 1;
				nextP.jmpCnt = nowP.jmpCnt;
				if (i >= 4)
					nextP.jmpCnt--;
				que.add(new int[] { ny, nx });
				if(ny+nx == height + width -2 ) return;
			}
		}
	}

	private static boolean canMove(int y, int x, int jmpCnt, int type) {
		if (!isInBoundary(y, x) || map[y][x] == 1)
			return false;
		Point p = cache[y][x];
		if (p.val != -1 && p.jmpCnt >= jmpCnt - type)
			return false;
		return true;
	}
	
	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= height || x >= width) ? false : true;
	}
}

class Point {
	int val, jmpCnt;

	public Point(int jmpCnt) {
		val = -1;
		this.jmpCnt = jmpCnt;
	}
}
