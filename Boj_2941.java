//Main idea: 비교 줄이기
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;

	private static String str;
	private static int answer;
	private static String[] alp = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	public static void main(String[] args) throws IOException {
		alphabet();
	}

	private static void alphabet() throws IOException {
		str = in.readLine();

		for (int idx = 0; idx < str.length(); idx++) {
			String substr = (str.length() <= idx + 3)? str.substring(idx, str.length()) :str.substring(idx, idx + 3);
			for (int i = 0; i < 8; i++) {
				if(substr.length() < alp[i].length()) continue;
				if (substr.contains(alp[i])) {
					char tmp = str.charAt(idx);
					if (tmp == 'd' && str.charAt(idx + 1) == 'z')
						idx++;
					break;
				}
				if(i == 7) idx--;
			}
			idx++;
			answer++;
		}
		System.out.println(answer);
	}
}
