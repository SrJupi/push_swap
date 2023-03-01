# 42 Project - push_swap

## Subject
### Summary
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

### Introduction
The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.</br>
You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.</br>
Your goal? Write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

### Rules
You have 2 stacks named a and b.</br>
At the beginning:</br>
The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.</br>
The stack b is empty.</br>
The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:</br>
<li>sa (swap a): Swap the first 2 elements at the top of stack a.</br>
Do nothing if there is only one or no elements.</li>
<li>sb (swap b): Swap the first 2 elements at the top of stack b.</br>
Do nothing if there is only one or no elements.</li>
<li>ss : sa and sb at the same time.</li>
<li>pa (push a): Take the first element at the top of b and put it at the top of a.</br>
Do nothing if b is empty.</li>
<li>pb (push b): Take the first element at the top of a and put it at the top of b.</br>
Do nothing if a is empty.</li>
<li>ra (rotate a): Shift up all elements of stack a by 1.</br>
The first element becomes the last one.</li>
<li>rb (rotate b): Shift up all elements of stack b by 1.</br>
The first element becomes the last one.</li>
<li>rr : ra and rb at the same time.</li>
<li>rra (reverse rotate a): Shift down all elements of stack a by 1.</br>
The last element becomes the first one.</li>
<li>rrb (reverse rotate b): Shift down all elements of stack b by 1.</br>
The last element becomes the first one.</li>
<li>rrr : rra and rrb at the same time.</li>

## My approach
