Question 2 Documentation

(a) DATA STRUCTURES
Stack Structure
• Uses an array items to store characters (maximum size 100)
• Uses a variable top to point to the last inserted element
• When the stack is empty, top = -1

(b) FUNCTIONS IMPLEMENTED
Basic Stack Functions
• initStack() – Initializes a new empty stack
• push() – Adds an element to the top of the stack
• pop() – Removes and returns the top element
• isEmpty() – Checks whether the stack is empty

Helper Functions

• isOpeningBracket() – Returns true if the character is '(', '[' or '{'
• isClosingBracket() – Returns true if the character is ')', ']' or '}'
• isMatchingPair() – Checks whether the opening and closing brackets form a correct pair

Main Logic Function
• isBalanced() – Checks whether the expression has balanced parentheses
• Scans each character of the expression
• Pushes opening brackets into the stack
• Pops and matches closing brackets
• If mismatch occurs → returns false
• If stack is empty at the end → returns true

(c) MAIN METHOD ORGANIZATION

Print program title

Define three test expressions:
• "a + (b - c) * (d"
• "m + [a - b * (c + d * {m)]"
• "a + (b - c)"

Check each expression using isBalanced() and print the result

End program

(d) SAMPLE OUTPUT

BALANCED PARENTHESES CHECKER

Expression: a + (b - c) * (d
Result: NOT BALANCED

Expression: m + [a - b * (c + d * {m)]
Result: NOT BALANCED

Expression: a + (b - c)
Result: BALANCED

Explanation
• First expression is not balanced because one '(' bracket is not closed
• Second expression is not balanced because '{' is incorrectly closed with ')'
• Third expression is balanced because all brackets are properly matched