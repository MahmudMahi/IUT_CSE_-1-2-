#include<bits/stdc++.h>
using namespace std;
struct point{
	double x, y;
};
struct parallelogram{
	point A, B, D;
};
point addpoint(point p1, point p2);
point subPoint(point p1, point p2);
point fourthpoint(point p1, point p2, point p3);
double area(parallelogram p);
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	point p1, p2, p3;
	cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
	point unknown_point= fourthpoint(p1, p2, p3);
	parallelogram p;
	p.A=p1; p.B=p2; p.D=p3;
	double area_ans= area(p);
	cout<<unknown_point.x<<" "<<unknown_point.y<<" "<<area_ans<<endl;
	return 0;
}
point addpoint(point p1, point p2){
	point pSum;
	pSum.x= p1.x + p2.x;
	pSum.y= p1.y + p2.y;
	return pSum;
}
point subPoint(point p1, point p2){
	point pSub;
	pSub.x= p1.x-p2.x;
	pSub.y= p1.y- p2.y;
	return pSub;
}
point fourthpoint(point p1, point p2, point p3){
	point O, C;
	O= addpoint(p2, p3);
	O.x/=2; O.y/=2;
	C= addpoint(O, subPoint(O, p1));
	return C;
}
double crossProducts(point a, point b){
	double prod= abs((a.x)*(b.y)-(a.y)*(b.x));
	return prod;
}
double area(parallelogram p){
	double ans= crossProducts(subPoint(p.B, p.A), subPoint(p.D, p.A));
	return ans;
}
