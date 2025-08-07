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
