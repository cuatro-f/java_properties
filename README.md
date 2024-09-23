≡ Project - java properties 

# JAVA properties structure
## Project description
This project is my first laboratory work in C++. I wrote a program that takes a string in java properties format and fills the properties structure with data from it. The program can also generate a jave properties format string from an instance of the properties structure.  
To check the correctness of the entered java properties strings, I used regular expressions. The line must be in the format: {name="any non-empty string", group="format of NRNU MEPhI groups", grade=a number from 0 to 5 (type integer or double)}  
## Assembly Instructions
The cmake utility is used for assembly. In the project folder, create the build directory, then go to it and write "cmake ..", then the cmake utility will create a makefile. All we have to do is write "make" and the project will be built.  
**example**
[user@unix project]$ rm -rf build/  
[user@unix project]$ mkdir build/  
[user@unix project]]$ cd build/  
[user@unix build]$ cmake ..  
[user@unix build]$ make  
As a result, you will get the executable file main.
## Examples
**java properties string to structure**
0. Quit
1. String to properties
2. Properties to string
3. String to properties cstring
4. String to properties array
5. Properties to string cstring
6. Properties to string array
1  
Enter properties string:  
{name="Sasha", group="B23-505", grade=4.0}  
name=Sasha  
group=B23-505  
grade=4  
___
**structure to java properties string**
0. Quit
1. String to properties
2. Properties to string
3. String to properties cstring
4. String to properties array
5. Properties to string cstring
6. Properties to string array  
2  
Enter structure name:  
student  
student.name=Sasha  
student.group=B23-505  
student.grade=4.000000  
___
