#include <bits/stdc++.h>
#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;
	
ll n, s, t;

ll simulateBaggageCarousel(int pos, map<ll,ll> knapsack) {
        ll cur_pos = pos;
	ll time = 0;
	while(!knapsack.empty()) {
		auto bag = knapsack.lower_bound(cur_pos);
		if(bag == knapsack.end()) {
			time += (s - cur_pos);
			cur_pos = 0;
			bag = knapsack.lower_bound(cur_pos);
		}
		knapsack[bag->first]--;
		time += (bag->first - cur_pos + t);
		cur_pos = (bag->first + t) % s;
		if(knapsack[bag->first] == 0)
			knapsack.erase(bag);
	}
	return time;

}

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd (b, a % b);
}

int main() {

	while(cin >> n >> s >> t) {
		map<ll,ll> knapsack;
		set<ll> start_pos;
		ll last_baggage = 0;
		for(int i = 0; i < n; i++) {
			ll l;
			cin >> l;
			knapsack[l]++;
			start_pos.insert(l);
			if(l > last_baggage)
				last_baggage = l;
		}

		ll min_time = LLONG_MAX, max_time = LLONG_MIN, average_time = 0;
		ll bagagge_count_between = (s - last_baggage);
		last_baggage = 0;
		for(ll pos : start_pos) {
			bagagge_count_between += (pos - last_baggage);
			ll time = simulateBaggageCarousel(pos,knapsack);
			if(min_time > time)
				min_time = time;
			if(max_time < time + (bagagge_count_between-1))
				max_time = time + (bagagge_count_between-1);
			average_time += bagagge_count_between*time + ((bagagge_count_between-1)*bagagge_count_between)/2;
			last_baggage = pos;
			bagagge_count_between = 0;
		}

		ll g = gcd(average_time,s);

		cout << min_time << endl;
		cout << max_time << endl;
		cout << (average_time/g) << "/" <<(s/g) <<endl;
		
		start_pos.clear();
		knapsack.clear();
	}
	
 
	return 0;
}
