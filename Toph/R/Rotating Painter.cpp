// https://toph.co/arena?practice=67beea7dbd06f0757a979cf7#!/p/67b8c242a1421e6d6b46d16a

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
#define endl '\n'
typedef long double ld;


const ld pi = 2 * acos(0.0);

ld rad(ld theta){
	theta *= pi;
	theta /= 180.0;
	return theta;

}

ld radius(ld side, ld len){
	ld theta = (ld) (360.0 / (2.0*side));
	theta = rad(theta);
	ld ret=(len/2)/tan(theta);
	return ret;
}

ld cor(ld side, ld len){
	ld theta = (ld) (360.0 / (2.0*side));
	theta = rad(theta);
	ld ret = (len / 2.0) / (cos(theta));
	return ret;
}



ld xxx(ld br, ld bl){
	bl=bl/2.0;
	return sqrtl((br*br)+(bl*bl));
}

void solve(int test) {
	ld ts, tl, bs, bl;
	cin >> ts >> tl >> bs >> bl;
	cout << fixed << setprecision(10);

	ld topr = radius(ts, tl);
	ld bottomr = radius(bs, bl);

	ld corner=xxx(bottomr, bl);
	
	if(topr >= corner) cout << "0.0" << endl;
	else if( topr <= bottomr){
		// diff of their areas
		ld triarea = bs * bl * bottomr * 0.5;
		ld cir = (pi * topr * topr);
		ld ans = triarea - cir;
		cout << ans << endl;
	}
	else{
		ld base = sqrtl((topr * topr) - (bottomr * bottomr));
		ld areaTri = base * bottomr;


		ld theta=acos(bottomr/topr);
		theta*=(180.0/pi);
		theta*=2.0;

		ld circle_area= ((pi*topr * topr)*theta)/360.0;

		ld dif= circle_area- areaTri;
		dif*=bs;

		ld extra=(pi*topr * topr)-dif;

		ld poly_area=bl*bottomr*bs* 0.5;

		ld ans= poly_area - extra;
		cout<<ans<<endl;

	}
}




int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	int t = 1;
	cin >> t;

	for (int T = 1; T <= t; T++) {
		solve(T);
	}


	return 0;
}