//Main idea: MST, 크루스칼로 
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int numOfComputer, numOfLan, answer;
	private static int[] parents;
	private static ArrayList<Network> arr; 
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		run();
		System.out.println(answer);
	}

	private static void input() throws IOException {
		numOfComputer = Integer.parseInt(in.readLine());
		numOfLan = Integer.parseInt(in.readLine());
		answer = 0;
		arr = new ArrayList<Network>();
		parents = new int[numOfComputer + 1];
		for (int y = 0; y < numOfLan; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			arr.add(new Network(a, b, c));
		}
		
		for(int i = 1; i <= numOfComputer; i++)
			parents[i] = i;
		Collections.sort(arr);
	}
	
	private static void run() {
		for(Network network : arr) {
			if(union(network.a, network.b))
				answer += network.weight;
		}
	}
	
	private static int find(int child) {
		if(child == parents[child]) return child;
		return parents[child] = find(parents[child]);
	}
	
	private static boolean union(int a, int b) {
		int ha = find(a);
		int hb = find(b);
		if(ha == hb) return false;
		parents[hb] = ha;
		return true;
	}
}

class Network implements Comparable<Network>{
	int a, b, weight;

	public Network(int a, int b, int weight) {
		super();
		this.a = a;
		this.b = b;
		this.weight = weight;
	}

	@Override
	public int compareTo(Network o) {
		return weight - o.weight;
	}
}
