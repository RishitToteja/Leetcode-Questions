#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

class MedianFinder {
public:
    priority_queue <int> max;
    priority_queue <int, vector<int>, greater<int>> min;
    
    void addNum(double num) {
        if(max.size()==0 && min.size() == 0){ 
            max.push(num);
        }  //push is any of the heap  //max or min

        else{
            if(num < max.top())
                max.push(num);
            else 
                min.push(num);
        }
            //keeping in check that both heap are almost of same size
        if(int(max.size()-min.size() )> 1){
            int x=max.top();
            max.pop();
            min.push(x);
        }
        else if(int(min.size()-max.size()) > 1){
            int x=min.top();
            min.pop();
            max.push(x);
        }
    }
    
    double abs(double a){
        if(a < 0){
            return a*-1;
        }
        return a;
    }
    double findMedian(){


            int c=max.size()+min.size();  //count

            //checking size of list to find median
            if(c%2==0)
                return (double)(max.top() + min.top()) / 2;
            else
            {
                if(max.size()>min.size())
                    return max.top();
                else
                    return min.top();
            }
        

    }
};







/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */