ass Solution {
public:

/* Algorithm is as below :
 1. maintain and auxiliary array 't' of size of the string to be checked .
 2. each position in t tells whether there is a string in dictionary ending at 'i'.
 3. the matching of the substrings has to be consecutive. There should be no elements in between substrings 
    which do not form a word in the dictionary
 4. for each position i in the string iterate through all the words in the dictionary to check whether starting at
    that i if there is a matching word in the dictionary.
 */
    bool wordBreak(string s, unordered_set<string> &dict) {
        
        if ( s.empty())
           return false;
           
        if ( dict.size() == 0)
            return false;
        
         bool t[s.size()] ;
         
         for ( int i = 0 ; i < s.length(); i++)
             t[i] = 0;
         
         int end;
         
         for ( int i = 0 ; i < s.length() ;i++) {
             
             /*the matching of the substrings has to be consecutive. There should be no elements in between substrings 
    which do not form a word in the dictionary */
             if ( i > 0 && !t[i-1])
                continue;
             
             for ( unordered_set<string>::iterator itr = dict.begin() ; itr != dict.end() ; ++itr) {
                 
                 end = i + (*itr).length()-1;
                 
                 if ( end >= s.length())
                     continue;
                
                 if ( t[end]) 
                     continue;
                 
                 if ( s.substr(i, (*itr).length() )== *itr)
                     t[end] = true;
             }
         }
     
        return t[s.length()-1];
    }
};
