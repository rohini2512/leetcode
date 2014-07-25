#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stack>

using namespace std;

bool isValid(string s) {
        
        if ( s.empty() || s.size() == 0)
           return false;
           
        map<char, char> paren ;
        
        paren[')'] = '(';
        paren['}'] = '{';
        paren[']'] = '[';
        
        stack<char> st;
        st.push(s[0]);
        
        int i = 1;
        
        while (!st.empty() || i < s.size()) {
            
            /* find if the next character is a closing brace
             *. If it is closing then check if top is the opening corresponding to it
             */
             
             if ( paren.find(s[i]) != paren.end()) {
                 
		 cout<<"i = "<<i<<"s [i] ="<<s[i]<<endl;    
                 /* if it matches the top then pop stack else return false*/
                 if ( !st.empty() && st.top() == paren[s[i]] )
                     st.pop();
                  else
                      return false;
             }
             else {
                 st.push(s[i]);
             }
             
             i++;
            
        }
        
        if ( st.empty())
            return true;
        else
            return false;
        
}


int main() {

    string s = "[])";
    bool valid =  isValid(s);

    cout<<"is string valid"<<valid;

}
