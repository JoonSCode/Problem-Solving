//Main idea: 플로이드 워셜 알고리즘 구현
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int numOfCity, numOfBus;
	private static int[][] busMap;
	public static void main(String[] args) throws IOException {
		test();
	
	}

	private static void test() throws IOException {
		input();
		floyd();
		for(int[] arr : busMap) {
			for(int a : arr)
				sb.append(a + " ");
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}

	private static void input() throws IOException {
		numOfCity = Integer.parseInt(in.readLine());
		numOfBus = Integer.parseInt(in.readLine());
		busMap = new int[numOfCity][numOfCity];
		for(int i = 0; i < numOfBus; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			int from = Integer.parseInt(st.nextToken()) - 1;
			int to = Integer.parseInt(st.nextToken()) - 1;
			int cost = Integer.parseInt(st.nextToken());	
			busMap[from][to] = (busMap[from][to] == 0)? cost : Math.min(busMap[from][to], cost);
		}
	}
	
	private static void floyd() {
		for(int stopover = 0; stopover < numOfCity; stopover++) {
			for(int from = 0; from < numOfCity; from ++) {
				if(from == stopover) continue;
				for(int to = 0; to < numOfCity; to++) {
					if(stopover == to || from == to) continue;
					if(busMap[from][stopover] != 0 && busMap[stopover][to] != 0)
						busMap[from][to] = (busMap[from][to] == 0)? busMap[from][stopover] + busMap[stopover][to] : Math.min(busMap[from][to], busMap[from][stopover] + busMap[stopover][to]);
				}
			}
		}
	}
}
