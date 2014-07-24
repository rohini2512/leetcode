ass Solution {
public:
    int longestConsecutive(vector<int> &num) {
        
        int len ;
        int max_len = INT_MIN;
        
        if ( num.size() == 0 )
           return 0;
        
        map<int, int> numbers_present ;
        map<int, int> visited;
        
        for ( int i = 0 ; i < num.size() ; i++) {
            numbers_present[num[i]] = 1;
            
        }
    
        for ( int i = 0 ; i < num.size() ; i++) {
            
            if ( visited.find(num[i]) == visited.end()) {
            
                len = 1 ;
            
                int left_num = num[i]-1;
                int right_num = num[i]+1;
            
                visited[num[i]] = 1;
            
                while ( numbers_present.find(left_num) != numbers_present.end()) {
                    len++;
                    visited[left_num] = 1;
                    left_num--;
                }
                while( numbers_present.find(right_num) != numbers_present.end()) {
                    len++;
                    visited[right_num] = 1;
                    right_num++;
                }
            
                if ( len > max_len)
                    max_len = len;
            }   
        }
        
        return max_len;
        
    }
};
