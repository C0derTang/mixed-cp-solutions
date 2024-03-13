#include <bits/stdc++.h>
using namespace std;

struct Event{
	int time;
	int id;
};

bool compareByTime(Event a, Event b) {
    return a.time < b.time;
}

int main() {
	int n;
	cin >> n;
	Event events[2*n];
	for (int i=0; i<2*n; i+=2){
		cin >> events[i].time;
		cin >> events[i+1].time;
		events[i].id = i/2;
		events[i+1].id = i/2;
	}
	sort(events, events+2*n, compareByTime);

	int alone[n] = {0};
	int last = 0;
	int total = 0;
	set<int> working;
	for (auto e : events) {
		if (working.size() == 1){
			alone[*working.begin()] += e.time - last;
		}
		if (!working.empty()){
			total += e.time - last;
		}
        if (working.find(e.id) == working.end()){
			working.insert(e.id);
		}else{
			working.erase(e.id);
		}
		last = e.time;
    }

	cout << total - *min_element(alone, alone+n);
}
