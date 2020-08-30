//Main idea: LCS + 
import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	private static int lengthOfSequence;
	private static int[] numbers;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		init();
		System.out.println(run());
	}

	private static void init() throws NumberFormatException, IOException {
		lengthOfSequence = Integer.parseInt(in.readLine());
		numbers = new int[lengthOfSequence];
		st = new StringTokenizer(in.readLine(), " ");
		for (int y = 0; y < lengthOfSequence; y++)
			numbers[y] = Integer.parseInt(st.nextToken());
	}

	private static int run() {
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(numbers[0]);
		for (int i = 1; i < lengthOfSequence; i++) {
			if (list.get(list.size() - 1) < numbers[i])
				list.add(numbers[i]);
			else
				bs(list, 0, list.size() - 1, numbers[i]);
		}
		return list.size();
	}

	private static void bs(ArrayList<Integer> list, int start, int end, int target) {
		while (start + 1 < end) {
			int mid = (start + end) / 2;
			if (list.get(mid) < target)
				start = mid + 1;
			else
				end = mid;
		}
		if (list.get(start) >= target)
			list.set(start, target);
		else
			list.set(end, target);
	}
}
