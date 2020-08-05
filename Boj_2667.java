//Main idea: bfs
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int[][] map;
	private static int N;
	private static int[] dy = { 0, 0, 1, -1 }, dx = { -1, 1, 0, 0 };
	private static ArrayList<Integer> sizeOfGroup = new ArrayList<Integer>();
	private static Queue<Point> que = new LinkedList<Point>();
	public static void main(String[] args) throws IOException {
		tomato();
		out.flush();
		out.close();
	}

	private static void tomato() throws IOException {
		input();
		int answer = 0;
		for(int y = 0; y < N; y++) {
			for(int x = 0; x < N; x++) {
				if(map[y][x] == 0) 
					continue;
				sizeOfGroup.add(bfs(y,x));
				answer++;
			}
		}
		Collections.sort(sizeOfGroup);
		out.write(String.valueOf(answer));
		out.newLine();
		for(int a : sizeOfGroup) {
			out.write(String.valueOf(a));
			out.newLine();		
		}
	}

	private static void input() throws IOException {
		N = Integer.parseInt(in.readLine());
		map = new int[N][N];

		for (int y = 0; y < N; y++) {
			char[] arr = in.readLine().toCharArray();
			for (int x = 0; x < N; x++) 
				map[y][x] = arr[x]-'0';
		}
	}

	private static int bfs(int a, int b) {
		que.add(new Point(a,b));
		int size = 0;
		map[a][b] = 0;
		while (!que.isEmpty()) {
			Point now = que.poll();
			int y = now.y;
			int x = now.x;
			size++;
			for (int i = 0; i < dx.length; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!isInBoundary(ny, nx) || map[ny][nx] == 0)
					continue;
				map[ny][nx] = 0;
				que.add(new Point(ny, nx));
			}
		}
		return size;
	}

	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= N || x >= N) ? false : true;
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
