class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>ans;
        
        for(int i=0;i<operations.size();i++){

            if(operations[i]=="C"){
                ans.pop();
            }
            else if(operations[i]=="D"){
                ans.push(2*ans.top());
            }
            else if(operations[i]=="+"){
              int f=ans.top();
              ans.pop();
              int s=ans.top();
              ans.push(f);
              ans.push(f+s);
            }
            else
            {
                ans.push(stoi(operations[i]));
            }
        }
        int sum=0;
       
        while(!ans.empty()){
          sum+=ans.top();
          
          ans.pop();
        }

        return sum;
        
    }
};