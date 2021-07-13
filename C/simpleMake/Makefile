
# Running make without argument starts the target "all" in the makefile. 
# A makefile consists of a set of rules. 
# A rule consists of 3 parts: 
# 	a target, 
# 	a list of pre-requisites 
# 	a command
#
# As follows:
#
# target: pre-req-1 pre-req-2 ...
# 	command
#
# source: https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html#zz-1.4

all: hello
	
hello: hello.o
	gcc -o hello hello.o

hello.o: hello.c
	gcc -c hello.c

clean: 
	rm hello hello.o
