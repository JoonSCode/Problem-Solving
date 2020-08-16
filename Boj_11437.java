//Main idea: LCA
import java.io.*;
import java.util.*;

public class Boj_11437 {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int[] parentsNode = new int[50001];//각 노드의 부모를 저장
	private static int[] depth = new int[50001];//각 노드들의 깊이를 저장
	private static ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>();//인접 리스트로 공간을 적게 사용
	private static int numOfNode, numOfQuestion;
	private static int[][] questions;

	public static void main(String[] args) throws IOException {
		lca();
	}

	private static void lca() throws NumberFormatException, IOException {
		input();
		init();
		for (int[] question : questions)
			run(question);
		sb.deleteCharAt(sb.length() - 1);
		System.out.print(sb.toString());
	}

	private static void input() throws IOException {
		numOfNode = Integer.parseInt(in.readLine());
		for (int y = 0; y <= numOfNode; y++)
			adjList.add(new ArrayList<Integer>());//인접 리스트 할당
		for (int y = 0; y < numOfNode - 1; y++) {//인접리스트 입력
			st = new StringTokenizer(in.readLine(), " ");
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			adjList.get(from).add(to);
			adjList.get(to).add(from);
		}
		numOfQuestion = Integer.parseInt(in.readLine());
		questions = new int[numOfQuestion][2];
		for (int i = 0; i < numOfQuestion; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			int num1 = Integer.parseInt(st.nextToken());
			int num2 = Integer.parseInt(st.nextToken());
			questions[i] = new int[] { num1, num2 };
		}
	}

	private static void init() {
		Queue<Integer> que = new LinkedList<Integer>();
		que.add(1);
		parentsNode[1] = 1;
		int d = 0;
		while (!que.isEmpty()) {
			int size = que.size();
			d++;
			while (--size >= 0) {//depth 별로 bfs
				int now = que.poll();
				int parent = parentsNode[now];
				for (int child : adjList.get(now)) {
					if (child == parent)//나에게서 연결 된 것은 부모 1개, 나머지는 자식
						continue;
					parentsNode[child] = now;
					que.add(child);
					depth[child] = d;
				}
			}
		}
	}

	private static void run(int[] question) {
		int num1 = question[0];
		int num2 = question[1];
		int x = num1;
		int y = num2;
		if (depth[num1] > depth[num2]) {
			x = num2;
			y = num1;
		}
		findLca(x, y);
	}

	private static void findLca(int x, int y) {
		while (depth[x] != depth[y])//두 노드의 depth를 맞춘다.
			y = parentsNode[y];
		if (x == y)
			sb.append(x);
		else {
			while (parentsNode[x] != parentsNode[y]) {//공통 조상이 나올 때 까지 반복
				x = parentsNode[x];
				y = parentsNode[y];
			}
			sb.append(parentsNode[x]);
		}
		sb.append("\n");
	}
}
