//Main idea: 수학문제
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		play();
	}

	private static void play() throws IOException {
		long N = Long.parseLong(in.readLine());
		System.out.println((N%4 == 1 || N%4 == 3)? "SK" : "CY");
	}
}
