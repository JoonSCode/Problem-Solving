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
		int N = in.nextInt();
		int[][] map = new int[101][101];
		for(int i = 0;i < N; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			int w = in.nextInt();
			int h = in.nextInt();
			
			for(int a = y; a < y + h; a++) {
				for(int b = x; b < x + w; b++)
					map[a][b] = i + 1;
			}
		}
		int[] answer = new int[N];
		for(int y = 0; y < 101; y++) {
			for(int x = 0; x < 101; x++) {
				if(map[y][x] == 0) continue;
				answer[map[y][x]-1]++;
			}
		}
		for(int i = 0; i < N; i++)
			System.out.println(answer[i]);
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
