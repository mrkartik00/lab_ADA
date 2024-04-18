#include <iostream>
#include <vector>

using namespace std;

// Function to print subsets with the given sum using backtracking
void findSubsetsWithSum(const vector<int>& set, vector<int>& subset, int index, int currentSum, int targetSum) {
    // If the current sum equals the target sum, print the subset
    if (currentSum == targetSum) {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1) {
                cout << ",";
            }
        }
        cout << "],";
        return;
    }

    // Explore remaining elements
    for (int i = index; i < set.size(); ++i) {
        // Add the current element to the subset
        subset.push_back(set[i]);
        currentSum += set[i];

        // Recur with the updated subset and sum
        findSubsetsWithSum(set, subset, i + 1, currentSum, targetSum);

        // Backtrack: Remove the current element from the subset and update the sum
        subset.pop_back();
        currentSum -= set[i];
    }
}

// Function to find subsets with the given sum in the given set
void subsetSum(const vector<int>& set, int targetSum) {
    vector<int> subset;
    findSubsetsWithSum(set, subset, 0, 0, targetSum);
}

int main() {
    // Example 1
    vector<int> set1 = {1, 2, 1};
    int sum1 = 3;
    cout << "Input: set = {1, 2, 1}, sum = 3\nOutput: ";
    subsetSum(set1, sum1);
    cout << endl;

    // Example 2
    vector<int> set2 = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    cout << "Input: set = {3, 34, 4, 12, 5, 2}, sum = 30\nOutput: ";
    subsetSum(set2, sum2);
    cout << endl;

    return 0;
}
