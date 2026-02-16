#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        int lastGreaterValue = letters[0];
        int pointer = right - ((right - left) / 2);
        bool isFound = false;
        while (left <= right && !isFound) {
            pointer = left + ((right - left) / 2);
            if (letters[pointer] == target) {
                isFound = true;
            } else if (letters[pointer] < target) {
                left = pointer + 1;
            } else {
                lastGreaterValue = letters[pointer];
				right = pointer - 1;
        }
        }
        if (isFound) {
            pointer += 1;
        }
        return letters[pointer];
    }
};

int main() {
    vector<char> letters = {'a','b','c','f'};
    Solution s;
    char result = s.nextGreatestLetter(letters, 'd');
    printf("%c\n", result);
    return 0;
}
