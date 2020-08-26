//Main idea: 기능별로 나눠서 시뮬레이션 + 순열
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int height, width, numOfOrder, answer;
	private static int[][] map;
	private static int[] dy = {0,1,0,-1}, dx = {1,0,-1,0};
	private static ArrayList<Order> orders = new ArrayList<Order>();
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		run();
		System.out.println(answer);
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine()," ");
		height = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		numOfOrder = Integer.parseInt(st.nextToken());
		map = new int[height][width];
		answer = (int)2e31-1;
    
		for (int y = 0; y < height; y++) {
			st = new StringTokenizer(in.readLine()," ");
			for(int x = 0; x < width; x++) 	
				map[y][x] = Integer.parseInt(st.nextToken());
		}
		for(int i = 0; i <numOfOrder; i++) {
			st = new StringTokenizer(in.readLine()," ");
			int r = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken()) - 1;
			int s = Integer.parseInt(st.nextToken());
			orders.add(new Order(r, c, s));
		}
	}
	
	private static void run() {
		int[] arr = new int[numOfOrder];
		for(int i = 0 ; i < numOfOrder; i++)
			arr[i] = i;
		do {
			int[][] copyMap = copy(map);
			for(int a : arr) {
				Order order = orders.get(a);
				rotation(copyMap, order.y, order.x, order.size);
			}
			answer = Math.min(getValueOfArr(copyMap), answer);
		}while(nextPermutation(arr));
	}

	private static void rotation(int[][] map, int r, int c, int s) {
		int y = r;
		int x = c;
		int size = s;
		if(size == 0) return;
		
		int sy = y - size;
		int sx = x - size;
		int idx = 0;
		
		int ny = sy;
		int nx = sx;
		int bubble = map[ny][nx];
    
		do {
			for(int i = 0; i < size*2; i++) {
				int tmp = map[ny+=dy[idx]][nx+=dx[idx]];
				map[ny][nx] = bubble;
				bubble = tmp;
			}
			idx++;
		}while(ny != sy || nx != sx);
		
		rotation(map, r, c, size - 1);
	}
	
	private static int getValueOfArr(int[][] map) {
		int ans = (int)2e31-1;
		for(int i = 0; i < map.length; i++) {
			int sum = 0;
			for(int a = 0; a < map[i].length; a++)
				sum += map[i][a];
			ans = Math.min(ans, sum);
		}
		return ans;
	}
	
	private static int[][] copy(int[][] org) {
		int[][] tmp = org.clone();
		for(int i = 0; i < org.length; i++) 
			tmp[i] = org[i].clone();
		return tmp;
	}
	
	private static boolean nextPermutation(int[] arr) {
		int i = arr.length-1;
		while(i > 0 && arr[i-1] >= arr[i]) i--;
		if(i == 0) return false;
		
		int j = arr.length-1;
		while(arr[i-1] >= arr[j]) j--;
		swap(arr,i-1,j);
		int k = arr.length-1;
		while(i < k) swap(arr, i++, k--);
		return true;
	}
	
	private static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

class Order{
	int y,x,size;

	public Order(int y, int x, int size) {
		super();
		this.y = y;
		this.x = x;
		this.size = size;
	}
}
