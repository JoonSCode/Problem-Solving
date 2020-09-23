//Main idea: X,Y 분리해서 
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		int W, H;
		W = in.nextInt();
		H = in.nextInt();
		int p = in.nextInt(), q = in.nextInt();
		int T = in.nextInt();
		int distX = T % (2 * W);
		if (distX > (W - p) * 2) {
			distX -= (W - p) * 2;
			if (distX > p)
				p = distX - p;
			else
				p -= distX;
		} else {
			if (distX <= W - p)
				p += distX;
			else
				p = W * 2 - distX - p;
		}
		
		int distY = T % (2 * H);
		if (distY > (H - q) * 2) {
			distY -= (H - q) * 2;
			if (distY > q)
				q = distY - q;
			else
				q -= distY;
		} else {
			if (distY <= H - q)
				q += distY;
			else
				q = H * 2 - distY - q;
		}
		System.out.println(p + " " + q);
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
