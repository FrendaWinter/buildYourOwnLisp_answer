# Q-Expressions • Chapter 10

Online read link: https://buildyourownlisp.com/chapter10_q_expressions

### Question 1: What are the four typical steps for adding new language features?

As reminder, in the lecture. We have 4 steps to add new Rule to the language

| Step           | Description                                                               |
| :------------- | :------------------------------------------------------------------------ |
| Syntax         | Add new rule to the language grammar for this feature.                    |
| Representation | Add new data type variation to represent this feature.                    |
| Parsing        | Add new functions for reading this feature from the abstract syntax tree. |
| Semantics      | Add new functions for evaluating and manipulating this feature.           |

### Question 2: Create a Macro specifically for testing for the incorrect number of arguments.
### Question 3: Create a Macro specifically for testing for being called with the empty list.
### Question 4: Add a builtin function cons that takes a value and a Q-Expression and appends it to the front.
### Question 5: Add a builtin function len that returns the number of elements in a Q-Expression.
### Question 6: Add a builtin function init that returns all of a Q-Expression except the final element.