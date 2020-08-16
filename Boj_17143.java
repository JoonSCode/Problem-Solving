//Main idea: 기능별로 함수를 나누어서 구현!, 상어가 먹히는 경우를 잘 고려해야 한다.
import java.io.*;
import java.util.*;

public class Boj_17143 {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;

	private static int height, width, numOfShark, answer;
	private static Shark[][] ocean;
	private static LinkedList<Shark> sharkList = new LinkedList<Shark>();
	private static int[] dy = { -1, 1, 0, 0 }, dx = { 0, 0, 1, -1 };

	public static void main(String[] args) throws IOException {
		fishing();
	}

	private static void fishing() throws NumberFormatException, IOException {
		input();
		run();
		System.out.println(answer);
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		height = Integer.parseInt(st.nextToken());
		width = Integer.parseInt(st.nextToken());
		numOfShark = Integer.parseInt(st.nextToken());
		answer = 0;
		ocean = new Shark[height][width];

		for (int i = 0; i < numOfShark; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			int y = Integer.parseInt(st.nextToken()) - 1;
			int x = Integer.parseInt(st.nextToken()) - 1;
			int speed = Integer.parseInt(st.nextToken());
			int dir = Integer.parseInt(st.nextToken()) - 1;
			int size = Integer.parseInt(st.nextToken());
			Shark shark = new Shark(y, x, speed, dir, size);
			ocean[y][x] = shark;
			sharkList.add(shark);
		}
	}

	private static void run() {
		for (int i = 0; i < width; i++) {
			catchShark(i);
			for (Iterator<Shark> iterator = sharkList.iterator(); iterator.hasNext();) {
				Shark shark = (Shark) iterator.next();
				moveShark(shark);
			}
			for (Iterator<Shark> iterator = sharkList.iterator(); iterator.hasNext();) {
				Shark shark = (Shark) iterator.next();
				if(shark.speed == -1) {
					iterator.remove();
					continue;
				}
				shark.isMoved = false;
			}
		}
	}

	private static void moveShark(Shark shark) {
		int dir = shark.dir;
		int y = shark.y;
		int x = shark.x;
		int speed = shark.speed;
		if(ocean[y][x] == shark)
			ocean[y][x] = null;
		while (speed != 0) {
			speed--;
			y += dy[dir];
			x += dx[dir];
			if (isInBoundary(y, x))
				continue;
			if (dir % 2 == 0)
				dir++;
			else
				dir--;
			y += dy[dir] * 2;
			x += dx[dir] * 2;
		}
		shark.y = y;
		shark.x = x;
		shark.dir = dir;
		shark.isMoved = true;

		Shark tmp = ocean[y][x];
		if (tmp != null && tmp.isMoved == true) {
			if(tmp.size > shark.size) 
				shark.speed = -1;//이동해서 먹힌 경우 다음에 삭제하기 위해 표시
			else if(tmp.size == shark.size) //상어가 다시 원래 위치로 온 경우
				ocean[y][x] = shark;
			else {//이 위치에 있던 상어를 먹은 경우
				ocean[y][x] = shark;
				tmp.speed = -1;//다음에 삭제하기 위해 표시
			}
		} else 
			ocean[y][x] = shark;
	}

	private static void catchShark(int idx) {
		for (int y = 0; y < height; y++) {
			Shark shark = ocean[y][idx];
			if (shark == null || shark.speed == -1)
				continue;
			shark.speed = -1;
			answer += shark.size;
			sharkList.remove(shark);
			return;
		}
	}
	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= height || x >= width) ? false : true;
	}
}

class Shark {
	int y, x, speed, dir, size;
	boolean isMoved = false;

	public Shark(int y, int x, int speed, int dir, int size) {
		super();
		this.y = y;
		this.x = x;
		this.speed = speed;
		this.dir = dir;
		this.size = size;
	}

	@Override
	public String toString() {
		return "[y=" + y + ", x=" + x + ", speed=" + speed + ", dir=" + dir + ", size=" + size + "]";
	}
}
