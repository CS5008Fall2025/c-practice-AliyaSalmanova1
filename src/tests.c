/**
 * Student Name: Aliya Salmanova
 * Semester: Fall 2025
 * 
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library
#include <time.h>
#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

/**
 * Tests a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

/**
 * Tests the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib() {
    printf("2. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); // note expected does not need freed.. why is that?
    // everything matched
    return 1;
}

int test_reverse_array() {
    printf("3. test_reverse_array()\n");

    int arr[5] = {1, 2, 3, 4, 5};
	reverse_array(arr, 5);
    int expected[] = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        } 
    }
	
    free(arr); 
    // everything matched
    return 1;
}

int test_double_array_size() {
    printf("4. test_double_array_size()\n");

    int arr[5] = {1, 2, 3, 4, 5};
	int *doubledArray = double_array_size(arr, 5);
    int expected[] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};
    for (int i = 0; i < 10; i++) {
        if (doubledArray[i] != expected[i]) {
            free(doubledArray);
            return 0;
        } 
    }
	
    free(doubledArray); 
    // everything matched
    return 1;
}

int test_copy_array_start_end_loop() {
    printf("5. test_copy_array_start_end_loop()\n");

	int newSize1 = 0;
	int newSize2 = 0;
    int arr[5] = {1, 2, 3, 4, 5};

	int *newArr1 = copy_array_start_end_loop(arr, 5, 1, 3, &newSize1);
	int *newArr2 = copy_array_start_end_loop(arr, 5, 3, 1, &newSize2);
    int expected1[] = {2, 3, 4};
	int expected2[] = {4, 5, 1, 2};
    for (int i = 0; i < newSize1; i++) {
		//printf("arr 1 %d, %d\n", newArr1[i],  expected1[i]);
        if (newArr1[i] != expected1[i]) {
            free(newArr1);
            return 0;
        } 
    }
	for (int i = 0; i < newSize2; i++) {
		//printf("arr 2 %d, %d\n", newArr2[i],  expected2[i]);
        if (newArr2[i] != expected2[i]) {
            free(newArr2);
            return 0;
        } 
    }
	
    free(newArr1); 
	free(newArr2); 
    // everything matched
    return 1;
}

int test_create_point(){
 	printf("6. test_create_point()\n");
	Point *myStruct = create_point(4, 5);
	if ((myStruct->x != 4) || (myStruct->y != 5)){
		return 0;
	}
	return 1;
}

int test_create_polygon(){
 	printf("7. test_create_polygon()\n");
 	int size = 5;
	Polygon *polygon = create_polygon(size);

	if (polygon->size != size){
		return 0;
	}
	for (int i = 0; i < size; i++) {
        if ((polygon->points[i]->x != 0) || (polygon->points[i]->y != 0)){
			return 0;
		}
    }

	return 1;
}



int test_create_rectangle(){
	printf("8. test_create_rectangle()\n");
	Polygon *rectangle = create_rectangle(4,5);
	if (rectangle->size != 4){
		return 0;
	} 
	if ((rectangle->points[0]->x != 0) || (rectangle->points[0]->y != 0)){
		return 0;
	}
	if ((rectangle->points[1]->x != 4) || (rectangle->points[1]->y != 0)){
		return 0;
	}
	if ((rectangle->points[2]->x != 4) || (rectangle->points[2]->y != 5)){
		return 0;
	}
	if ((rectangle->points[3]->x != 0) || (rectangle->points[3]->y != 5)){
		return 0;
	}
	return 1;
}

int test_create_triangle(){
	printf("9. test_create_triangle()\n");
	Polygon *triangle = create_triangle(4,5);
	if (triangle->size != 3){
		return 0;
	} 
	if ((triangle->points[0]->x != 0) || (triangle->points[0]->y != 0)){
		return 0;
	}
	if ((triangle->points[1]->x != 4) || (triangle->points[1]->y != 0)){
		return 0;
	}
	if ((triangle->points[2]->x != 4) || (triangle->points[2]->y != 5)){
		return 0;
	}
	return 1;
}

int test_calculate_polygon_area(){
	printf("10. test_calculate_polygon_area()\n");
	Polygon *rectangle = create_rectangle(4,5);
	// 0, 0 // 0 - 0 = 0
	// 4, 0 // 20 - 0 = 20
	// 4, 5 // 20 - 0 = 20
	// 0, 5 // 0 - 0 = 0

 //* 0, 0
 //* width, 0
 //* width, height
 //* 0, height
	time_t currTime;
	time(&currTime);
	char* timeString = ctime(&currTime);

	printf("%s\n", timeString);

	double expected = 40.0;
    double area = calculate_polygon_area(rectangle);
	if (area == expected) {
		return 0;
	}
	return 1;
}


// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_create_array_of_ints_fib,
        // add more test function names here
		test_reverse_array,
		test_double_array_size,
		test_copy_array_start_end_loop,
		test_create_point,
		test_create_polygon,
		test_create_rectangle,
		test_create_triangle,
		test_calculate_polygon_area
};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i + 1);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
