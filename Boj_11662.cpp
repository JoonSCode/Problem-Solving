//Main idea: 1.삼분탐색 2.소수의 범위
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;

void input() {
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
}

double dist(pair<double,double> a, pair<double, double> b) {//점 a와 점 b의 거리를 출력 
    double ans = sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
    if (ans < 1e-6)
        ans = 0;
    return ans;
}

pair<double,double> mino(double p) {//벡터 매개변수처럼 표기
    p /= 100;
    return { Ax + (Bx - Ax) * p ,Ay + (By - Ay) * p };
}

pair<double, double> kangho(double p) {
    p /= 100;
    return { Cx + (Dx - Cx) * p , Cy + (Dy - Cy) * p };
}

double ts(double start, double end) {//삼분탐색
    double ans = 200000;
    while (end - start > 1e-6) {
        double p1 = (end + 2 * start) / 3;
        double p2 = (end * 2 + start) / 3;
        
        double d1 = dist(mino(p1), kangho(p1));
        double d2 = dist(mino(p2), kangho(p2));
        ans = min(ans,min(d1, d2));
        if (ans == 0)
            break;
        if (d1 < d2)    end = p2;
        else start = p1;
    }
    return ans;
}

void Mino() {
    input();
    cout.precision(11);
    cout<<ts(0,100);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Mino();
}
