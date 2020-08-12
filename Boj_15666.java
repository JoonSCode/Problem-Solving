//Main idea: 중복 
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int N, M;
	private static int[] numArr, arr;
	private static LinkedHashSet<String> sortedSet = new LinkedHashSet<String>();
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		input();
		run(0, 0);
		Iterator<String> iterator = sortedSet.iterator();
		while(iterator.hasNext()) {
			sb.append(iterator.next());
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		numArr = new int[N];
		arr = new int[M];
		st = new StringTokenizer(in.readLine(), " ");
		for(int i = 0; i < N; i++)
			numArr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(numArr);
	}

	private static void run(int cnt, int idx) {
		if (cnt == M) {
			for (int a : arr) {
				sb.append(a);
				sb.append(" ");
			}
			sortedSet.add(sb.toString());
			sb = new StringBuilder();
			return;
		}
		for (int i = idx; i < N; i++) {
			arr[cnt] = numArr[i];
			run(cnt + 1, i);
		}
	}
}
