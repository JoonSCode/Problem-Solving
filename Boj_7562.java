//Main idea: 
import java.io.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.util.*;

import org.omg.PortableInterceptor.INACTIVE;

class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int sizeOfChessMap;
	private static int sy, sx, destY, destX;
	private static int answer;
	private static boolean[][] chessMap;
	private static Queue<Point> que = new LinkedList<Point>();
	private static int[] dy = { -1, -2, -2, -1, 1, 2, 2, 1 };
	private static int[] dx = { -2, -1, 1, 2, 2, 1, -1, -2 };

	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; i++)
			test();
		out.flush();
		out.close();
	}

	private static void test() throws NumberFormatException, IOException {
		init();
		run();
		//System.out.println("answer:" + answer);
		out.write(Integer.toString(answer));
		out.newLine();

	}

	private static void init() throws IOException {
		sizeOfChessMap = Integer.parseInt(in.readLine());
		chessMap = new boolean[sizeOfChessMap][sizeOfChessMap];
		que.clear();
		answer = 987654321;
		st = new StringTokenizer(in.readLine(), " ");
		sy = Integer.parseInt(st.nextToken());
		sx = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(in.readLine(), " ");
		destY = Integer.parseInt(st.nextToken());
		destX = Integer.parseInt(st.nextToken());
	}

	private static void run() throws IOException {	
		que.add(new Point(sy, sx, 0));
		chessMap[sy][sx] = true;
		while (!que.isEmpty()) {
			Point now = que.poll();
			int cnt = now.cnt;
			int y = now.y;
			int x = now.x;
			
			if(isArrived(now)) {
				answer = cnt;
				return;
			}
			
			for (int i = 0; i < 8; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(!isInBoundary(ny,nx) || chessMap[ny][nx]) continue;
				chessMap[ny][nx] = true;
				que.add(new Point(ny,nx, cnt+1));
			}
		}	
	}

	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || y >= sizeOfChessMap || x < 0 || x >= sizeOfChessMap) ? false : true;
	}

	private static boolean isArrived(Point a) {
		return (a.y == destY && a.x == destX)? true:false;
	}
}

class Point {
	int y, x, cnt;

	Point() {
	}

	public Point(int y, int x, int cnt) {
		super();
		this.y = y;
		this.x = x;
		this.cnt = cnt;
	}
}
