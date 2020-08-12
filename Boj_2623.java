//Main idea: 위상
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int numOfSinger, numOfScreenWriter;
	private static int[][] graph;
	private static int[] weightOfSinger;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		input();
		run();
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		numOfSinger = Integer.parseInt(st.nextToken());
		numOfScreenWriter = Integer.parseInt(st.nextToken());
		graph = new int[numOfSinger][numOfSinger];
		weightOfSinger = new int[numOfSinger];

		for (int i = 0; i < numOfScreenWriter; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			int sizeOfSequence = Integer.parseInt(st.nextToken());
			int now = -1;
			int next = -1;
			for (int a = 0; a < sizeOfSequence; a++) {
				if (now != -1) {
					next = Integer.parseInt(st.nextToken()) - 1;
					graph[now][next]++;
					weightOfSinger[next]++;
					now = next;
				} else
					now = Integer.parseInt(st.nextToken()) - 1;
			}
		}
	}

	private static void run() {
		Queue<Integer> que = new LinkedList<Integer>();
		pushZeroWeightSinger(que);
		int cnt = 0;
		while (!que.isEmpty()) {
			cnt++;
			int now = que.poll();
			sb.append(now + 1);
			sb.append("\n");
			deleteWeight(now);
			pushZeroWeightSinger(que);
		}

		if (cnt != numOfSinger)
			System.out.println(0);
		else
			System.out.println(sb.toString());
	}

	private static void pushZeroWeightSinger(Queue<Integer> que) {
		for (int i = 0; i < numOfSinger; i++) {
			if (weightOfSinger[i] != 0)
				continue;
			que.add(i);
			weightOfSinger[i] = -1;
		}
	}

	private static void deleteWeight(int from) {
		for (int to = 0; to < numOfSinger; to++) {
			if (graph[from][to] == 0)	continue;
			weightOfSinger[to] -= graph[from][to];
			graph[from][to] = 0;
		}
	}
}
