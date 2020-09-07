//Main idea: 한 줄씩 생각을 해야 한다.
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	static int answer, height, width, K;
	static String[] map;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		height = in.nextInt();
		width = in.nextInt();
		map = new String[height];
		for (int y = 0; y < height; y++)
			map[y] = in.readLine();
		K = in.nextInt();
		answer = 0;
		run();
		System.out.println(answer);
	}

	static void run() {
		for (int y = 0; y < height; y++) {
			int cnt = 0;
			int tmp = 0;
			for (int x = 0; x < width; x++) {
				if (map[y].charAt(x) == '0')// 현재 줄을 키는 경우
					cnt++;
			}
			if (K < cnt || (K - cnt) % 2 != 0)// 킬 수 있는 경우인지 확인
				continue;
			for (int i = y; i < height; i++) {//현재 줄을 킬 수 있는 경우라면 그 줄과 같은 상태인 것들은 모두 켜지는 것
				if (map[y].equals(map[i]))
					tmp++;
			}
			answer = Math.max(answer, tmp);
		}
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
