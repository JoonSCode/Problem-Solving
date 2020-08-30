//Main idea: Heap (2개 이용)
import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	private static int nums;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		init();
		run();
		System.out.println(sb.toString());
	}

	private static void init() throws NumberFormatException, IOException {
		nums = Integer.parseInt(in.readLine());
	}

	private static void run() throws IOException {
		PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();
		PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(o2, o1);
			}
		});

		int num = 0;
		for (int i = 0; i < nums; i++) {
			num = Integer.parseInt(in.readLine());
			if (maxHeap.isEmpty() || maxHeap.peek() > num)
				maxHeap.add(num);
			else
				minHeap.add(num);

			if(maxHeap.size() > minHeap.size() + 1) 
				minHeap.add(maxHeap.poll());
			else if(maxHeap.size() < minHeap.size()) 
				maxHeap.add(minHeap.poll());
			
			sb.append(maxHeap.peek());
			sb.append("\n");
		}
	}
}
