//Main idea: 순환배열
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;

	private static int[] person;
	private static int cnt, L;
	public static void main(String[] args) throws IOException {
		play();
	}

	private static void play() throws IOException {
		st = new StringTokenizer(in.readLine()," ");
		person = new int[Integer.parseInt(st.nextToken())];
		cnt = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		
		int idx = 0;
		int answer = 0;
		while(true) {
			if(++person[idx] == cnt) break;
			if(person[idx]%2 == 1)
				idx += L;
			else
				idx -= L;
			if(idx >= L)
				idx %= person.length;
			else if(idx < 0) 
				idx = person.length - Math.abs(idx)%person.length;
			answer++;
		}
		System.out.println(answer);
	}
}
