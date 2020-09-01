//Main idea: TRIE 자료구조 
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int numOfPhoneNo;
	private static Node[] list;
	private static ArrayList<char[]> phoneNums;
	
	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; i++)
			test();
		System.out.println(sb.toString());
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		sb.append((run())? "YES" : "NO");
		sb.append("\n");
	}

	private static void input() throws IOException {
		numOfPhoneNo = Integer.parseInt(in.readLine());
		list = new Node[26];
		phoneNums = new ArrayList<char[]>();
		for (int i = 0; i < numOfPhoneNo; i++) 
			phoneNums.add(in.readLine().toCharArray());
		Collections.sort(phoneNums, new Comparator<char[]>() {

			@Override
			public int compare(char[] o1, char[] o2) {
				return o1.length- o2.length;
			}
		});
	}

	private static boolean run() {
		for(char[] phoneNo : phoneNums) {
			if(!makeTrie(phoneNo))
				return false;
		}
		return true;
	}
	
	static boolean makeTrie(char[] arr) {
		int idx = 0;
		Node now = list[arr[idx++]-'0'];
		if(now == null) 
			now = list[arr[idx-1] -'0'] = new Node();
		while(idx != arr.length) {
			if(now.isEnd) 
				return false;
			if (now.next[arr[idx++]-'0'] == null)
				now = now.next[arr[idx-1]-'0'] = new Node();
			else
				now = now.next[arr[idx-1]-'0'];
		}
		now.isEnd = true;
		return true;
	}
}
class Node{
	boolean isEnd;
	Node[] next;
	
	Node(){
		isEnd = false;
		next = new Node[26];
	}
}
