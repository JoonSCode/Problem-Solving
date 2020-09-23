//Main idea: 시뮬레
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
		int numOfSwitch = in.nextInt();
		boolean[] switches = new boolean[numOfSwitch+1];
		for(int i = 1; i <= numOfSwitch; i++)
			switches[i] = (in.nextInt() == 1)? true : false;
		
		int numOfStudent = in.nextInt();
		for(int i = 0; i < numOfStudent; i++) {
			int sex = in.nextInt();
			int num = in.nextInt();
			
			if(sex == 1) {
				int a = num;
				while(a <= numOfSwitch) {
					switches[a] = !switches[a];
					a+=num;
				}
			}
			else {
				int a = num-1;
				int b = num +1;
				while(a>=1 && b <= numOfSwitch) {
					if(switches[a] == switches[b]) {
						a--;
						b++;
					}
					else
						break;
				}
				a++;
				b--;
				while(a <= b) {
					switches[a] = !switches[a];
					a++;
				}
			}
		}
		for(int i = 1; i <= numOfSwitch; i++) {
			if(switches[i]) sb.append("1");
			else sb.append("0");
			if(i%20 == 0)
				sb.append("\n");
			else
				sb.append(" ");
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
