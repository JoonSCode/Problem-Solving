//Main idea: 함수를 최소한 작게
import java.io.*;
import java.util.*;

public class Solution {
	
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static int H,W;
	private static char[][] field;
	private static int tx,ty,tdir;
	private static int[] dy = {-1,1,0,0}, dx = {0,0,-1,1};
	private static char[] dir = {'^', 'v', '<','>'};
	private static char[] alpDir = {'U', 'D', 'L','R'};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		int T = Integer.parseInt(br.readLine());
		for(int i = 0; i < T; i++) {
			System.out.print("#" + (i+1) +" ");
			battle();
		}
	}
	
	private static void battle() throws IOException {
		input();
		br.readLine();
		char[] order = br.readLine().toCharArray();
		for(char a : order) {
			if(a == 'S')
				shoot();
			else 
				move(a);
		}
		
		StringBuilder sb = new StringBuilder();
		for(int y = 0 ; y < H; y++) {
			sb.append(field[y]);
			sb.append("\n");
		}	
		System.out.print(sb);
	}
	
	private static void input() throws IOException {
		st = new StringTokenizer(br.readLine(), " ");
		H = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		field = new char[H][W];
		
		for(int y = 0 ; y < H; y++) {
			char[] arr = br.readLine().toCharArray();
			for(int x = 0; x < W; x++) {
				char tmp = field[y][x] = arr[x];
				if(isTank(tmp)) {
					ty = y;
					tx = x;
				}
			}
		}
	}
	
	private static boolean isTank(char a) {
		for(int i = 0; i < 4; i++) {
			char t = dir[i];
			if(t == a) {
				tdir = i;
				return true;
			}
		}
		return false;
	}
	
	private static void shoot() {
		int ny = ty + dy[tdir];
		int nx = tx + dx[tdir];
		while(isInBoundary(ny, nx)) {
			if(isEncountered(ny, nx)) break;
			ny += dy[tdir];
			nx += dx[tdir];
		}
	}
	
	private static boolean isInBoundary(int y, int x) {
		if(y < 0 || y >= H || x < 0 || x >= W) return false;
		return true;	
	}
	
	private static boolean isEncountered(int y, int x) {
		if(field[y][x] == '*') {
			field[y][x] = '.';
			return true;
		}
		else if(field[y][x] == '#')
			return true;
		return false;	
	}
	
	private static boolean isWater(int y, int x) {
		int ny = y + dy[tdir];
		int nx = x + dx[tdir];
		if(isInBoundary(ny,nx) && field[ny][nx] == '.') return false;
		return true;
	}
	
	private static void move(char a) {
		for(int i = 0; i < 4; i++) {
			if(alpDir[i] != a) continue;
			tdir = i;
			break;
		}
		field[ty][tx] = dir[tdir];
		if(isWater(ty,tx)) return;
		field[ty][tx] = '.';
		ty += dy[tdir];
		tx += dx[tdir];
		field[ty][tx] = dir[tdir];
	}

}
