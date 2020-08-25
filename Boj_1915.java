//Main idea: Bottomup, dp유사
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int height, width, answer;
	private static int[][] map;
	private static Stack<Point> stack = new Stack<Point>();

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		while(!stack.isEmpty())
			run(stack.pop());
		System.out.println(answer*answer);
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine()," ");
		height = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		map = new int[height][width];
		for(int y = 0; y < height; y++) {
			char[]arr = in.readLine().toCharArray();
			for(int x = 0; x < width; x++) {
				map[y][x] = arr[x] -'0';
				if(map[y][x] == 1)
					stack.push(new Point(y, x));
			}
		}
		answer = (stack.size() != 0)? 1 : 0;
	}

	private static void run(Point point) {
		int y = point.y;
		int x = point.x;
		if(y == height - 1 || x == width - 1) return;
		int goal = Math.min(map[y+1][x+1] + 1, Math.min(height - y, width - x));
		while(!(map[y][x+1] >= goal - 1 && map[y+1][x] >= goal -1)) goal--;
		map[y][x] = goal;
		answer = Math.max(answer, goal);		
	}
}
	
class Point{
	int y,x;
	Point(int y, int x){
		this.y = y;
		this.x = x;
	}
}
