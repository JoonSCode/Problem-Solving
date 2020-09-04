//Main idea: bfs, MST 결합!   프림알고리즘 만들 때 pq 중복처리 조심하자!
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	static int answer;
	static int N, M;
	static int[] dy = { -1, 0, 0, 1 };
	static int[] dx = { 0, -1, 1, 0 };
	static int[][] map;
	static ArrayList<ArrayList<int[]>> islands;
	static int[][] adj;
	static int[] parents;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		int size = 1;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x] != 0)
					continue;
				islands.add(new ArrayList<int[]>());
				map[y][x] = size;
				makeIsland(y, x, size++);//bfs를 이용해 섬들을 구분해 놓음
			}
		}
		adj = new int[size][size];
		for (int i = 1; i < size; i++)//구분 한 것들을 바탕으로 연결간선들을 생성한다.
			fillAdjList(i);
		PriorityQueue<int[]> pq = new PriorityQueue<int[]>(new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[1], o2[1]);
			}
		});

		int cnt = 0;
		pq.add(new int[] { 1, 0 });
		boolean[] isVisited = new boolean[size];
		int[] arr = new int[size];
		Arrays.fill(arr, Integer.MAX_VALUE);
		while (!pq.isEmpty() && cnt != size - 1) {//연결 간선을 바탕으로 프림 알고리즘 사용
			int[] tmp = pq.poll();
			int now = tmp[0];
			int dist = tmp[1];
			if (isVisited[now])
				continue;
			cnt++;
			answer += dist;
			isVisited[now] = true;
			for (int i = 1; i < size; i++) {
				if (isVisited[i])
					continue;
				if ((adj[now][i] == 0 || (arr[i] <= adj[now][i])))
					continue;
				arr[i] = adj[now][i];
				pq.add(new int[] { i, arr[i] });
			}
		}
		if (cnt != size - 1)
			System.out.println(-1);
		else
			System.out.println(answer);
	}

	static void input() throws IOException {
		N = in.nextInt();
		M = in.nextInt();
		answer = 0;
		map = new int[N][M];
		islands = new ArrayList<ArrayList<int[]>>();
		islands.add(new ArrayList<int[]>());
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				map[i][j] = in.nextInt() - 1;
		}
	}

	static void makeIsland(int y, int x, int no) {
		Queue<int[]> que = new LinkedList<int[]>();
		que.add(new int[] { y, x });
		while (!que.isEmpty()) {
			int[] tmp = que.poll();
			y = tmp[0];
			x = tmp[1];
			islands.get(no).add(new int[] { y, x });
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (!isInBoundary(ny, nx) || map[ny][nx] != 0)
					continue;
				map[ny][nx] = no;
				que.add(new int[] { ny, nx });
			}
		}
	}

	static void fillAdjList(int from) {
		Queue<Bridge> que = new LinkedList<Main.Bridge>();
		for (int[] p : islands.get(from)) {
			int y = p[0];
			int x = p[1];
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (!isInBoundary(ny, nx) || map[ny][nx] != -1)
					continue;
				que.add(new Bridge(ny, nx, i));
			}
		}
		int dist = 0;
		while (!que.isEmpty()) {
			dist++;
			int size = que.size();
			while (--size >= 0) {
				Bridge br = que.poll();
				int y = br.y + dy[br.dir];
				int x = br.x + dx[br.dir];
				if (!isInBoundary(y, x) || map[y][x] == from)
					continue;
				int to = map[y][x];
				if (to == -1) {
					br.y = y;
					br.x = x;
					que.add(br);
				} else if (dist >= 2)
					adj[to][from] = adj[from][to] = (adj[from][to] == 0) ? dist : Math.min(dist, adj[from][to]);
			}
		}
	}

	static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= N || x >= M) ? false : true;
	}

	static class Bridge {
		int y, x, dir;

		public Bridge(int y, int x, int dir) {
			super();
			this.y = y;
			this.x = x;
			this.dir = dir;
		}
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
