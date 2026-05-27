class Solution {
   public:
    bool isValid(string s) {
        stack<char> parentheses_stack;

        for (char character : s) {
            if (!parentheses_stack.empty() &&
                ((parentheses_stack.top() == '(' && character == ')') ||
                 (parentheses_stack.top() == '[' && character == ']') ||
                 (parentheses_stack.top() == '{' && character == '}'))) {
                parentheses_stack.pop();
            } else {
                parentheses_stack.push(character);
            }
        }

        return parentheses_stack.empty() ? true : false;
    }
};
