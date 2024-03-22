from ArrayStack import ArrayStack
import copy

input_str = input("-->")
start = True

while (input_str != "done()"):
    assign_expr = False
    input_lst = input_str.split()
    stack = ArrayStack()

    for token in input_lst:
        if (token in "+-*/"):
            arg2 = stack.pop()
            arg1 = stack.pop()

            if (arg2 == "0" and token == "/"):
                raise ZeroDivisionError

            res = eval(arg1 + token + arg2)
            stack.push(str(res))

        elif (token == "="):
            var = stack.pop()
            assign_expr = True

        else:
            stack.push(token)

    final = eval(stack.pop())

    if (assign_expr):
        if (start):
            dict_var = copy.copy(locals())
            start = False

        if (var in dict_var or var == "dict_var"):
            print("Please input another variable name.")

        else:
            locals()[var] = final
            print(var)

    else:
        print(final)

    input_str = input("-->")