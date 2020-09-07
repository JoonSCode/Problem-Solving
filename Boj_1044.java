//Main idea: 정점간의 
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		int T = in.nextInt();
		for (int i = 0; i < T; i++)
			test();
		System.out.println(sb.toString());
	}

	private static void test() throws NumberFormatException, IOException {
		int x1, y1, x2, y2;
		x1 = in.nextInt();
		y1 = in.nextInt();
		x2 = in.nextInt();
		y2 = in.nextInt();
		int numOfPlanet = in.nextInt();
		int answer = 0;
		int cx, cy, r;
		for (int i = 0; i < numOfPlanet; i++) {
			cx = in.nextInt();
			cy = in.nextInt();
			r = in.nextInt();
			boolean flag = false;
			if(getDist(x1, y1, cx, cy) < r)
				flag = !flag;
			if(getDist(x2, y2, cx, cy) < r) {
				flag = !flag;
			}
			if(flag)
				answer++;
		}
		sb.append(answer);
		sb.append("\n");
	}

	static double getDist(int x, int y, int cx, int cy) {
		return Math.sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
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
