#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int start_time;
    int duration;
    int end_time;
    Workshop(int s, int d, int t) : start_time(s), duration(d), end_time(t) {}
};

struct Available_Workshops {
    int N;
    vector<Workshop> workshops;
};

Available_Workshops* initialize(int start_time[], int duration[], int N) {
    Available_Workshops* p = new Available_Workshops;
    p->N = N;
    for (int i = 0; i < N; i++) {
        p->workshops.emplace_back(start_time[i], duration[i], start_time[i] + duration[i]);
    }
    return p;
}

int CalculateMaxWorkshops(Available_Workshops *p) {
    sort(p->workshops.begin(), p->workshops.end(), [](const Workshop &l, const Workshop &r){
        return l.end_time < r.end_time;});
    int cur = -1;
    int count = 0;
    for (auto &w : p->workshops) {
        if (w.start_time >= cur) {
            count++;
            cur = w.end_time;
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int start_time[n],duration[n];
    for(int i=0;i<n;i++)
    {
        cin>>start_time[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>duration[i];
    }

    Available_Workshops * ptr;
    ptr=initialize(start_time,duration,n);
    cout<<CalculateMaxWorkshops(ptr)<<endl;
    return 0;
}
