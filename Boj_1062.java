//Main idea: 
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	static int answer;
	static int[] wordArr;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		int N, K;
		N = in.nextInt();
		K = in.nextInt();
		answer = 0;
		String[] words = new String[N];
		for (int i = 0; i < N; i++)
			words[i] = in.readLine();

		if (K < 5) {
			System.out.println(0);
			return;
		}

		K -= 5;
		int mask = 0;
		char[] tmp = { 'a', 'n', 't', 'i', 'c' };
		wordArr = new int[N];
		for (char a : tmp)
			mask |= 1 << (a - 'a');
		for (int i = 0; i < N; i++) {
			char[] arr = words[i].toCharArray();
			int word = mask;
			for (int j = 4; j < arr.length - 4; j++) {
				word |= 1 << (arr[j] - 'a');
			}
			wordArr[i] = word;
		}
		comb(mask, K, 0);
		System.out.println(answer);
	}

	static void comb(int mask, int cnt, int idx) {
		if (cnt == 0) {
			answer = Math.max(answer, check(mask));
			return;
		}
		if (idx >= 26)
			return;
		comb(mask, cnt, idx + 1);
		if ((mask & 1 << idx) == 0) {
			mask |= 1 << idx;
			comb(mask, cnt - 1, idx + 1);
		}
	}

	static int check(int mask) {
		int cnt = 0;
		for (int word : wordArr) {
			if ((mask & word) == word)
				cnt++;
		}
		return cnt;
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
