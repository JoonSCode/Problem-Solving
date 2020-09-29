//Main idea: 페르마의 소정리, 빠른 거듭제곱
import java.io.*;
import java.util.StringTokenizer;

public class Solution {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static long[] fact;
	static final int INF = 1234567891;
	public static void main(String[] args) throws NumberFormatException, IOException {
		fact = new long[1000001];
		fact[1] = 1;
		for(int i = 2; i <= 1000000; i++) 
			fact[i] = fact[i-1] * i % INF;
		
		int T = Integer.parseInt(in.readLine());
		for(int i = 1; i <= T; i++) {
			sb.append("#");
			sb.append(i);
			sb.append(" ");
			sb.append(test());
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
	

	static long test() throws IOException {
		int N, R;
		st = new StringTokenizer(in.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		long ans = fact[N]% INF*power(fact[N-R], INF-2, INF)%INF*power(fact[R], INF-2, INF)%INF;
		
		return ans;
	}
	static long power(long fact2, int p, int div) {
		if(p == 1)
			return fact2;
		long tmp = power(fact2,p/2, div);
		tmp =(tmp*tmp)%div;
		if(p%2 != 0)
			tmp*= fact2;
		return tmp % div;
	}
}
