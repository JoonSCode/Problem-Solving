//Main idea: 연산의 범위 지정이 중요하다.
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	static int R,G, answer;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		R = in.nextInt();
		G = in.nextInt();
		answer = 1;
		
		int gcd = R;
		int a = G;
		if(R <= G) {
			gcd = G;
			a = R;
		}
		
		while(a!=0) {
			int tmp = gcd % a;
			gcd = a;
			a = tmp;
		}
		
		for(int i = 1; i <= gcd; i++) {
			if(G%i != 0 || R % i != 0) continue;
			sb.append(i);
			sb.append(" ");
			sb.append(R/i);
			sb.append(" ");
			sb.append(G/i);
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
