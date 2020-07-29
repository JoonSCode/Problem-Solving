//Main idea: 겹치는 idx 
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;

	private static char[][] paper;
	private static String str1,str2;
	public static void main(String[] args) throws IOException {
		puzzle();
	}

	private static void puzzle() throws IOException {
		st = new StringTokenizer(in.readLine()," ");
		str1 = st.nextToken();
		str2 = st.nextToken();
		paper = new char[str2.length()][str1.length()];
		int idx1 = -1, idx2 = 0;
		for(int i = 0; i < str1.length(); i++) {
			char tmp = str1.charAt(i);
			for(int j = 0; j < str2.length(); j++) {
				if(tmp == str2.charAt(j)){
					idx1 = i;
					idx2 = j;
					break;
				}
			}
			if(idx1 != -1)
				break;
		}
		int cnt = 0;
		for(int y = 0; y < str2.length(); y++) {
			if(y == idx2) {
				paper[y] = str1.toCharArray();
				cnt++;
				continue;
			}
			for(int x = 0; x < str1.length(); x++) {
				if(x == idx1) {
					paper[y][x] = str2.charAt(cnt);
					cnt++;
				}
				else
					paper[y][x] = '.';
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int y = 0; y < str2.length(); y++) {
			sb.append(paper[y]);
			sb.append("\n");
		}
		System.out.print(sb);
	}
}
