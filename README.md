# my_scanf
Custom function which aims to reproduce scanf's behaviour. Personal project to enhance what was learned with ft_printf 42 project.

# What is the scanf function?
The scanf function is declared in the stdio.h C library and is to be mutually complementary with printf. It reads user input from the standard input and stores it in a desired variable.

## How does it work?
The scanf function reads input from the stdin into a buffer;
The function then itterates through its parameters (format specifiers and addresses) until a format specifier is found;
When a format specifier is found, it itterates through the buffer and copies its data to the associated variable's memory address;
