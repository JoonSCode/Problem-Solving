//Main idea : 조합 , 
import java.io.*;
import java.util.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int[][] map;
	static int[] dy = { 0, 0, -1, 1 }, dx = { 1, -1, 0, 0 };
	static int height, width;

	static LinkedList<int[]> viruses;
	static ArrayList<int[]> emptyAreas;
	static int answer = 0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		st = new StringTokenizer(in.readLine(), " ");
		height = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		map = new int[height][width];
		viruses = new LinkedList<int[]>();
		emptyAreas = new ArrayList<int[]>();
		for (int y = 0; y < height; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int x = 0; x < width; x++) {
				map[y][x] = Integer.parseInt(st.nextToken());
				if (map[y][x] == 0)
					emptyAreas.add(new int[] { y, x });
				if (map[y][x] == 2)
					viruses.add(new int[] { y, x });
			}
		}
		comb(new int[3][2], 0, 0);
		System.out.println(answer);
	}

	static void comb(int[][] selected, int idx, int cnt) {
		if (cnt == 3) {
			answer = Math.max(answer, getNumOfSafeArea(selected));
			return;
		}

		for (int i = idx; i < emptyAreas.size(); i++) {
			selected[cnt] = emptyAreas.get(i);
			comb(selected, i + 1, cnt + 1);
		}
	}

	private static int getNumOfSafeArea(int[][] selected) {
		for (int[] area : selected)
			map[area[0]][area[1]] = 1;

		Queue<int[]> que = new LinkedList<int[]>();
		for (int[] virus : viruses)
			que.add(virus);
		int cnt = 0;
		while (!que.isEmpty()) {
			int[] now = que.poll();
			int y = now[0];
			int x = now[1];
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (!isInBoundary(ny, nx) || map[ny][nx] != 0)
					continue;
				map[ny][nx] = 3;
				cnt++;
				que.add(new int[] { ny, nx });
			}
		}

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if(map[y][x] == 3)
					map[y][x] = 0;
			}
		}

		for (int[] area : selected)
			map[area[0]][area[1]] = 0;
		return emptyAreas.size() - 3 - cnt;
	}

	static int[][] copy(int[][] org) {
		int[][] copy = new int[org.length][org[0].length];
		for (int i = 0; i < org.length; i++)
			copy[i] = org[i].clone();
		return copy;
	}

	static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= height || x >= width) ? false : true;
	}
}
