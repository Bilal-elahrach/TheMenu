#structure of this file (synthax basically)

#line 1: to make linked_list, you need test.c and linked_list_1.c
#line 2: INDENT + comment you'd normally run on terminal to create the executable file

linked_list: test.c linked_list_1.c
	gcc -o linked_list test.c linked_list_1.c

code1: code1.c
	gcc -o code1 code1.c