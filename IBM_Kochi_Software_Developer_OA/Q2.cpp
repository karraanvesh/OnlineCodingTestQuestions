/*
Q : Given an array of n positive intergers nums , yout task is to find the count of 
    numbers for every nums[i] which satisfy the below condition .
    
        * gcd(nums[i] , num) = 1 , where num >= 1 and num <= nums[i]

    Find the count of numbers fro every nums[i] and return the resultant vector . 

    Example Input  1 : n = 4 , nums = [1 , 2 , 6 , 10]

    Example Output 1 : [1 , 1 , 2 , 4]

    Explanation : 
    1  -> 1
    2  -> 1
    6  -> 1 , 5
    10 -> 1 , 3 , 7 , 9

    Example Input  2 : n = 3 , nums = [1 , 4 , 5]

    Example Output 2 : [1 , 2 , 4]

    Explanation : 
    1 -> 1
    4 -> 2
    5 -> 1 , 2 , 3 , 4

*/

// Time  Complexity : O(n * sqrt(n)) + O(numbers)
// Space Complexity : O(n)
// where numbers = summation of every sieve of num[i] i.e., num[i] * log(log * nums[i])

#include<bits/stdc++.h>
using namespace std;

void primeFactorization(int num , vector<vector<int>> &factorsList , int ind) {

    for(int i = 2 ; i <= sqrt(num) ; i++) {

        if(num%i == 0) {
            factorsList[ind].push_back(i);

            while(num%i == 0) {
                num /= i;
            }
        }
    }

    if(num >= 2) {
        factorsList[ind].push_back(num);
    }

    return ;
}

void sieveHelper(int n , int factor , vector<bool> &arr , int &ans) {

    for(int i = factor ; i <= n ; i += factor) {

        if(arr[i]) {
            arr[i] = false;
            ans--;
        }
    }

    return ;
}

vector<int> GCDCount(vector<int> &nums , int n) {
    vector<vector<int>> factorsList(n);

    for(int i = 0 ; i < n ; i++) {
        int num = nums[i];

        primeFactorization(num , factorsList , i);
    }

    vector<int> result;

    for(int i = 0 ; i < n ; i++) {
        int num = nums[i];

        vector<int> factors = factorsList[i];
        int noOfFactors = factors.size();
        vector<bool> arr(num+1 , true);
        int ans = num;

        for(int j = 0 ; j < noOfFactors ; j++) {
            sieveHelper(num , factors[j] , arr , ans);
        }

        result.push_back(ans);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n , 0);

    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i];
    }

    vector<int> ans = GCDCount(nums , n);

    for(int i = 0 ; i < ans.size() ; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

