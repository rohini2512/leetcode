class Solution {
public:

    void bfs(vector<vector<char>> &board, int row, int col, int r , int c, map<pair<int, int>, int> &visited) {
        
        queue<pair<int, int>> q;
        
        q.push(make_pair(r,c)) ;
        
        while ( !q.empty()) {
            
            pair<int, int> f = q.front();
            q.pop();
            if ( f.first+1 < row && board[f.first+1][f.second] == 'O' && 
                                    visited.find(make_pair(f.first+1,f.second)) == visited.end() )  {
                visited[make_pair(f.first+1, f.second)] = 1;
                q.push(make_pair(f.first+1, f.second));
            }
            
            if ( f.first-1 >= 0 && board[f.first-1][f.second] == 'O' && 
                                    visited.find(make_pair(f.first-1,f.second)) == visited.end() )  {
                visited[make_pair(f.first-1, f.second)] = 1;
                q.push(make_pair(f.first-1, f.second));
            }
            
             if ( f.second+1 < row && board[f.first][f.second+1] == 'O' && 
                                    visited.find(make_pair(f.first,f.second+1)) == visited.end() )  {
                visited[make_pair(f.first, f.second+1)] = 1;
                q.push(make_pair(f.first, f.second+1));
            }
            
            if ( f.second-1 >= 0 && board[f.first][f.second-1] == 'O' && 
                                    visited.find(make_pair(f.first,f.second-1)) == visited.end() )  {
                visited[make_pair(f.first, f.second-1)] = 1;
                q.push(make_pair(f.first, f.second-1)) ;
            }
            
        }
    }
    void solve(vector<vector<char>> &board) {
        
        if  ( board.size() == 0 )
            return ;
        
        if ( board[0].size() == 0)
            return;
            
        int row = board.size();
        int col = board[0].size();
        int c = 0 , r = 0 ;
        
        map<pair<int, int>, int> visited;
    
        while ( c < col ) { 
            if ( board[row-1][c] == 'O' && visited.find(make_pair(row-1,c)) == visited.end() ) {
                visited[make_pair(row-1,c)] = 1;
                bfs(board, row, col, row-1, c, visited);
            }
            c++;
        }
        
         c = 0 ;
         while ( c < col ) { 
            if ( board[0][c] == 'O' && visited.find(make_pair(0,c)) == visited.end() ) {
                visited[make_pair(0,c)] = 1;
                bfs(board, row, col, 0, c, visited);
            }
            c++;
        }
        
        while ( r < row ) { 
            if ( board[r][col-1] == 'O' && visited.find(make_pair(r,col-1)) == visited.end() ) {
                visited[make_pair(r,col-1)] = 1;
                bfs(board, row, col, r, col-1, visited);
            }
            r++;
            
        }
        
        r = 0 ;
        while ( r < row ) { 
            if ( board[r][0] == 'O' && visited.find(make_pair(r,0)) == visited.end() ) {
                visited[make_pair(r,0)] = 1;
                bfs(board, row, col, r, 0, visited);
            }
            r++;
        }
        
        for ( int i = 0 ; i < row; i++) {
            for ( int j = 0 ; j < col; j++) {
                
                if ( board[i][j] == 'O' && visited.find(make_pair(i,j)) == visited.end()) {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
