//Main idea: 
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		boolean[][] map = new boolean[5][5];
		int[][] dict = new int[26][2];
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				dict[in.nextInt()] = new int[] { y, x };
			}
		}
		int end = -1;
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				int[] pos = dict[in.nextInt()];
				if (end != -1)
					continue;
				map[pos[0]][pos[1]] = true;
				if (isBingo(map))
					end = 5 * y + x + 1;
			}
		}
		System.out.println(end);
	}

	static boolean isBingo(boolean[][] map) {
		int cnt = 0;
		for (int y = 0; y < 5; y++) {
			if (!map[y][0])
				continue;
			for (int x = 0; x < 5; x++) {
				if (!map[y][x])
					break;
				if (x == 4)
					cnt++;
			}
		}

		for (int x = 0; x < 5; x++) {
			if (!map[0][x])
				continue;
			for (int y = 0; y < 5; y++) {
				if (!map[y][x])
					break;
				if (y == 4)
					cnt++;
			}
		}

		for (int i = 0; i < 5; i++) {
			if (!map[i][i])
				break;
			if (i == 4)
				cnt++;
		}

		for (int i = 0; i < 5; i++) {
			if (!map[i][4 - i])
				break;
			if (i == 4)
				cnt++;
		}
		return (cnt >= 3) ? true : false;
	}
}

class InputReader extends BufferedReader {
	private StringTokenizer st;

	public InputReader(InputStream in) {
		super(new InputStreamReader(in));
	}

	public int nextInt() throws IOException {
		if (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine());
		return Integer.parseInt(st.nextToken());
	}

	public int nextInt(String delimiter) throws IOException {
		if (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine(), delimiter);
		return Integer.parseInt(st.nextToken());
	}
}
