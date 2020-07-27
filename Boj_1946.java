//Main idea: 정렬, 나보다 한과목 순위가 높은사람들이 다른 과목은 나보다 낮은지 한번에 찾는 방법
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int numOfParticipant;
	static int[] arr1,arr2;
	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(br.readLine());
		for(int i = 0; i < T; i++) 
			run();		
	}
	
	static void run() throws NumberFormatException, IOException {
		int answer = 0;
		numOfParticipant = Integer.parseInt(br.readLine());
		arr1 = new int[numOfParticipant + 1];
		arr2 = new int[numOfParticipant + 1];
		StringTokenizer st;
		
		for(int n = 0; n < numOfParticipant; n++) {
			st = new StringTokenizer(br.readLine(), " ");
			arr1[Integer.parseInt(st.nextToken())] = Integer.parseInt(st.nextToken());
		}
		
		arr2[0] = numOfParticipant+1;
		for(int i = 1; i <= numOfParticipant; i++) {
			arr2[i] = Math.min(arr2[i-1], arr1[i]);
			if(arr1[i] == arr2[i])
				answer++;
		}
		
		System.out.println(answer);
	}
}
