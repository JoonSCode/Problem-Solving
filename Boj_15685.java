//Main idea: 선분들 방향의 규칙성 
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	
	static boolean[][] map; 
	static int numOfCurve;
	static int[] dy = {0,-1,0,1},dx = {1,0,-1,0};
	static ArrayList<Integer> order;
	public static void main(String[] args) throws IOException {
		numOfCurve = Integer.parseInt(in.readLine());
		order = new ArrayList<Integer>();
		map = new boolean[101][101];
		int answer = 0;
		for(int i = 0; i < numOfCurve; i++) {
			st = new StringTokenizer(in.readLine()," ");
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int dir = Integer.parseInt(st.nextToken());
			int gen = Integer.parseInt(st.nextToken());
			map[y][x] = true;
			makeCurve(x,y,dir,gen);
		}
		
		for(int y = 0; y < 100; y++) {
			for(int x = 0; x < 100; x++) {
				if(isValidate(y, x)) answer++;
			}
		}
		System.out.println(answer);
	}
	private static void makeCurve(int x, int y, int dir, int gen) {
		y += dy[dir];
		x += dx[dir];
		map[y][x] = true;	
		if(gen == 0) return;
		if(++dir == 4)
			dir = 0;
		order.add(dir);
		y += dy[dir];
		x += dx[dir];
		map[y][x] = true;
		
		int cnt = 1;
		ArrayList<Integer> tmp = new ArrayList<Integer>();
		while(cnt++ != gen) {
			for(int i = order.size()-1; i >= 0; i--) {
				dir = order.get(i);
				if(++dir == 4)
					dir = 0;
				tmp.add(dir);
				y += dy[dir];
				x += dx[dir];
				map[y][x] = true;
			}
			
			for(int i = 0; i < order.size(); i++) {
				dir = order.get(i);
				y += dy[dir];
				x += dx[dir];
				tmp.add(dir);
				map[y][x] = true;
			}
			order.clear();
			order.addAll(tmp);
			tmp.clear();
		}
		order.clear();
	}
	
	private static boolean isValidate(int y, int x) {
		for(int i = y; i <= y+1; i++) {
			for(int j = x; j <= x+1; j++) {
				if(!map[i][j]) return false;
			}
		}
		return true;
	}
}
