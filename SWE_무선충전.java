//Main idea: 
import java.io.*;
import java.util.*;

public class Solution {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		int T = Integer.parseInt(in.readLine());
		for (int i = 1; i <= T; i++) {
			sb.append("#");
			sb.append(i);
			sb.append(" ");
			test();
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}

	static List<Charger>[][] map;
	static List<Integer> aMoves, bMoves;
	static int[] dy = { 0, -1, 0, 1, 0 }, dx = { 0, 0, 1, 0, -1 };
	static int[] aPos, bPos;
	static int totalTime, numOfCharger;
	static int answer;

	static void test() throws NumberFormatException, IOException {
		init();
		input();

		for (int i = 0; i <= totalTime; i++) {
			aPos[0] += dy[aMoves.get(i)];
			aPos[1] += dx[aMoves.get(i)];
			bPos[0] += dy[bMoves.get(i)];
			bPos[1] += dx[bMoves.get(i)];
			List<Charger> aList = map[aPos[0]][aPos[1]];
			List<Charger> bList = map[bPos[0]][bPos[1]];

			if (aList.size() != 0 && bList.size() != 0) {
				if (aList.get(0).id == bList.get(0).id) {
					answer += aList.get(0).performance;
					int tmp = 0;
					if (aList.size() > 1)
						tmp = Math.max(tmp, aList.get(1).performance);
					if (bList.size() > 1)
						tmp = Math.max(tmp, bList.get(1).performance);
					answer += tmp;
				} else 
					answer += aList.get(0).performance + bList.get(0).performance;
			}
			else {
				if(aList.size() != 0) 
					answer += aList.get(0).performance;
				if(bList.size() != 0) 
					answer += bList.get(0).performance;
			}
		}
		sb.append(answer);
	}

	private static void init() {
		aMoves = new ArrayList<Integer>();
		bMoves = new ArrayList<Integer>();
		aPos = new int[] { 0, 0 };
		bPos = new int[] { 9, 9 };
		answer = 0;
		map = new ArrayList[10][10];
		for (int y = 0; y < 10; y++) {
			for (int x = 0; x < 10; x++)
				map[y][x] = new ArrayList<Charger>();
		}
		aMoves.add(0);
		bMoves.add(0);
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		totalTime = Integer.parseInt(st.nextToken());
		numOfCharger = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(in.readLine(), " ");
		for (int i = 0; i < totalTime; i++)
			aMoves.add(Integer.parseInt(st.nextToken()));
		st = new StringTokenizer(in.readLine(), " ");
		for (int i = 0; i < totalTime; i++)
			bMoves.add(Integer.parseInt(st.nextToken()));

		for (int i = 0; i < numOfCharger; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			int[] pos = { Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken())- 1 };
			int tmp = pos[0];
			pos[0] = pos[1];
			pos[1] = tmp;
			int coverage = Integer.parseInt(st.nextToken());
			int perfomance = Integer.parseInt(st.nextToken());
			updateMap(i, pos, coverage, perfomance);
		}
		for (int y = 0; y < 10; y++) {
			for (int x = 0; x < 10; x++)
				Collections.sort(map[y][x]);
		}
	}

	private static void updateMap(int id, int[] pos, int coverage, int performance) {
		int sy = Math.max(0, pos[0] - coverage);
		int ey = Math.min(9, pos[0] + coverage);
		int sx = Math.max(0, pos[1] - coverage);
		int ex = Math.min(9, pos[1] + coverage);
		for (int y = sy; y <= ey; y++) {
			for (int x = sx; x <= ex; x++) {
				int dist = Math.abs(y - pos[0]) + Math.abs(x - pos[1]);
				if (dist > coverage)
					continue;
				map[y][x].add(new Charger(id, performance));
			}
		}
	}
	
	static class Charger implements Comparable<Charger>{
		int id, performance;

		public Charger(int id, int performance) {
			this.id = id;
			this.performance = performance;
		}

		@Override
		public int compareTo(Charger o) {
			return o.performance - this.performance;
		}
	}
}
