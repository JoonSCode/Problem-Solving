//Main idea: 방향에 유의해서 코드 
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		test();
	}

	static int width, height, numOfStore;

	private static void test() throws NumberFormatException, IOException {
		width = in.nextInt();
		height = in.nextInt();
		numOfStore = in.nextInt();
		ArrayList<int[]> stores = new ArrayList<int[]>();
		for (int i = 0; i < numOfStore; i++)
			stores.add(new int[] { in.nextInt(), in.nextInt() });

		int[] dg = { in.nextInt(), in.nextInt() };
		int answer = 0;
		for (int[] store : stores)
			answer += getDist(dg, store);
		System.out.println(answer);
	}

	static int getDist(int[] a, int[] b) {
		int dist = 0;
		if (a[0] > b[0]) {
			int[] tmp = a;
			a = b;
			b = tmp;
		}
		int ao = a[0];
		int ad = a[1];
		int bo = b[0];
		int bd = b[1];
		if (ao == bo)
			dist = Math.abs(ad - bd);
		else if (Math.abs(ao - bo) == 3)
			dist = width - ad + bd;
		else if (Math.abs(ao - bo) == 2) {
			if (bo == 3)
				dist = ad + bd;
			else
				dist = width - ad + height - bd;
		} else {
			if (bo == 2)
				dist = height + Math.min(ad + bd, width * 2 - ad - bd);
			else if (bo == 3)
				dist = ad + height - bd;
			else
				dist = width + Math.min(ad + bd, height * 2 - ad - bd);
		}
		return dist;
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
