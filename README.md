Jacob (JT) Fox
03/12/2024

GitHub Repo: https://github.com/jtfox142/compilers-1

I chose to implement option 1 for this project. It is a simple string parser that can read tokens delimited by whitespace. It is able to count line number and character number for each token.

It can be compiled using the included makefile. Simply type "make" into the terminal.

After compilation, this program can be run in three different ways: The first way is to type "./p1" with no arguments, then type out your desired input. The second way is to supply a text file as an argument. Example: "./p1 test.txt". The third way is to redirect a file into the program, in which case its contents are treated as keyboard input. Example: "./p1 < test.txt".

It does not handle multiline redirected input very well. If you attempt to run it using redirected input, it will only read what is on the first line. 

I do not currently know of any other errors.