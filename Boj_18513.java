//Main idea: 답의 범위에 주의 하자, 변수 초기화 주의    bfs
import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int numOfBBQ, numOfHouse, dist;// 치킨집 수, 집 수, 정답, 치킨 거리 변수 선언
	static long ans;
	static LinkedList<Integer> BBQ;// 치킨집의 위치를 저장할 배열 선언
	static HashMap<Integer, Boolean> map;// 치킨집들의 위치를 저장해놓기 위해 사용 -> 집 지을 수 있는지 여부 확인 때 빠르게 알기 위해서 사용
	static int candSize;// 치킨 거리 기준으로 지을 수 있는 집의 수 저장하기 위한 변수

	public static void main(String[] args) throws IOException {
		input();// 입력받는 함수 선언
		while (numOfHouse != 0) {// 집을 다 지을 때 까지 반복
			ans += (Math.min(numOfHouse, candSize) * dist);// 남은 집의 수, 후보군의 수 중 적은 수 * 기준거리 만큼 답에 더한다.
			numOfHouse -= Math.min(numOfHouse, candSize);// 남은 집의 수, 후보군의 수 중 적은 수를 남은 집의 수 에서 뺀다.
			dist++;// 치킨거리를 늘려서 다시 후보지 추가하기 위해 치킨거리 증가
			refreshQueue();// 새로운 치킨거리 기준으로 후보지 추가
		}
		System.out.println(ans);// 답 출력
	}

	static void input() throws IOException {// 입력받고 초기화 하는 코드들을 모아놓은 곳
		st = new StringTokenizer(in.readLine(), " ");// 키보드 입력 받은 스트링을 공백 기준으로 자른다
		numOfBBQ = Integer.parseInt(st.nextToken());// 자른 스트링을 정수로 변환하고 변수에 대입
		numOfHouse = Integer.parseInt(st.nextToken());// 자른 스트링을 정수로 변환하고 변수에 대입
		BBQ = new LinkedList<Integer>();// 변수 초기화
		map = new HashMap<Integer, Boolean>();// 변수 초기화
		ans = 0;// 정답 0으로 초기화
		dist = 1;// 치킨거리 1로 초기값 설정
		st = new StringTokenizer(in.readLine(), " ");// 키보드 입력 받은 스트링을 공백 기준으로 자른다 치킨집 정보들
		for (int i = 0; i < numOfBBQ; i++) { // 모든 치킨집의 위치를 받기 위해 반복문 설정
			BBQ.add(Integer.parseInt(st.nextToken()));// 치킨집의 위치를 받고 바로 배열에 넣음
			map.put(BBQ.getLast(), false);// 미리 맵에 넣어놔서 집 위치 후보에서 제외함
		}
		refreshQueue();// 치킨 거리 기준으로 후보지 갱신
	}

	static void refreshQueue() {// 치킨 거리 기준으로 후보지 갱신
		candSize = 0;
		for (Iterator<Integer> iterator = BBQ.iterator(); iterator.hasNext();) {// 집 지을 최고의 위치를 넣기 위해 사용
			Integer pos = (Integer) iterator.next();// 이터레이터로 치킨집 위치 받아온다.
			boolean flag = true;// 후보지를 낼 수 없는 치킨집의 경우는 다른 치킨집에서 먼저 선점하거나 다른 치킨집 근처인 경우인데 이럴 경우 그 치킨집에서 검사하는 곳이랑
								// 이 치킨집이랑 겹치므로 제외하기 위해 사용
			if (!map.containsKey(pos - dist)) { // 왼쪽으로 치킨거리 만큼 떨어진 곳에 집을 지을 수 있는지
				candSize++;// 집 후보 크기 증가
				map.put(pos - dist, true);// 중복으로 체크 되는거 막기위해
				flag = false;// 후보지 찾을 수 있는 치킨집 임을 표시
			}
			if (!map.containsKey(pos + dist)) { // 오른쪽으로 치킨거리 만큼 떨어진 곳에 집을 지을 수 있는지
				candSize++;// 집 후보 크기 증가
				map.put(pos + dist, true);// 중복으로 체크 되는거 막기위해
				flag = false;// 후보지 찾을 수 있는 치킨집 임을 표시
			}
			if (flag)// 후보지를 낼 수 없는 치킨집의 경우는 다른 치킨집에서 먼저 선점하거나 다른 치킨집 근처인 경우인데 이럴 경우 그 치킨집에서 검사하는 곳이 이 치킨집이랑 겹치므로 제외하기 위해 사용
				iterator.remove();// 집 지을 후보 찾는 치킨 집에서 제외
		}
	}
}
