//Main idea: LCA(Lowest Common Ancestor)
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int[] family;
	private static int sizeOfPerson, personA, personB;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		input();
		ArrayList<Integer> parentToRootA = getParentToRoot(personA);
		ArrayList<Integer> parentToRootB = getParentToRoot(personB);
		int distanceToCommonDescent = getDistanceToCommonDescent(parentToRootA, parentToRootB);
		System.out.println(distanceToCommonDescent);
	}

	private static void input() throws IOException {
		sizeOfPerson = Integer.parseInt(in.readLine());
		family = new int[sizeOfPerson + 1];
		st = new StringTokenizer(in.readLine(), " ");
		personA = Integer.parseInt(st.nextToken());
		personB = Integer.parseInt(st.nextToken());

		int M = Integer.parseInt(in.readLine());
		for (int y = 0; y < M; y++) {
			st = new StringTokenizer(in.readLine(), " ");
			int parent = Integer.parseInt(st.nextToken());
			int child = Integer.parseInt(st.nextToken());
			family[child] = parent;
		}
	}

	private static ArrayList<Integer> getParentToRoot(int cur) {
    	ArrayList<Integer> parentToRoot = new ArrayList<Integer>();
    	while(cur != 0) {
    		parentToRoot.add(cur);
    		cur = family[cur];
    	}
		return parentToRoot; 	
    }

	private static int getDistanceToCommonDescent(ArrayList<Integer> parentToRootA, ArrayList<Integer> parentToRootB) {
		int idxA = parentToRootA.size()-1;
		int idxB = parentToRootB.size()-1;
		int nowA = parentToRootA.get(idxA);
		int nowB = parentToRootB.get(idxB);
		if(nowA != nowB)
			return -1;
		while((idxA != 0 && idxB != 0) && nowA == nowB) {
			nowA = parentToRootA.get(--idxA);
			nowB = parentToRootB.get(--idxB);
		}
		int answer = idxA + idxB + 2;
		if((idxA == 0 || idxB == 0) && nowA == nowB)
			answer -= 2;
		return answer;
	}
}
