# Homework - C Practice Report

Completely answer the report questions below. Make sure to double check the final version to make sure it is easily readable on your github repository. 

Name: Aliya Salmanova
Semester: Fall 2025


1. What is the difference between a standard numeric type (int, float, double) and a pointer?
A pointer refers to an address in memory in which a value is stored. Whereas a standard numeric type is a value. 
If you pass in a numeric type into a function, the parameter is a copy of the value. 
   
2. In your test file, we had the following code:
    
    ```c
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    ```
    Later in the code we only `free(arr)` but not expected. Why is this? What is the difference in where they are stored in memory?
arr is stored in the heap as we created it using malloc in the create_array_of_ints_fib function. This was necessary 
because otherwise when the array would get returned, the values in the array would get pulled off the stack, and we would 
no longer have access to them. expected is stored in the stack, so it is in local memory. 

3. What is the difference between the heap and stack when related to memory allocation and management?
When memory is allocated on the stack, it automatically gets pulled off the stack as soon as the function finishes running.
In the heap, the memory stays allocated after the function ends. If you need it free, you have to manually free the space in C. 

4. Take the following code:
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct {
     int x, y;
   } Point;

   Point * new_point(int x, int y) {
     Point pt = {x, y};
     return &pt;
   }

   int main() {
      Point* point = new_point(10, 10);
      printf("x: %d, y: %d", point->x, point->y);
      return 0;
   }
   ```
   Would the code run correctly? Even if it does compile, what would be some potential runtime issues? After answering your thoughts, put the output of a run below (you may need to run it a few times).
   pt is declared as a Point, but it is assigned an array. Also, since pt is meant to be a struct, it would have to say *pt as a struct
   is referred to with a pointer. The x and y would be accessed like pt->x and pt-> y. Furthermore, you wouldn't have to indicate & before pt
   as a struct is already referred to with a pointer. I think there would be a type error in line 38, (Point pt = {x, y};),
   and there could be further syntax issues because of that error. 

      ```text
   reportQuestion4.c:10:13: warning: address of stack memory associated with local variable 'pt' returned [-Wreturn-stack-address]
   10 |     return &pt;
      |             ^~
   1 warning generated.

      output here
      ```

      Fix the code in the following block:
      ```c
      #include <stdio.h>
      #include <stdlib.h>

      typedef struct {
        int x, y;
      } Point;

      Point * new_point(int x, int y) {
        Point* pt = (Point*)malloc(sizeof(Point));
        pt->x = x;
        pt->y = y;
   
        return pt;
      }

      int main() {
         Point* point = new_point(10, 10);
         printf("x: %d, y: %d", point->x, point->y);
         return 0;
      }
      ```

5. When you use `malloc`, where are you storing the information?
In the heap. 

6. Speaking about `malloc` and `calloc`, what is the difference between the two (you may need to research it!)?
calloc makes sure that the unassigned values are set to 0. It is slower than malloc. 
Usually we use malloc unless we need to make sure that the values are initially set to 0. 

7. What are some common built in libraries used for C, list at least 3 and explain each one in your own words. Name a few (at least 3) functions in those libraries (hint: we used two of the most common ones in this assignment. There are many resources online that tell you functions in each library - you need to include at least 1 reference, but ideally for every library, you should have a reference to it)?
   - Example: stdlib.h - provides functions for general-purpose operations including
              memory management and random numbers [1].
     - void * malloc(size_t) - allocates memory specified in size on the heap and returns a pointer to that location
     - void * calloc(size_t num_elements, size_t element_size) - contiguous allocation for allocating arrays with the default value of 0. Slower than malloc. 
     - int rand(void) - returns a random integer between 0 and RAND_MAX. Seed should be set before hand. 
   1.  math.h - gives you access to functions that perform mathematics on numbers 
      *  pow(x, y) - calculates and return x to the power of y
      *  round(x) - rounds x to the nearest integer and returns that
      *  sqrt(x) - calculates the square root of x and return that
   
   2. time.h - provides functions to work with time, dates, and durations
      * time(NULL) or time(addressOfVariable) - returns the amount of seconds passed since Jan 1, 1970 (Unix timestamp).  
        You can pass in NULL and it will return the amount of seconds, or you pass in the address of the variable that you want the value to be returned into.
        Returns a time_t value, which is a long integer. 
      * ctime(&address) - takes in the address of a time_t value, and returns the time as a string (weekday, month, day of month, time, year, ex: Thu Jun 26 10:30:00 2025 )
      * localtime(&address) - similar to ctime, but returns a struct, so you can access the month, day, hour, etc, separately.
      Also takes in the address of a time_t variable. Has members such as tm_hour, tm_mday, etc. 
 
   3. stdio.h - provides functions for file handling, input, and output
      * fopens(filePath, mode) - a function that opens a file and returns a pointer to the file.
        Takes in a string for the filepath, and mode. Modes include "r" for reading, "w" for writing which clears existing content of the file,
        "a" for writing to the end of the file, and more.
      * fprintf(filePointer, formatted string, additional) - writes formatted string into file. 
        The string can have format specifiers indicate in the additional arguments. 
      * putchar(character) - writes a single character to the console. 

https://www.w3schools.com/c/c_ref_math.php

https://www.w3schools.com/c/c_ref_time.php
https://www.geeksforgeeks.org/c/time-function-in-c/
https://www.w3schools.com/cpp/ref_ctime_localtime.asp

https://www.w3schools.com/c/c_ref_stdio.php
https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm


8. Looking at the struct Point and Polygon, we have a mix of values on the heap, and we make ample use of pointers. Take a moment to draw out how you think that looks after `create_triangle(2,3)` is called (see an example below). The important part of the drawing it to see that not everything is stored together in memory, but in different locations! Store the image file in your github repo and link it here. You can use any program to draw it such as [drawIO](https://app.diagrams.net/), or even draw it by hand and take a picture of it. 
```markdown
![create_triangle(2,3)](stackHeap.png)
```

## Technical Interview Practice Questions
For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.
   https://www.freecodecamp.org/news/compiled-versus-interpreted-languages/

    What is the difference between a compiled and an interpreted language? Which one is better? Give an example of each.
    A compiled language is turned into machine code before running. You need to manually compiled it and when you make a change you need to re-compile it.
    They are faster usually than interpreted languages, but one con is that it takes longer to compile,
    and you have to compile again after making a change. An example is c. 
    An interpreted language is run line by line. They are typically slower than compiled languages but it's getting faster.
    An example is Python. Often interpreted languages offer dynamic typing. 
   
   
2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 


## Deeper Thinking
In Java and Python, do you think new objects are stored on the stack or the heap? Feel free to work through your thoughts as to why it would be better to store them on the stack or heap. You should consider pass by reference, and how that is similar to pointer in your answer. Feel free to use resources, but make sure to cite them, and include the citation below using ACM format. You will note LLMs are not valid references, but they can give you directions to valid references. Make sure to use your own words. 

Answer here using a paragraph (not just bullet points). 
I think objects in Java and Python would be stored in the heap because the stack can overflow, 
and objects can be large as they can have both attributes and methods. Also, you might lose the values of the fields
if you create the objects in a function and then return
https://www.geeksforgeeks.org/java/how-are-java-objects-stored-in-memory/
According to my references, in Java, objects are stored in the heap while references to the objects are stored in the stack.
https://www.geeksforgeeks.org/python/memory-management-in-python/
Same thing with Python. Also, I think it's important to note that eveything is an object in these languages.


## References
Add any references you use here. Use ACM style formatting, adding to the numbers as you add the reference. 

1. cppreference.com Contributors. 2025. Standard library header <stdlib.h>. cppreference.com. Retrieved May 1, 2025 from https://en.cppreference.com/w/c/header/stdlib

2. ... https://www.geeksforgeeks.org/dsa/stack-vs-heap-memory-allocation/
   https://www.geeksforgeeks.org/c/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

## Resource/Help: Linking to images?
To link an image, you use the following code


for example
```markdown
![my memory drawing](instructions/rectangle_points.png)
```


Here is a sample using: 
```c
void my_func() {
    Polygon* r = create_rectangle(5,5);
    printf("The area of the rectangle is %d\n", area(r));
}
```

![my memory drawing](instructions/rectangle_points.png)

Note: This is a simplified version. However, it helps illustrate why we need to use `free` on the pointers in the struct. If we do not, we will have memory leaks! (memory that is allocated, but not freed, and thus cannot be used by other programs). In the above example code, `r` is created, and then the variable is destroyed when the function ends. However, the memory allocated for the struct is not freed, and thus we have a memory leak.

When you work on your version for `create_triangle(2, 3)`, you do not have to be exact on the memory structure (the locations on the heap were randomly chosen). The idea is more to show how the memory is stored, and the pointers to different memory addresses. 

