class Solution {
public:
    struct Comp{
        bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2){
            return p1.first > p2.first; // min heap
        }  
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==0 || matrix[0].size()==0 || k>matrix.size()*matrix[0].size()){
            return INT_MIN;
        }
        
        // pair<value, pair<x-index, y-index>>
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Comp> min_heap; 
        // pair<x-index, y-index>
        set<pair<int, int>> st;
        
        int row = 0;
        int col = 0;
        min_heap.push(make_pair(matrix[row][col], make_pair(row, col)));
        st.insert(make_pair(row, col));
        
        int res = INT_MAX;
        
        for(int i=0; i<k; ++i){
            pair<int, pair<int, int>> cur = min_heap.top();
            min_heap.pop();
            
            res = cur.first;
            row = cur.second.first;
            col = cur.second.second;
            
            if(row+1<matrix.size() && st.find(make_pair(row+1, col))==st.end()){
                min_heap.push(make_pair(matrix[row+1][col], make_pair(row+1, col)));
                st.insert(make_pair(row+1, col));
            }
            
            if(col+1<matrix[0].size() && st.find(make_pair(row, col+1))==st.end()){
                min_heap.push(make_pair(matrix[row][col+1], make_pair(row, col+1)));
                st.insert(make_pair(row, col+1));
            }
        }
        
        return res;
    }
};