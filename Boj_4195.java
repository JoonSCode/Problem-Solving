//Main idea: Disjoint Set
import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	private static int numOfRelation;
	private static HashMap<String, String> parentMap;
	private static HashMap<String, Integer> sizeMap;

	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(in.readLine());
		for(int i = 0; i < T; i++)
			test();
		System.out.println(sb.toString());
	}

	private static void test() throws IOException {
		init();
		run();
	}

	private static void init() throws NumberFormatException, IOException {
		numOfRelation = Integer.parseInt(in.readLine());
		parentMap = new HashMap<String, String>();
		sizeMap = new HashMap<String, Integer>();
	}

	private static void run() throws IOException {
		for (int i = 0; i < numOfRelation; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			String child1, child2;
			child1 = st.nextToken();
			child2 = st.nextToken();
			if (!parentMap.containsKey(child1)) {
				parentMap.put(child1, child1);
				sizeMap.put(child1, 1);
			}
			if (!parentMap.containsKey(child2)) {
				parentMap.put(child2, child2);
				sizeMap.put(child2, 1);
			}
			sb.append(union(child1, child2));
			sb.append("\n");
		}
	}

	private static String find(String child) {
		if (parentMap.get(child) == child)
			return child;
		parentMap.put(child, find(parentMap.get(child)));
		return parentMap.get(child);
	}

	private static int union(String a, String b) {
		String ha = find(a);
		String hb = find(b);
		if (ha == hb)
			return sizeMap.get(ha);
		int sum = sizeMap.get(ha) + sizeMap.get(hb);
		sizeMap.put(ha, sum);
		sizeMap.put(hb, sum);
		parentMap.put(hb, ha);
		return sum;
	}
}
