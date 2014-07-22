#include<stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<map>

using namespace std;
/**
 * Definition for a point.
 */
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };
int maxPoints(vector<Point> &points) {
        
        if ( points.size() == 0 )
            return 0;
            
        double slop ;    
        int max_points ;
        int max_freq = 0 ;
        
        for ( int i = 0 ; i < points.size() ; i++) {
            
            int dup = 0 ;
            map<double,int> slope ;
            max_points = 1;
            
            for ( int j = 0 ; j < points.size(); j++) {
                
                if ( i != j) {
                    
                    if ( points[j].x == points[i].x && points[j].y == points[i].y)
                         dup++ ;
                    else if ( points[j].x == points[i].x) {
                        
                         if ( slope.find(INT_MAX) == slope.end())
                            slope[INT_MAX] = 2;
                        else    
                            slope[INT_MAX]++;
                            
                         if ( slope[INT_MAX] >= max_points)
                             max_points =  slope[INT_MAX];
                    }     
                    else {
                        slop = 1.00 * (points[i].y - points[j].y)/( points[i].x - points[j].x);
                        
                        if ( slope.find(slop) == slope.end())
                            slope[slop] = 2;
                        else    
                            slope[slop]++;
                        if ( slope[slop] >= max_points)
                            max_points = slope[slop];
                    }
                }
                
            }
            
            if ( max_points +dup > max_freq)
                max_freq = max_points + dup;
        }
        
        return max_freq;
        
    }
int main() {

    vector<Point> v;
    Point m1  ;
    m1.x = 84;
    m1.y = 250;

    v.push_back(m1);

    m1.x = 0 ;
    m1.y = 0;
    v.push_back(m1);

    m1.x = 1;
    m1.y  = 0;
    v.push_back(m1);

    m1.x = 0;
    m1.y = -70;
    v.push_back(m1);

    m1.x = 0;
    m1.y  = -70;
    v.push_back(m1);

    m1.x = 1;
    m1.y = -1;
    v.push_back(m1);

    m1.x = 21;
    m1.y = 0;
    v.push_back(m1);

    m1.x = 42;
    m1.y = 90;
    v.push_back(m1);

    m1.x = -42;
    m1.y = -230;
    v.push_back(m1);

 int maxp =     maxPoints(v);

 cout<<"map = "<<maxp;

}


