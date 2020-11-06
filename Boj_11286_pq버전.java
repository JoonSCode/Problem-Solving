//Main idea: pq 
import java.io.*;
import java.util.*;

public class Main {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int numOfOrder = Integer.parseInt(in.readLine());
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if(Math.abs(o1) == Math.abs(o2))
					return Integer.compare(o1, o2);
				else
					return Math.abs(o1) - Math.abs(o2);
			}
		});
		
		for(int i = 0; i < numOfOrder; i++) {
			int order = Integer.parseInt(in.readLine());
			if(order == 0) 
				System.out.println((pq.isEmpty()) ? 0 : pq.poll());
			else
				pq.offer(order);
		}
	}
}
