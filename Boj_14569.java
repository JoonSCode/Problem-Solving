//Main idea: 비트 
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	static int answer, numOfSubject, numOfStudent;
	static long[] isPossible;
	static long[] timeTables;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {

		numOfSubject = in.nextInt();
		timeTables = new long[numOfSubject];

		for (int i = 0; i < numOfSubject; i++) {
			st = new StringTokenizer(in.readLine());
			int k = Integer.parseInt(st.nextToken());
			long tmp = 0;
			long t = 1;
			for (int a = 0; a < k; a++) 
				tmp |= t << Integer.parseInt(st.nextToken());
			timeTables[i] = tmp;
		}
		
		numOfStudent = in.nextInt();
		isPossible = new long[numOfStudent];
		for (int i = 0; i < numOfStudent; i++) {
			st = new StringTokenizer(in.readLine());
			int p = Integer.parseInt(st.nextToken());
			long t = 1;
			for (int a = 0; a < p; a++)
				isPossible[i] |= t << Long.parseLong(st.nextToken());
		}
		
		for(long student : isPossible) {
			answer = 0;
			for(long timetable: timeTables) {
				if ((timetable & student) == timetable)	
					answer++;
			}
			sb.append(answer);
			sb.append("\n");
		}
		System.out.println(sb.toString());
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
