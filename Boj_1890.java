//Main idea: 메모이제이션
import java.io.*;
import java.util.*;


class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int sizeOfMap;
	private static int[][] gameMap;
	private static long[][] cache;
	public static void main(String[] args) throws IOException {
		test();
		out.flush();
		out.close();
	}

	private static void test() throws NumberFormatException, IOException {
		init();
		out.write(String.valueOf(dp(0,0)));
	}

	private static void init() throws IOException {
		sizeOfMap = Integer.parseInt(in.readLine());
		gameMap = new int[sizeOfMap][sizeOfMap];
		cache = new long[sizeOfMap][sizeOfMap];
		for(int y = 0; y < sizeOfMap; y++) {
			st = new StringTokenizer(in.readLine()," ");
			for(int x = 0; x < sizeOfMap; x++) 
				gameMap[y][x] = Integer.parseInt(st.nextToken());
		}
	}

	private static long dp(int y, int x) throws IOException {
		if(!isInBoundary(y, x)) return 0;
		long data = cache[y][x];
		if(data != 0) return data;
		
		int jumpCnt = gameMap[y][x];	
		if(y + x == sizeOfMap*2 -2) 
			return 1;
		if(jumpCnt == 0)return 0;
		return cache[y][x] = dp(y+ jumpCnt, x) + dp(y, x + jumpCnt);
	}
	
	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= sizeOfMap || x >=sizeOfMap)? false: true;
	}
}
