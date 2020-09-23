//Main idea: 브루트포스
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		test();
	}

	static int answer =0;
	static ArrayList<Integer> list;
	static ArrayList<Integer> ansList;
	private static void test() throws NumberFormatException, IOException {
		int N = in.nextInt();
		list = new ArrayList<Integer>();
		ansList = new ArrayList<Integer>();
		
		list.add(N);
		for(int i = 1; i <= N; i++) {
			list.add(i);
			run(2);
			list.remove(1);
		}
		sb.append(answer);
		sb.append("\n");
		for(int num : ansList) {
			sb.append(num);
			sb.append(" ");
		}
		System.out.println(sb.toString());
	}
	
	static void run(int cnt) {
		int num = list.get(cnt-2) - list.get(cnt-1);
		if(num < 0) {
			if(answer < cnt) {
				answer = cnt;
				ansList.clear();
				ansList.addAll(0, list);
			}
			return;	
		}
		list.add(num);
		run(cnt+1);
		list.remove(cnt);
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
