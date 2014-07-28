#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<map>
#include<iostream>

using namespace std;
bool isValidSudoku(vector<vector<char> > &board) {
        
	cout<<board.size()<<board[0].size();
        if ( board.size() < 9){
	   cout<<"board size row="<<board.size()<<endl;	
           return false;
	}
        
        if ( board[0].size() < 9){   
	   cout<<"board size col ="<<board[0].size()<<endl;	
           return false;
	}
           
        map<char, int> natural_num ;   
        /* verify each row*/
	 cout<<"verify row"<<endl;
        for ( int i = 0 ; i < 9 ; i++) {
            
            natural_num.clear();
            for (int j = 0 ; j < 9 ;j++) {
                
		cout<<"value of ij ="<<board[i][j]<<endl;    
                if ( board[i][j] != '.') {
                    if ( natural_num.find(board[i][j]) != natural_num.end()){
			cout<<"i="<<i<<"j="<<j<<"returning row"<<endl;    
                        return false;
		    }
                    else
                        natural_num[board[i][j]] = 1;
                }
                
            }
        }

	 cout<<"verify col"<<endl;
        
         /* verify each col*/
        for ( int i = 0 ; i < 9 ; i++) {
            
            natural_num.clear();
            for (int j = 0 ; j < 9 ;j++) {
                
		cout<<"value of ij ="<<board[j][i]<<endl;    
                if ( board[j][i] != '.') { 
                    if ( natural_num.find(board[j][i]) != natural_num.end()){
			cout<<"i="<<i<<"j="<<j<<"returning col"<<endl;    
                        return false;
		    }
                    else
                        natural_num[board[j][i]] = 1;
                }
                
            }
        }
        
        /*verify each square*/
	 cout<<"verify sq"<<endl;
      
        for ( int i = 0 ; i < 9 ; i = i + 3) {
            
            for ( int j = 0 ; j < 9 ; j = j + 3) {
                
                natural_num.clear();
                
                for ( int k = i ; k < i+3 ; k++ ) {
                    
                    for ( int l = j ; l < j+3; l++) {
                        
		        cout<<"value of kl ="<<board[k][l]<<endl;    
                        if (board[k][l] != '.' ) {
                            if ( natural_num.find(board[k][l]) != natural_num.end()){
			        cout<<"i="<<i<<"j="<<j<<"returning sq"<<endl;    
                                return false;
			    }
                            else
                                natural_num[board[k][l]] = 1;
                        }
                        
                    }
                }
            }
        }
        
	cout<<"returning atlast"<<endl;
        return true;
        
}

int  main() {

 vector<char> v ;

 vector<vector<char> > grid;

  v.push_back('.');
  v.push_back('8');
  v.push_back('7'); 
  v.push_back('6'); 
  v.push_back('5'); 
  v.push_back('4'); 
  v.push_back('3'); 
  v.push_back('2'); 
  v.push_back('1'); 

  grid.push_back(v);

  v.clear();
  v.push_back('2');
  v.push_back('.');
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 

  grid.push_back(v);

  v.clear();
  v.push_back('3');
  v.push_back('.');
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 

  grid.push_back(v);

  v.clear();
  v.push_back('4');
  v.push_back('.');
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 


  grid.push_back(v);

  v.clear();
  v.push_back('5');
  v.push_back('.');
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 

  grid.push_back(v);

  v.clear();
  v.push_back('6');
  v.push_back('.');
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 

  grid.push_back(v);

  v.clear();
  v.push_back('7');
  v.push_back('.');
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 


  grid.push_back(v);

  v.clear();
  v.push_back('8');
  v.push_back('.');
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 

  grid.push_back(v);

  v.clear();
  v.push_back('9');
  v.push_back('.');
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  v.push_back('.'); 
  grid.push_back(v);

 cout<<"result"<<isValidSudoku(grid);
}
