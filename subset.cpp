#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;
vector<int> result;

void solve(vector<int> &nums, int idx, int sum, int key){
    if(sum == key){
        ans.push_back(result);
        return;
    }

    if(sum > key || idx >= nums.size()) return;

    result.push_back(nums[idx]);

    solve(nums, idx+1, sum + nums[idx], key);
    result.pop_back();
    solve(nums, idx+1, sum, key);
}

int main(){

    int n, key;
    cout<<"Enter Number of elements :";
    cin>>n;

    cout<<"Enter the key :";
    cin>>key;

    cout<<"Enter the elements :";
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin>>nums[i];

    solve(nums, 0, 0, key);
    
    int N = ans.size();

    cout<<"Total Solutions : "<<N<<endl;
    cout<<"Solutions are:"<<endl;

    if(N > 0){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < ans[i].size(); j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}