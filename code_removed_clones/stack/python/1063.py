#!/usr/bin/python
import sys

def push(stack_list, input): INDENT
    stack_list.append(input)

DEDENT def pop(stack_array): INDENT
    if len(stack_array) == 0: INDENT
        return 0
DEDENT     else: INDENT
        value = stack_array.pop()
        return value

DEDENT DEDENT def peep(stack_array): INDENT
    value = len(stack_array)
    if value == 0: INDENT
        return 0
DEDENT     else: INDENT
        return stack_array[value -1]

DEDENT DEDENT def is_empty(stack_array): INDENT
    if len(stack_array) == 0: INDENT
        return True
DEDENT     else: INDENT
        return False

DEDENT DEDENT def exit_code(): INDENT
    sys.exit()

DEDENT if __name__=="__main__": INDENT
    stack_list = []
    while True: INDENT
        value = 0
        print("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^")
        print ("Enter the operation to be performed on stack: ")
        print ("1. Print")
        print ("2. Push")
        print ("3. Pop")
        print ("4. Is Empty")
        print ("5. Peep")
        print ("0. Exit")
        try: INDENT
            value = int(raw_input("Enter the option: "))
DEDENT         except (TypeError, NameError, RuntimeError, ValueError): INDENT
            value = 6
DEDENT         print("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^")

        if value == 1: INDENT
            print stack_list
DEDENT         elif value == 2: INDENT
            input_value = input("Enter the value to be pushed: ")
            push(stack_list, input_value)
            print ("Now the stack looks like: ")
            print stack_list
            del input_value
DEDENT         elif value == 3: INDENT
            pop_value = pop(stack_list)
            print ("Poped value is : " +str(pop_value))
            print ("Now the stack looks like")
            print stack_list
DEDENT         elif value == 4: INDENT
            print "Stack is empty: " +str(is_empty(stack_list))
DEDENT         elif value == 5: INDENT
            print "Peep value for stack: " +str(peep(stack_list))
DEDENT         elif value == 0: INDENT
            print "Good Byee... :)"
            exit_code()
DEDENT         else: INDENT
            print "Please enter a valid input"

DEDENT         del value
DEDENT DEDENT 
