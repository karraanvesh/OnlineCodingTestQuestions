/*
Q : Given an array of n positive intergers and we have two players namely player1 and player2
    where score1 and score2 are their corresponding scores . Two players takes alternative 
    turns starting the game with player1 , In each turn the player picks the first element 
    in the array and add that element to their corresponding score and deletes it from the 
    array if current element picked by the player is even then after deleting the current 
    element the array has to be reversed . This game continues until the  array 
    is non empty , your task is to return the difference of score1 and score2 after the 
    game is done  . 

    Example Input : n = 5 , nums = [1 , 2 , 3 , 4 , 5]

    Output : 3

    Explanation : 

    1. score1 = 0 , score2 = 0 .

    [1 , 2 , 3 , 4 , 5]

    player1 picks 1 and adds to his score and deletes it from nums

    2. score1 = 1 , score2 = 0  . 

    [2 , 3 , 4 , 5]

    player2 picks 2 and adds to his score and delete it from nums , Since 
    the current element i.e., 2 is even after deleting 2 the array will be 
    reversed .

    3. score1 = 1 , score2 = 2

    [5 , 4 , 3]

    player1 picks 5 and adds to his score and deletes it from nums.

    4. score1 = 6 , score2 = 2 

    [4 , 3] 

    player2 picks 4 and adds to his score and deletes it from nums , since 
    4 is even after deleting 4 from nums we wil reverse the array .

    5. score1 = 6 , score2 = 6 

    [3]

    player1 picks 3 and adds to his score and deletes it from nums . 

    score1 = 9 , score2 = 6.

    score1 - score2 = 9 - 6 = 3

*/

// Time  Complexity : O(n)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

int findDifference(vector<int> &nums , int n) {
    int score1 , score2 , left , right;
    score1 = score2 = left = 0;
    right = n - 1;

    bool flag = true;
    int ct = 0;

    while(left <= right) {
        int currEle;
        ct++;

        if(flag) {
            currEle = nums[left];
            left++;
        }

        else {
            currEle = nums[right];
            right--;
        }

        ct = ct;

        if(ct%2 == 1) {
            score1 += currEle;

            if(currEle%2 == 0) {
                flag = !flag;
            }
        }

        else {
            score2 += currEle;

            if(currEle%2 == 0) {
                flag = !flag;
            }
        }   
    }

    int result = score1 - score2;

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n , 0);

    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i];
    }

    cout << findDifference(nums , n) << endl;
    return 0;
}