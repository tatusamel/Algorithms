#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
#include <map>
using namespace std;




int greedy(vector<int>& startTimes, vector<int>& endTimes){
    
    int n = (int) startTimes.size();
    
    // first- > end , second - > start
    vector<pair<int,int>> tasks;
    for ( int i = 0 ; i < n ; i++){
        tasks.push_back({endTimes[i],startTimes[i]});
    }
    
    sort(tasks.begin(), tasks.end());
    
    int counter = 1;
    // baslangic ve bitis
    int bitis = tasks[0].first;
    
    for ( int i = 1; i < n ; i++){
        
        int st = tasks[i].second;
        int et = tasks[i].first;
        if ( st >= bitis ){
            counter++;
            bitis = et;
        }
    }
    
    return counter;
    
    
}



struct task{
    int st,et,prof;
    task() {}
    task(int st, int et, int prof) : st(st), et(et) , prof(prof) {}
};


vector<int> pArrayiniBul(vector<task>& tasks){
    int n = (int)tasks.size();
    
    vector<int> p(n);
    
    for ( int i = 0 ; i < n ;i++){
        
        int l = 0, r = n-1;
        while ( l <= r){
            int mid = (l+r)/2;
            
            if ( tasks[mid].et <= tasks[i].st ){
                l = mid+1;
                p[i] = l-1;
            }
            else {
                r = mid-1;
                p[i] = r;
            }
        }
    }
    return p;
}

bool compareByEndTime(task& t1, task& t2){
    return t1.et < t2.et;
}

int dp(vector<int>& startTimes, vector<int>& endTimes, vector<int>& profits){
    
    int n =(int) startTimes.size();
    vector<task> tasks(n);
    
    for ( int i = 0;  i < n ; i++){
        tasks[i] = task(startTimes[i],endTimes[i],profits[i]);
    }
    
    sort(tasks.begin(), tasks.end(), compareByEndTime);
    vector<int> p;
    int dp[n];
    
    dp[0] = tasks[0].prof;
    for ( int i = 1 ; i < n ; i++){
        if ( p[i] == -1 )   {
            dp[i] = max ( dp[i-1], tasks[i].prof);
        }else{
            dp[i] = max ( dp[i-1], tasks[i].prof + dp[p[i]]);
        }
        
    }
    return dp[n-1];
}



/*
 
 DP sample 1
 8
 0 1 3 3 4 5 6 8
 6 4 5 8 7 9 10 11
 50 20 35 40 75 10 30 55
 
 DP sample 2
 8
 6 15 7 11 1 3 16 2
 19 18 19 16 10 8 19 8
 2 9 1 19 5 7 3 19
 
 Greedy sample 1
 8
 0 1 3 3 4 5 6 8
 6 4 5 8 7 9 10 11
 
 */



