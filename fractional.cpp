#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<double, int>>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;
    vector<pair<double, int>> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].first >= R[j].first) {
            arr[k] = L[i];
            k++; i++;
        } else {
            arr[k] = R[j];
            k++; j++;
        }
    }

    while (i < n1) {
        arr[k] = L[i];
        k++; i++;
    }

    while (j < n2) {
        arr[k] = R[j];
        k++; j++;
    }
}

void mergeSort(vector<pair<double, int>>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main(){
    int n;
    int maxCapacity;
    cout<<"Enter maximum capacity: ";
    cin>>maxCapacity;

    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> profits(n), weights(n);
    vector<pair<double, int>> ratios(n);
    vector<double> ans(n, 0);

    cout<<"Enter the weights of elements: ";
    for(int i = 0; i < n; i++){
        cin>>weights[i];
    }

    cout<<"Enter the profits: ";
    for(int i = 0; i < n; i++){
        cin>>profits[i];
    }

    cout<<"Weights of Items: ";
    for(int i = 0; i < n; i++){
        cout<<weights[i]<<" ";
    }
    cout<<endl;

    cout<<"Profits of items: ";
    for(int i = 0; i < n; i++){
        cout<<profits[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i < n; i++){
        ratios[i] = {(double)profits[i] / weights[i], i};
    }

    mergeSort(ratios, 0, n-1);

    cout<<"Ratios after sorting: ";
    for(int i = 0; i < n; i++){
        cout<<ratios[i].first<<" "<<ratios[i].second<<", ";
    }
    cout<<endl;

    double maxProfit = 0;
    int i = 0;
    while(maxCapacity && i < n){
        int idx = ratios[i].second;
        if(maxCapacity - weights[idx] >= 0){
            maxProfit += profits[idx];
            maxCapacity -= weights[idx];
            ans[idx] = 1;
        }
        else{
            double fraction = (double)maxCapacity / weights[idx];
            maxProfit += fraction * profits[idx];
            maxCapacity = 0;
            ans[idx] = fraction;
        }
        i++;
    }

    cout<<"Fraction Array: ";
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    cout<<"Maximum Profit: "<<maxProfit<<endl;

    return 0;
     
}