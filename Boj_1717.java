//Main idea: Union find 구현
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int numOfVertex, numOfOrder;
	private static int[][] orders;
	private static int[] parents;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		run();
		System.out.println(sb.toString());
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		numOfVertex = Integer.parseInt(st.nextToken())+1;
		numOfOrder = Integer.parseInt(st.nextToken());
		orders = new int[numOfOrder][2];
		parents = new int[numOfVertex];
		for (int y = 0; y < numOfOrder; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			int order = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			orders[y] = new int[] {order,a,b};
		}
		
		for(int i = 0; i < numOfVertex; i++)
			parents[i] = i;
	}

	private static void run() {
		for(int[] order : orders) {
			int o = order[0];
			int a = order[1];
			int b = order[2];
			
			if(o == 0)
				union(a,b);
			else {
				sb.append((isGroup(a, b)? "YES" : "NO"));
				sb.append("\n");
			}
		}
	}
	
	private static int find(int child) {
		if(child == parents[child]) return child;
		return parents[child] = find(parents[child]);
	}
	
	private static void union(int a, int b) {
		int hA = find(a);
		int hB = find(b);
		if(hA == hB) return;
		parents[hB] = hA;
	}
	
	private static boolean isGroup(int a, int b) {
		int hA = find(a);
		int hB = find(b);
		return (hA == hB)? true : false;
	}
}
