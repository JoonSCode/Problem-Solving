//Main idea: 스택 
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		test();
	}

	static int[] cache, arr;
	private static void test() throws NumberFormatException, IOException {
		int N = in.nextInt();
		ArrayList<int[]> pillars = new ArrayList<int[]>();
		for(int i = 0; i < N; i++)
			pillars.add(new int[] {in.nextInt(), in.nextInt()});
		Collections.sort(pillars, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return o1[0]-o2[0];
			}
		});
		int ans = 0;
		int[] tmp = pillars.get(0); 
		int left = tmp[0];
		int h = tmp[1];
		int idx = 0;
		for(int i = 0; i < N; i++) {
			int[] pillar = pillars.get(i);
			if(pillar[1] < h) continue;
			ans += (pillar[0]-left) * h;
			h = pillar[1];
			left = pillar[0];
			idx = i;
		}
		tmp = pillars.get(N-1);
		int r = tmp[0];
		h = tmp[1];
		for(int i = N-1; i >=idx; i--) {
			int[] pillar = pillars.get(i);
			if(pillar[1] < h) continue;
			ans += (r - pillar[0]) * h;
			h = pillar[1];
			r = pillar[0];
		}
		if(left == r)
			ans += h;
		System.out.println(ans);
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
