//Main idea: MST??
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int numOfRoad, numOfCity;
	private static long answer;
	private static int[] parents;
	private static ArrayList<Road> list = new ArrayList<Main.Road>();

	public static void main(String[] args) throws IOException {
		city();
	}

	private static void city() throws NumberFormatException, IOException {
		input();
		run();
		System.out.println(answer);
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine()," ");
		numOfCity = Integer.parseInt(st.nextToken());
		numOfRoad = Integer.parseInt(st.nextToken());
		parents = new int[numOfCity + 1];
		for(int i = 0; i < numOfRoad; i++) {
			st = new StringTokenizer(in.readLine()," ");
			int city1 = Integer.parseInt(st.nextToken());
			int city2 = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			list.add(new Road(city1, city2, weight));
		}
		Collections.sort(list);
	}

	private static void run() {
		int cnt = 0;
		answer = 0;
		
		for (Road road : list) {
			if(union(road.city1, road.city2)) {
				answer += road.weight;
				cnt++;
			}
			if(cnt == numOfCity - 2) break;
		}
	}
	
	private static int getParents(int child) {
		if(parents[child] == 0) return child;
		return parents[child] = getParents(parents[child]);
	}
	
	private static boolean union(int city1, int city2) {
		int headA = getParents(city1);
		int headB = getParents(city2);
		if(headA == headB) return false;
		parents[headB] = headA;
		return true;
	}
	
	static class Road implements Comparable<Road>{
		int city1, city2;
		int weight;
			
		public Road(int city1, int city2, int weight) {
			super();
			this.city1 = city1;
			this.city2 = city2;
			this.weight = weight;
		}

		@Override
		public int compareTo(Road o) {
			return this.weight - o.weight;
		}
	}
}
