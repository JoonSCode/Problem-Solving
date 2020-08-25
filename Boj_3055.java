//Main idea: bfs2개 돌리
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int ans, height, width;
	private static int[][] map;
	private static Queue<int[]> beaver, water;
	private static int[] dy = { 0, 0, -1, 1 }, dx = { 1, -1, 0, 0 };

	public static void main(String[] args) throws IOException {

		escape();
	}

	private static void escape() throws NumberFormatException, IOException {
		input();
		int ans = run();
		System.out.println((ans== 0)? "KAKTUS" : ans-1);
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		height = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		map = new int[height][width];
		beaver = new LinkedList<int[]>();
		water = new LinkedList<int[]>();
		for (int y = 0; y < height; y++) {
			char[] arr = in.readLine().toCharArray();
			for (int x = 0; x < width; x++) {
				char tmp = arr[x];
				if (tmp == 'X')
					map[y][x] = -2;
				else if (tmp == 'D')
					map[y][x] = -3;
				else if (tmp == 'S') {
					map[y][x] = 1;
					beaver.add(new int[] { y, x });
				} else if (tmp == '*') {
					map[y][x] = 0;
					water.add(new int[] { y, x });
				} else
					map[y][x] = -1;
			}
		}
	}

	private static int run() {
		while (!beaver.isEmpty()) {
			int size = beaver.size();
			while (--size >= 0) {
				int[] bnow = beaver.poll();
				int y = bnow[0];
				int x = bnow[1];
				if(isWater(y, x)) continue;
				int cnt = map[y][x];
				for(int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if(!isInBoundary(ny, nx) || isRock(ny, nx) || isWater(ny, nx)|| isVisited(ny, nx)) continue;
					if(isDestination(ny, nx)) return cnt+1;
					map[ny][nx] = cnt+1;
					beaver.add(new int [] {ny,nx});
				}
			}
			size = water.size();
			while(--size >= 0) {
				int[] wnow = water.poll();
				int y = wnow[0];
				int x = wnow[1];
				for(int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if(!isInBoundary(ny, nx) || isDestination(ny, nx) || isRock(ny, nx) || isWater(ny, nx)) continue; 
					map[ny][nx] = 0;
					water.add(new int[] {ny,nx});
				}
			}
		}
		return 0;
	}

	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= height || x >= width) ? false : true;
	}

	private static boolean isWater(int y, int x) {
		return (map[y][x] == 0) ? true : false;
	}

	private static boolean isVisited(int y, int x) {
		return (map[y][x] >= 1) ? true : false;
	}
	
	private static boolean isRock(int y, int x) {
		return (map[y][x] == -2) ? true : false;
	}

	private static boolean isDestination(int y, int x) {
		return (map[y][x] == -3) ? true : false;
	}
}
