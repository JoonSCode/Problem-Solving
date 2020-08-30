//Main idea: LIS(이분탐색)
import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	private static int lengthOfSequence;
	private static int[] numbers;
	private static ArrayList<Integer> list;
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		init();
		run();
		System.out.println(list.size());
	}

	private static void init() throws NumberFormatException, IOException {
		lengthOfSequence = Integer.parseInt(in.readLine());
		numbers = new int[lengthOfSequence];
		list = new ArrayList<Integer>();
		st = new StringTokenizer(in.readLine(), " ");
		for (int y = 0; y < lengthOfSequence; y++) 
			numbers[y] = Integer.parseInt(st.nextToken());
		list.add(numbers[0]);
	}

	private static void run() {
		
		for(int i = 1; i < lengthOfSequence; i++) {
			if(list.get(list.size()-1) < numbers[i])
				list.add(numbers[i]);
			else 
				findNPush(0,list.size()-1,numbers[i]);
		}
	}
	
	private static void findNPush(int start, int end, int target){
		int mid = (start+end)/2;
		if(start + 1 >= end) {
			if(list.get(start) >= target)
				list.set(start, target);
			else
				list.set(end, target);
			return;
		}
		if(list.get(mid) < target) 
			findNPush(mid + 1, end, target);
		else 
			findNPush(start, mid, target);
	}
}
