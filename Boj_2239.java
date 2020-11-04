//Main idea: 
import java.io.*;
import java.util.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static char[][] map = new char[9][9];
	static boolean[][] isUsedCol, isUsedRow, isUsedSqu;
	static List<int[]> holes = new ArrayList<int[]>();

	public static void main(String[] args) throws NumberFormatException, IOException {
		isUsedCol = new boolean[9][10];
		isUsedRow = new boolean[9][10];
		isUsedSqu = new boolean[9][10];
		for (int y = 0; y < 9; y++) {
			map[y] = in.readLine().toCharArray();
			for (int x = 0; x < 9; x++) {
				int num = map[y][x] - '0';
				isUsedRow[y][num] = true;
				isUsedCol[x][num] = true;
				isUsedSqu[(x/3)+3*(y/3)][num] = true;
				if(num == 0)
					holes.add(new int[] { y, x });
			}
		}
		dfs(0);
		for(char[] row : map)
			System.out.println(row);
	}

	private static boolean dfs(int cnt) {
		if (cnt == holes.size()) {
			return true;
		}
		int[] now = holes.get(cnt);
		int y = now[0];
		int x = now[1];
		for (int val = 1; val <= 9; val++) {
			map[y][x] = (char) (val + '0');
			if (isPossible(cnt, val)) {
				check(y, x, val, true);
				if(dfs(cnt + 1))
					return true;
				check(y, x, val, false);
			}
			map[y][x] = '0';
		}
		return false;
	}

	private static boolean isPossible(int cnt, int val) {
		int[] now = holes.get(cnt);
		int y = now[0];
		int x = now[1];
		if(isUsedRow[y][val] || isUsedCol[x][val] || isUsedSqu[x/3+3*(y/3)][val]) 
			return false;
		return true;
	}
	
	private static void check(int y, int x ,int val, boolean flag) {
		isUsedRow[y][val] = flag;
		isUsedCol[x][val] = flag;
		isUsedSqu[x/3+3*(y/3)][val] = flag;
	}
}
