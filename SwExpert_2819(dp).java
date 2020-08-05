//Main idea: hash set으로 짠 것을 dp로
import java.io.*;
import java.util.*;

public class Solution {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int[][] map;
	private static ArrayList<ArrayList<Set<String>>> cache;//[y,x를 이용한 position][앞에서 몇번째에 현재 위치의 숫자를 넣을 것인지] -> 만들 수 있는 숫자 set
	private static int N = 4;
	private static int[] dy = { 0, 0, -1, 1 }, dx = { -1, 1, 0, 0 };

	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; i++) {
			sb.append("#");
			sb.append(i + 1);
			sb.append(" ");
			test();
			sb.append("\n");
		}
		System.out.print(sb);
	}

	private static void test() throws IOException {
		input();
		Set<String> set = new HashSet<String>();
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) 
				set.addAll(dp(y, x, 0));
		}
		sb.append(set.size());
	}

	private static void input() throws IOException {
		map = new int[4][4];
		cache = new ArrayList<ArrayList<Set<String>>>();
		for (int y = 0; y < N; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int x = 0; x < N; x++) {
				map[y][x] = Integer.parseInt(st.nextToken());
				cache.add(new ArrayList<Set<String>>());//cache 초기화
				for(int k = 0; k < 7; k++)
					cache.get(y*4 + x).add(new HashSet<String>());
				cache.get(y*4 + x).get(6).add(String.valueOf(map[y][x]));
			}
		}
	}

	private static Set<String> dp(int y, int x, int cnt) {
		Set<String> org = cache.get(y*4 + x).get(cnt);
		if (org.size() != 0) //이미 처리한 경우 바로 리턴
			return org;
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!isInBoundary(ny, nx))
				continue;
			char suffix = (char) (map[y][x] + '0');
			sumTwoSetWithSuffix(org, dp(ny,nx, cnt + 1), suffix);
			/*map[ny][nx]를 suffix로 한 cnt+2 크기의 string set을 가져온다.  
			해당 string들에 현재위치의 값(map[y][x])을 suffix로 하여 현재 값에 해당하는 set 에 넣고 반환 */
		}
		return org;
	}
	
	private static boolean isInBoundary(int y, int x) {//범위체크
		return (y < 0 || x < 0 || y >= N || x >= N) ? false : true;
	}
	
	private static void sumTwoSetWithSuffix(Set<String> org, Set<String> sec, char suffix){
		for(String str: sec) {
			StringBuilder tmpSb = new StringBuilder();
			tmpSb.append(str);
			tmpSb.append(suffix);
			org.add(tmpSb.toString());
		}
	}
}
