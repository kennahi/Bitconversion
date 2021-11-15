# Bitconversion
A variant of minitalk that takes a string and displays each character as a byte.

2 programs that act as client and server, sender and receiver. (check my minitalk project for more info)

How to use:
----------------------
make

./server (you will receive the server's PID, do not close the program)

./client [PID] [any_string]

now the server should display each character of the string and their binary version.

How does it work?
----------------------
I used the signals SIGUSR1 and SIGUSR2 to send and receive bits. each 8 bits is one character. once 8 bits signals are sent, the program displays it.
