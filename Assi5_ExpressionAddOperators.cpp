/*
Problem Title:
Expression Add Operators using Divide and Conquer

Problem Statement:
You are given a string num that contains only digits and an integer target.
Your task is to add binary operators '+', '-', or '*' between the digits in num without reordering them, so that the resulting mathematical expression evaluates to the target value.

Return all valid expressions (as strings) that evaluate to the target value.
You can return them in any order.

Constraints:
The input string num will contain only digits (0–9) and will not be empty.
Leading zeros are not allowed, except for the number zero itself (e.g., "05" is invalid).
The target value can be positive or negative.
Operators must be added between digits, and digits cannot be rearranged or removed.
All evaluated expressions must be valid and follow standard operator precedence (*) has higher precedence than (+) or( -).
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void helper(string num, int target, int pos, long currVal, long prevNum, string expr, vector<string>& result) {
    if (pos == num.size()) {
        if (currVal == target)
            result.push_back(expr);
        return;
    }

    for (int i = pos; i < num.size(); i++) {
        // Avoid numbers with leading zero
        if (i != pos && num[pos] == '0') break;

        string part = num.substr(pos, i - pos + 1);
        long val = stol(part);

        if (pos == 0) {
            helper(num, target, i + 1, val, val, part, result);
        } else {
            helper(num, target, i + 1, currVal + val, val, expr + "+" + part, result);
            helper(num, target, i + 1, currVal - val, -val, expr + "-" + part, result);
            helper(num, target, i + 1, currVal - prevNum + prevNum * val, prevNum * val, expr + "*" + part, result);
        }
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> result;
    helper(num, target, 0, 0, 0, "", result);
    return result;
}

int main() {
    string num = "123";
    int target = 6;
    vector<string> expressions = addOperators(num, target);

    for (string expr : expressions)
        cout << expr << endl;

    return 0;
}
/*
Input
num = "123"
target = 6

output
["1+2+3", "1*2*3"]

*/
