//Main idea: MST문제 크루스칼로 해결
import java.io.*;
import java.util.*;

public class Main {

	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int numOfVertex, numOfEdge;
	private static int[][] edgeList;
	private static int[] parents;

	public static void main(String[] args) throws IOException {
		kruskal();
	}

	private static void kruskal() throws IOException {
		input();
		System.out.println(run());
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		numOfVertex = Integer.parseInt(st.nextToken());
		numOfEdge = Integer.parseInt(st.nextToken());
		edgeList = new int[numOfEdge][3];
		parents = new int[numOfVertex + 1];
		make();

		for (int i = 0; i < numOfEdge; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int dist = Integer.parseInt(st.nextToken());
			edgeList[i] = new int[] { from, to, dist };
		}
		Arrays.parallelSort(edgeList, new EdgeComparator());
	}

	private static int run() {
		int cntOfUnion = 0;
		int sumOfWeight = 0;
		int idx = 0;
		while (cntOfUnion != numOfVertex - 1) {
			int[] now = edgeList[idx];
			int vertex1 = now[0];
			int vertex2 = now[1];
			int weight = now[2];
			if (union(vertex1, vertex2)) {
				cntOfUnion++;
				sumOfWeight += weight;
			}
			idx++;
		}
		return sumOfWeight;
	}

	private static void make() {
		for (int i = 1; i <= numOfVertex; i++)
			parents[i] = i;
	}

	private static int getParent(int child) {
		if (parents[child] == child)
			return child;
		return parents[child] = getParent(parents[child]);
	}

	private static boolean union(int a, int b) {
		int headOfA = getParent(a);
		int headOfB = getParent(b);
		if (headOfA == headOfB)
			return false;
		parents[headOfB] = headOfA;
		return true;
	}

	static class EdgeComparator implements Comparator<int[]> {

		@Override
		public int compare(int[] edge0, int[] edge1) {
			return Integer.compare(edge0[2], edge1[2]);
		}

	}
}
