//Main idea: 그래프 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int[][] region;
	static int[][] isVisited;
	static int sizeOfArr;
	static int[] dx = {-1,0,0,1};
	static int[] dy = {0,-1,1,0};
	public static void main(String[] args) throws IOException {
		int answer = 1;	
		sizeOfArr = Integer.parseInt(br.readLine());
		region = new int[sizeOfArr][sizeOfArr];
		HashSet<Integer> set = new HashSet<Integer>();
		
		for(int y = 0; y < sizeOfArr; y++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			for(int x =0 ; x < sizeOfArr; x++) {
				region[y][x] = Integer.parseInt(st.nextToken());
				set.add(region[y][x]);
			}
		}
		
		for(int a : set) 
			answer = Math.max(answer, getNumOfSafeArea(a));
		
		System.out.println(answer);
	}
	
	private static int getNumOfSafeArea(int h) {
		isVisited = new int[sizeOfArr][sizeOfArr];
		int numOfSafeArea = 0;
		for(int y = 0; y < sizeOfArr; y++) {
			for(int x =0 ; x < sizeOfArr; x++) {
				if(region[y][x] <= h || isVisited[y][x] == 1) continue;
				isVisited[y][x] = 1;
				numOfSafeArea++;
				dfs(h,y,x);
			}
		}
		return numOfSafeArea;
	}
	
	private static void dfs(int h, int y, int x) {
		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 | ny >= sizeOfArr || nx >= sizeOfArr) continue;
			if(region[ny][nx] <= h || isVisited[ny][nx] == 1) continue;
			isVisited[ny][nx] = 1;
			dfs(h,ny,nx);
		}
	}
	
}
