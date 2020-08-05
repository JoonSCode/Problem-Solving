//Main idea: 3차원 bfs
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	
	private static int[][][] boxes;
	private static int N,M,H;
	private static int[] dy = {0,0,1,-1,0,0}, dx = {-1,1,0,0,0,0}, dh = {0,0,0,0,-1,1};
	private static int total;
	public static void main(String[] args) throws IOException {
		tomato();
		out.flush();
		out.close();
	}

	private static void tomato() throws IOException {
		Queue<Point> que;
		que = input();
		int answer = bfs(que);
		if(total != 0)
			answer = -1;
		out.write(String.valueOf(answer));
	}

	private static Queue<Point> input() throws IOException {
		st = new StringTokenizer(in.readLine()," ");
		Queue<Point> tmp = new LinkedList<Point>();
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		boxes = new int[H][N][M];
		total = 0;
		
		for(int h = 0; h <H; h++) {
			for(int y = 0; y < N; y++) {
				st = new StringTokenizer(in.readLine()," ");
				for(int x = 0; x < M; x++) {
					boxes[h][y][x] = Integer.parseInt(st.nextToken());
					if(boxes[h][y][x] == 1) tmp.add(new Point(h,y,x));
					else if(boxes[h][y][x] == 0) total++;
				}
			}
		}
		return tmp;
	}
	
	private static int bfs(Queue<Point> que) {
		if(total == 0)
			return 0;
		
		int day = 0;
		total += que.size();
		while(!que.isEmpty()) {
			int size = que.size();
			total -= size;
			while(--size >= 0) {
				Point now = que.poll();
				int h = now.h;
				int y = now.y;
				int x = now.x;
				
				for(int i = 0; i < 6; i++) {
					int nh = h + dh[i];
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(!isInBoundary(nh, ny, nx)) continue;
					if(boxes[nh][ny][nx] == 0) {
						boxes[nh][ny][nx] = 1;
						que.add(new Point(nh,ny,nx));
					}
				}
			}
			day++;
		}
		return day-1;
	}
	
	private static boolean isInBoundary(int h, int y, int x) {
		return(h <0 || y < 0 || x<0 || h >= H || y >=N || x >=M)? false : true;
	}
}

class Point {
	int y,x,h;

	public Point(int h, int y, int x) {
		super();
		this.y = y;
		this.x = x;
		this.h = h;
	}
}
