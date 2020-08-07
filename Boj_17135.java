//Main idea: 조합 + 
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int[][] board;
	private static int height,width, range, answer;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		input();
		setArcher(0,0,new int[width]);
		System.out.println(answer);
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		height = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		range = Integer.parseInt(st.nextToken());
		answer = 0;
		board = new int[height][width];
		
		for(int y = 0; y < height; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for(int x = 0; x < width; x++)
				board[y][x] = Integer.parseInt(st.nextToken());
		}
	}
	
	private static void setArcher(int idx, int cnt, int[] archer) {
		if(cnt == 3){
			game(archer);
			return;
		}
		if(idx == width) return;
		for(int i = idx; i < width; i++) {
			archer[i] = 1;
			setArcher(i + 1, cnt + 1, archer);
			archer[i] = 0;
		}
	}
	
	private static void game(int [] archer) {
		int[] counts = {99,0};
		int[][] map = new int[height][width];
		deepCopy(board, map);
		while(counts[0] != 0) {
			for(int i = 0; i < width; i++) {
				if(archer[i] == 0) continue;
				shoot(map, i);
			}
			int[] tmpCounts = move(map);
			counts[0] = tmpCounts[0];
			counts[1] += tmpCounts[1];
		}
		answer = Math.max(answer, counts[1]);
	}

	private static void shoot(int[][] map, int pos) {
		int my,mx,dist;
		my = mx = 0;
		dist = 987654321;
		for(int y = height - 1; y >= Math.max(0, height - range); y--) {
			for(int x = 0; x < width; x++) {
				if(map[y][x] == 0) continue;
				int tmpDist = height - y + Math.abs(pos-x);
				if(tmpDist > range) continue;
				if(dist > tmpDist) {
					dist = tmpDist;
					mx = x;
					my = y;
				}
				else if(dist == tmpDist && mx > x) {
					mx = x;		
					my = y;
				}
			}
		}
		if(dist != 987654321)
			map[my][mx] = -1;
	}
	
	private static int[] move(int[][] map) {
		int monster = 0;
		int deadMonster = 0;
		for(int y = height - 1; y >= 0; y--) {
			for(int x = 0; x < width; x++) {
				if(map[y][x] == 0) continue;
				
				if(map[y][x] == -1) {
					map[y][x] = 0;
					deadMonster ++;
					continue;
				}
				map[y][x] = 0;
				if(y+1 != height) {
					map[y+1][x] = 1;
					monster++;
				}
			}
		}
		return new int[] {monster,deadMonster};
	}
	
	private static void deepCopy(int [][] org, int [][] copy){
		for(int i = 0; i < org.length; i++) 
			copy[i] = org[i].clone();
	}
}
