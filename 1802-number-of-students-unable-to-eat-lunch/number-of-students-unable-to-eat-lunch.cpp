class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q(deque<int>(students.begin(), students.end()));
        int n=q.size();
        int i=0;
        int count=0;
        while(q.size()>0 && count!= q.size()){
            if(q.front()==sandwiches[i]){
                count=0;
                q.pop();
                i++;
            }
            else{
                count=count+1;
                int x=q.front();
                q.push(x);
                q.pop();
            }
        }
        return count;
    }
};