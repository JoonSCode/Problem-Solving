//Main idea: 기능별 
import java.io.*;
import java.util.*;

public class Solution {

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		int T = Integer.parseInt(in.readLine());
		for (int i = 1; i <= T; i++) 
			sb.append("#").append(i).append(" ").append(test()).append("\n");
		
		System.out.println(sb.toString());
	}

	static int[][] magnets;
	static int[][] rotationOrders;
	static int numOfRotation, answer;
	static int test() throws NumberFormatException, IOException {
		magnets = new int[4][8];
		numOfRotation = Integer.parseInt(in.readLine());
		rotationOrders = new int[numOfRotation][2];
		for (int i = 0; i < 4; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int a = 0; a < 8; a++)
				magnets[i][a] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < numOfRotation; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			rotationOrders[i] = new int[] { Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) };
		}

		for (int[] rotationOrder : rotationOrders)
			rotation(rotationOrder);
		
		return getScore();
	}

	private static void rotation(int[] rotationOrder) {
		boolean[] isRotated = new boolean[4];
		rotateOne(isRotated, rotationOrder[0], rotationOrder[1]);
	}

	private static void rotateOne(boolean[] isRotated, int target, int dir) {
		isRotated[target] = true;
		if (target == 0) {
			if (!isRotated[target + 1] && isRightMove(target))
				rotateOne(isRotated, target + 1, -dir);
		} else if (target == 3) {
			if (!isRotated[target - 1] && isLeftMove(target))
				rotateOne(isRotated, target - 1, -dir);
		} else {
			if (!isRotated[target - 1] && isLeftMove(target))
				rotateOne(isRotated, target - 1, -dir);
			if (!isRotated[target + 1] && isRightMove(target))
				rotateOne(isRotated, target + 1, -dir);
		}
		rotateArr(target, dir);
	}

	private static boolean isLeftMove(int target) {
		return magnets[target][6] != magnets[target - 1][2];
	}

	private static boolean isRightMove(int target) {
		return magnets[target][2] != magnets[target + 1][6];
	}

	private static void rotateArr(int target, int dir) {
		if(dir == 1) {
			int val = magnets[target][0];
			for(int i = 1; i < 8; i++) {
				int tmp = magnets[target][i];
				magnets[target][i] = val;
				val = tmp;
			}
			magnets[target][0] = val;
		}
		else {
			int val = magnets[target][7];
			for(int i = 7; i > 0; i--) {
				int tmp = magnets[target][i - 1];
				magnets[target][i - 1] = val;
				val = tmp;
			}
			magnets[target][7] = val;
		}
	}
	
	private static int getScore() {
		int sum = 0;
		int mul = 1;
		for(int i = 0; i < 4; i++) {
			sum += magnets[i][0] * mul;
			mul *= 2;
		}
		return sum;
	}
}
