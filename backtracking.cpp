/* //leet 17
class Solution {
public:
    void solve(string map[],string out,vector<string>&ans,string digit,int i){
        // base case 
        if(i>=digit.length()){
            if(out.length()!=0){
                ans.push_back(out);
                
            }
            return ;
        }
        // now solve
        // map me se wo char nikalo jinpe kaam karna hai 
        string temp=map[digit[i]-'0'];
        for(auto ch:temp){
            // output ko update karo 
            out.push_back(ch);
            // rec
            solve(map,out,ans,digit,i+1);
            // back
            out.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) {
        string maping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string out="";
        vector<string>ans;
        int i=0;
        solve(maping,out,ans,digits,i);
        return ans;
    }
};
*/

/* leet 301

class Solution {
public:
    void solve(string& s, int index, int left, int right, int bal, string &output, unordered_set<string>& ans ) {
        //base case
        if(index >= s.length()) {
            //valid ans
            if(left ==0 && right ==0 && bal == 0 ) {
                ans.insert(output);
            } 
            return;
        }

        //main logic -> incl/excl
        if(s[index] !='(' && s[index] != ')') {
            //include
            output.push_back(s[index]);
            solve(s,index+1, left, right, bal, output, ans);
            output.pop_back();
        }
        else {
            //bracket wala case
            if(s[index] =='(') {
                //removal - include
                if(left > 0) {
                    solve(s, index + 1, left-1, right, bal, output, ans);
                }
                //removal - exclude
                output.push_back(s[index]);
                solve(s, index+1, left, right, bal+1,output, ans );
                output.pop_back();
            }
            else if(s[index] == ')') {
                //removal - include
                if(right > 0 ) {
                    solve(s, index+1, left, right-1, bal, output, ans);
                }
                //removal - exclude
                //removal nahi karna , sirf usi case jab corresponding opening bracket available hai 
                if(bal > 0 ) {
                    output.push_back(s[index]);
                    solve(s, index + 1, left, right, bal-1, output, ans);
                    output.pop_back();
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        int invalidLeft = 0;
        int invalidRight = 0;

        for(auto ch: s ){
            if(ch == '(') 
                invalidLeft++;
            if(ch == ')') {
                if(invalidLeft != 0) {
                    --invalidLeft;
                }
                else {
                    invalidRight++;
                }
            }
        }
        int index = 0;
        int balance = 0;
        string output = "";
        solve(s,index,invalidLeft,invalidRight,balance,output,ans);
        return vector<string>(ans.begin(), ans.end());
    }
};

*/

/* //leet 51 n-queens 

class Solution {
public:

    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> upperLeftDiagnolCheck;
    unordered_map<int,bool> bottomLeftDiagnolCheck;

    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string> > &ans) {
        vector<string> temp;
        for(int i=0; i<n; i++) {
            string output = "";
            for(int j=0; j<n ;j++) {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }


    bool isSafe(int row, int col, vector<vector<char>> &board, int n) {

        if(rowCheck[row] == true )
            return false;
            
        if(upperLeftDiagnolCheck[n-1+col-row] == true)
            return false;
            
        if(bottomLeftDiagnolCheck[row+col] == true)
            return false;

        return true;

 
    }


    void solve(vector<vector<char>> &board, int col, int n, vector<vector<string> > &ans  ) {
    //base case
    if(col >= n) {
        storeSolution(board, n, ans);
        return ;
    }

    //1 case solve karna h , baaki recursion sambhal lega

    for(int row = 0; row <n; row++) {
        if(isSafe(row, col, board, n)) {
        //rakh do
        board[row][col] = 'Q';
        rowCheck[row] = true;
        upperLeftDiagnolCheck[n-1+col-row] = true;
        bottomLeftDiagnolCheck[row+col] = true;
            
        //recursion solution laega
        solve(board, col+1, n, ans);
        //backtracking
        board[row][col] = '.';
        rowCheck[row] = false;
        upperLeftDiagnolCheck[n-1+col-row] = false;
        bottomLeftDiagnolCheck[row+col] = false;
        }

    }
}


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n,'.'));
        vector<vector<string> > ans;
        int col = 0;
        //0 -> empty cell
        //1 -> Queen at the cell
        solve(board, col, n, ans);
        return ans;
    }

};
*/


/* leet sudoko solver 37

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char value) {
        int n = board.size();

        for(int i=0; i<n; i++) {
            //row check
            if(board[row][i] == value)
                return false;
            
            //col check
            if(board[i][col] == value) 
                return false;

            //3*3 box check
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                //check for empty cell
                if(board[i][j] == '.') {
                    //try to fill with values ranging from 1 to 9
                    for(char val = '1'; val<='9'; val++) {
                        //check for safety
                        if(isSafe(i,j, board, val)) {
                            //insert
                            board[i][j] = val;
                            //recursion sambal lega
                            bool remainingBoardSolution = solve(board);
                            if(remainingBoardSolution == true) {
                                return true;
                            }
                            else {
                                //backtrack
                                board[i][j] = '.';
                            }
                        }
                    }
                    // agar koi nahi dul paya to return 
                return false;
                }
            }
        }
        //all cells filled 
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

*/