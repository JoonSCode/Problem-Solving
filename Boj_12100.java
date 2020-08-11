//Main idea: 완전탐색 2차원 배열 복사에 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static Block[][] board;
	private static int sizeOfBoard, answer;

	public static void main(String[] args) throws IOException {
		tsp();
	}

	private static void tsp() throws NumberFormatException, IOException {
		init();
		game(board, 0);

		System.out.println(answer);
	}

	private static void init() throws IOException {
		sizeOfBoard = Integer.parseInt(in.readLine());
		board = new Block[sizeOfBoard][sizeOfBoard];
		answer = 0;
		for (int y = 0; y < sizeOfBoard; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int x = 0; x < sizeOfBoard; x++) {
				board[y][x] = new Block(Integer.parseInt(st.nextToken()), false);
				answer = Math.max(answer, board[y][x].val);
			}
		}
	}

	private static void game(Block[][] gameBoard, int cnt) {
		if (cnt == 5)
			return;
		for (int i = 0; i < 4; i++) {
			Block[][] newGameBoard = deepCopy(gameBoard);
			if (move(newGameBoard, i)) 
				game(newGameBoard, cnt + 1);
		}
	}

	private static boolean move(Block[][] gameBoard, int dir) {
		boolean isMove = false;
		if (dir <= 1) {
			for (int y = 0; y < sizeOfBoard; y++) {
				for (int x = 0; x < sizeOfBoard; x++) {
					boolean tmp = merge(gameBoard, y, x + (sizeOfBoard - 1 - 2 * x) * dir, dir);
					isMove = (isMove) ? true : tmp;
				}
			}
		} else {
			for (int x = 0; x < sizeOfBoard; x++) {
				for (int y = 0; y < sizeOfBoard; y++) {
					boolean tmp = merge(gameBoard, y + (sizeOfBoard - 1 - 2 * y) * (dir % 2), x, dir);
					isMove = (isMove) ? true : tmp;
				}
			}
		}
		initIsSummed(gameBoard);
		return isMove;
	}

	private static boolean merge(Block[][] gameBoard, int y, int x, int dir) {
		if (gameBoard[y][x].val == 0)
			return false;
		int ny = y;
		int nx = x;
		Block now = gameBoard[y][x];
		if (dir == 0) {
			while (true) {
				nx--;
				if (!isInBoundary(ny, nx)) {
					nx++;
					break;
				}
				Block next = gameBoard[ny][nx];
				if (next.val == 0)
					continue;
				if (canSum(now, next)) {
					sumBlock(next, now);
					return true;
				}
				nx++;
				break;
			}
		} else if (dir == 1) {
			while (true) {
				nx++;
				if (!isInBoundary(ny, nx)) {
					nx--;
					break;
				}
				Block next = gameBoard[ny][nx];
				if (next.val == 0)
					continue;
				if (canSum(now, next)) {
					sumBlock(next, now);
					return true;
				}
				nx--;
				break;
			}
		} else if (dir == 2) {
			while (true) {
				ny--;
				if (!isInBoundary(ny, nx)) {
					ny++;
					break;
				}
				Block next = gameBoard[ny][nx];
				if (next.val == 0)
					continue;
				if (canSum(now, next)) {
					sumBlock(next, now);
					return true;
				}
				ny++;
				break;
			}
		} else {
			while (true) {
				ny++;
				if (!isInBoundary(ny, nx)) {
					ny--;
					break;
				}
				Block next = gameBoard[ny][nx];
				if (next.val == 0)
					continue;
				if (canSum(now, next)) {
					sumBlock(next, now);
					return true;
				}
				ny--;
				break;
			}
		}
		if (y != ny || x != nx) {
			gameBoard[ny][nx].val = gameBoard[y][x].val;
			gameBoard[y][x].val = 0;
			return true;
		}
		return false;
	}

	private static Block[][] deepCopy(Block[][] org) {
		Block[][] copy = new Block[sizeOfBoard][sizeOfBoard];
		for (int i = 0; i < org.length; i++) {
			for(int x = 0;x < org.length; x++) {
				copy[i][x] = org[i][x].clone();
			}
		}
		return copy;
	}

	private static void initIsSummed(Block[][] gameBoard) {
		for (int y = 0; y < sizeOfBoard; y++) {
			for (int x = 0; x < sizeOfBoard; x++)
				gameBoard[y][x].isSummed = false;
		}
	}

	private static boolean isInBoundary(int y, int x) {
		return (y < 0 || x < 0 || y >= sizeOfBoard || x >= sizeOfBoard) ? false : true;
	}

	private static boolean canSum(Block now, Block next) {
		return ((!now.isSummed && !next.isSummed) && (now.val == next.val)) ? true : false;
	}

	private static void sumBlock(Block a, Block b) {
		a.val += b.val;
		a.isSummed = true;
		b.val = 0;
		answer = Math.max(answer, a.val);
	}

	static class Block {
		int val;
		boolean isSummed = false;

		public Block(int val, boolean isSummed) {
			super();
			this.val = val;
			this.isSummed = isSummed;
		}

		@Override
		public String toString() {
			return val + " ";
		}
		
		public Block clone() {
			return new Block(val, isSummed);
		}
	}
}
