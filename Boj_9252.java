//Main idea: LCS 생성후 역추적
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	private static String str1, str2;
	private static int ans;
	private static int[][] cache;

	public static void main(String[] args) throws IOException {
		city();
	}

	private static void city() throws NumberFormatException, IOException {
		input();
		run();
		ans = cache[0][0];
		System.out.println(ans);
		if(ans != 0)
			System.out.println(sb.toString());
	}

	private static void input() throws IOException {
		str1 = in.readLine();
		str2 = in.readLine();
		if (str1.length() > str2.length()) {
			String tmp = str1;
			str1 = str2;
			str2 = tmp;
		}
		cache = new int[str1.length()+1][str2.length()+1];
	}

	private static void run() {
		dp();
		findLCS(0,0);
	}

	private static void dp() {
		for (int y = str1.length() - 1; y >= 0; y--) {
			char a = str1.charAt(y);
			for (int x = str2.length() - 1; x >= 0; x--) {
				cache[y][x] = Math.max(cache[y+1][x], cache[y][x+1]);
				if(a == str2.charAt(x)) 
					cache[y][x] = Math.max(cache[y][x], cache[y+1][x+1]+1);
			}
		}
	}
	
	private static void findLCS(int y, int x) {
		int cnt = cache[y][x];
		if(cnt == 0) return;
		for(; x <= str2.length(); x++) {
			if(cache[y][x] == cnt) continue;
			x--;
			for(; y <= str1.length(); y++) {
				if(cache[y][x] == cnt) continue;
				y--;
				sb.append(str1.charAt(y));
				findLCS(y+1, x+1);
				return;
			}
			break;
		}
	}
}
