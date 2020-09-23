//Main idea: 가로 세로 나눠서 
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
		LinkedList<int[]> row = new LinkedList<int[]>();
		LinkedList<int[]> col = new LinkedList<int[]>();
		int w = in.nextInt();
		int h = in.nextInt();
		row.add(new int[] { 0, w });
		col.add(new int[] { 0, h });
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int o = in.nextInt();
			int line = in.nextInt();
			if (o == 0) {
				for (Iterator iterator = col.iterator(); iterator.hasNext();) {
					int[] is = (int[]) iterator.next();
					if (is[0] < line && line < is[1]) {
						col.add(new int[] { line, is[1] });
						is[1] = line;
						break;
					}
				}
			} else {
				for (Iterator iterator = row.iterator(); iterator.hasNext();) {
					int[] is = (int[]) iterator.next();
					if (is[0] < line && line < is[1]) {
						row.add(new int[] { line, is[1] });
						is[1] = line;
						break;
					}
				}
			}
		}
		int a = 0;
		int b = 0;
		for (Iterator iterator = row.iterator(); iterator.hasNext();) {
			int[] is = (int[]) iterator.next();
			if(is[1]-is[0] > a)
				a = is[1]-is[0];
		}
		for (Iterator iterator = col.iterator(); iterator.hasNext();) {
			int[] is = (int[]) iterator.next();
			if(is[1]-is[0] > b)
				b = is[1]-is[0];
		}
		System.out.println(a*b);
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
