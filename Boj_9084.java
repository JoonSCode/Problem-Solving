//Main idea: a원을 만들 수 있는 경우의 수 점화식
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	

	private static int numOfCoin;
	private static int[] coins;
	private static int[] cache;//cache[idx] = idx원을 만들 수 있는 경우의 수
	private static int targetAmount;
	
	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(in.readLine());
		for(int i = 0; i < T; i++)
			coin();
		System.out.println(sb);
	}
	
	private static void coin() throws NumberFormatException, IOException {
		numOfCoin = Integer.parseInt(in.readLine());
		init();
		st = new StringTokenizer(in.readLine()," ");
		for(int i = 0; i < numOfCoin; i++) 
			coins[i] = Integer.parseInt(st.nextToken());
		
		targetAmount = Integer.parseInt(in.readLine());
		
		for(int val : coins) 
			if(val <= targetAmount) run(val);
		sb.append(cache[targetAmount] + "\n");
	}
	
	private static void init() {
		coins = new int[numOfCoin];
		cache = new int[10001];
		cache[0] = 1;//0원은 무조건 만들 수 있음
	}
	
	private static void run(int val) {
		for(int i = 0; i <= targetAmount-val; i++) 
			cache[i+val] += cache[i];
	}
}
