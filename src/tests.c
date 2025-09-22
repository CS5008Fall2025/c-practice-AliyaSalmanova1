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
 * Swap test 1
 */
int test_swap1() {
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
 * Swapping negative values
 */
int test_swap2() {
	printf("1b. test_swap2e()\n");
	int a = -3, b = 4;
	swap(&a, &b);
	return (a == 4 && b == -3);
}

/**
 * Swapping same value
 */
int test_swap3() {
	printf("1c. test_swap3()\n");
	int a = 7, b = 7;
	swap(&a, &b);
	return (a == 7 && b == 7);
}



/**
 * Tests the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib1() {
    printf("2a. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
		//compare each element to expected element
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); // note expected does not need freed.. why is that?

    // everything matched
    return 1;
}

/**
 * Edge case where size is 1
 */
int test_create_array_of_ints_fib2() {
	printf("2b. test_create_array_of_ints_fib2()\n");
	int *arr = create_array_of_ints_fib(1);
	//arr should be [1]
	if (arr[0] != 1){
		free(arr);
		return 0;
	} 

	return 1;


}

/**
 * Edge case where size is <= 0
 */
int test_create_array_of_ints_fib3() {
	printf("2c. test_create_array_of_ints_fib3()\n");
	//passing in 0 or a negative number should return null
	return (create_array_of_ints_fib(0) == NULL &&
			create_array_of_ints_fib(-5) == NULL);
}

/**
 * test reverse array of size 5
*/
int test_reverse_array1() {
    printf("3a. test_reverse_array()\n");

    int arr[5] = {1, 2, 3, 4, 5};
	reverse_array(arr, 5);
    int expected[] = {5, 4, 3, 2, 1};

	
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            //free(arr);
            return 0;
        } 
    }
    //free(arr); 
    // everything matched
    return 1;
}

/**
 * Tests reverse array with size of 1
*/
int test_reverse_array2() {
	printf("3b. test_reverse_array()\n");

	int arr[1] = {0};
	reverse_array(arr, 1);
	int expected[1] = {0};

	//array should just have 1 element with value of 0
	if (arr[0] != expected[0]) {
		//free(arr);
		return 0;	
	}
	//free(arr); 
	// everything matched
	return 1;
}

/**
 * Even length array
 */
int test_reverse_array3() {
	printf("3c. test_reverse_array3()\n");
	int arr[4] = {1, 2, 3, 4};
	reverse_array(arr, 4);
	int expected[] = {4, 3, 2, 1};

	for (int i = 0; i < 4; i++) {
		if (arr[i] != expected[i]) {
			//free(arr);
			return 0;
		} 
	}
	//free(arr); 
	// everything matched
	return 1;
}

/**
 * Tests double array with size of 5
*/
int test_double_array_size1() {
    printf("4a. test_double_array_size()\n");

    int arr[5] = {1, 2, 3, 4, 5};
	int *doubledArray = double_array_size(arr, 5);
	
	//should double size of array, filling rest of elements with a value of 0
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

/**
 * Tests double array with size of 1
*/
int test_double_array_size2() {
	printf("4b. test_double_array_size2()\n");

	int arr[1] = {0};
	int *doubledArray = double_array_size(arr, 1);
	//array should have 2 elements with value 0
	int expected[2] = {0, 0};
	for (int i = 0; i < 2; i++) {
		if (doubledArray[i] != expected[i]) {
			free(doubledArray);
			return 0;
		} 
	}
	free(doubledArray); 
	// everything matched
	return 1;
}

/**
 * Tests double array with size of 0
*/
int test_double_array_size3() {
	printf("4c. test_double_array_size3()\n");

	int arr[0] = {};
	int *doubledArray = double_array_size(arr, 0);
	//since we are indicating that size is 0, array should remain the same
	int expected[1] = {0};

	if (doubledArray[0] != expected[0]) {
		free(doubledArray);
		return 0;
	} 
	
	free(doubledArray); 
	// everything matched
	return 1;
}


/**
 * Tests copy_array_start_end_loop with start less than end
*/
int test_copy_array_start_end_loop1() {
    printf("5a. test_copy_array_start_end_loop1()\n");

	int newSize = 0;
    int arr[5] = {1, 2, 3, 4, 5};

	int *newArr = copy_array_start_end_loop(arr, 5, 1, 3, &newSize);

    int expected[] = {2, 3, 4};

    for (int i = 0; i < newSize; i++) {

        if (newArr[i] != expected[i]) {
            free(newArr);
            return 0;
        } 
    }
    free(newArr); 
    // everything matched
    return 1;
}

/**
 * Tests copy_array_start_end_loop with start greater than end
*/
int test_copy_array_start_end_loop2() {
	printf("5b. test_copy_array_start_end_loop2()\n");

	int newSize = 0;
	int arr[5] = {1, 2, 3, 4, 5};

	int *newArr = copy_array_start_end_loop(arr, 5, 3, 1, &newSize);

	int expected[] = {4, 5, 1, 2};

	for (int i = 0; i < newSize; i++) {
		//printf("arr 2 %d, %d\n", newArr2[i],  expected2[i]);
		if (newArr[i] != expected[i]) {
			free(newArr);
			return 0;
		} 
	}
 
	free(newArr); 
	// everything matched
	return 1;
}

/**
 * Tests copy_array_start_end_loop with start equal to end
*/
int test_copy_array_start_end_loop3() {
	printf("5c. test_copy_array_start_end_loop3()\n");

	int newSize = 0;
	int arr[5] = {1, 2, 3, 4, 5};


	int *newArr = copy_array_start_end_loop(arr, 5, 3, 3, &newSize);

	int expected[] = {4, 5, 1, 2, 3, 4};

	for (int i = 0; i < newSize; i++) {
		//printf("arr 2 %d, %d\n", newArr2[i],  expected2[i]);
		if (newArr[i] != expected[i]) {
			free(newArr);
			return 0;
		} 
	}
 
	free(newArr); 
	// everything matched
	return 1;
}


/**
 * Tests create point with positive numbers
*/
int test_create_point1(){
 	printf("6a. test_create_point1()\n");
	Point *myStruct = create_point(4, 5);
	//check x and y
	if ((myStruct->x != 4) || (myStruct->y != 5)){
		free(myStruct);
		return 0;
	}
	free(myStruct);
	return 1;
}

/**
 * Tests create point with negative values
*/
int test_create_point2(){
	printf("6b. test_create_point2()\n");
	Point *myStruct = create_point(-4, -5);
	//check x and y
	if ((myStruct->x != -4) || (myStruct->y != -5)){
		free(myStruct);
		return 0;
	}
	free(myStruct);
	return 1;
}

/**
 * Tests create point with 0s
*/
int test_create_point3(){
	printf("6c. test_create_point3()\n");
	Point *myStruct = create_point(0, 0);
	//check x and y
	if ((myStruct->x != 0) || (myStruct->y != 0)){
		free(myStruct);
		return 0;
	}
	free(myStruct);
	return 1;
}

/**
 * Tests create polygon
*/
int test_create_polygon1(){
 	printf("7a. test_create_polygon1()\n");
 	int size = 5;
	Polygon *polygon = create_polygon(size);

	//check size
	if (polygon->size != size){
		return 0;
	}
	//loop through points and make sure each x and y is 0
	for (int i = 0; i < size; i++) {
        if ((polygon->points[i]->x != 0) || (polygon->points[i]->y != 0)){
        	free_polygon(polygon);
			return 0;
		}
    }
	free_polygon(polygon);
	return 1;
}

/**
 * Tests create polygon edge case where size < 3
*/
int test_create_polygon2(){
	printf("7b. test_create_polygon2()\n");

	//check size
	if (create_polygon(2) != NULL){
		
		return 0;
	}

	return 1;
}


/**
 * Tests rectangle  
*/
int test_create_rectangle1(){
	printf("8a. test_create_rectangle3()\n");
	Polygon *rectangle = create_rectangle(4,5);

	//check size
	if (rectangle->size != 4){
		free_polygon(rectangle);
		return 0;
	} 

	//check all points
	if ((rectangle->points[0]->x != 0) || (rectangle->points[0]->y != 0)){
		free_polygon(rectangle);
		return 0;
	}
	if ((rectangle->points[1]->x != 4) || (rectangle->points[1]->y != 0)){
		free_polygon(rectangle);
		return 0;
	}
	if ((rectangle->points[2]->x != 4) || (rectangle->points[2]->y != 5)){
		free_polygon(rectangle);
		return 0;
	}
	if ((rectangle->points[3]->x != 0) || (rectangle->points[3]->y != 5)){
		free_polygon(rectangle);
		return 0;
	}
	free_polygon(rectangle);
	return 1;
}


/**
 * Tests square  
*/
int test_create_rectangle2(){
	printf("8b. test_create_rectangle2()\n");
	Polygon *rectangle = create_rectangle(3,3);
	if (rectangle->size != 4){
		free_polygon(rectangle);
		return 0;
	} 
	//check all points
	if ((rectangle->points[0]->x != 0) || (rectangle->points[0]->y != 0)){
		free_polygon(rectangle);
		return 0;
	}
	if ((rectangle->points[1]->x != 3) || (rectangle->points[1]->y != 0)){
		free_polygon(rectangle);
		return 0;
	}
	if ((rectangle->points[2]->x != 3) || (rectangle->points[2]->y != 3)){
		free_polygon(rectangle);
		return 0;
	}
	if ((rectangle->points[3]->x != 0) || (rectangle->points[3]->y != 3)){
		free_polygon(rectangle);
		return 0;
	}
	free_polygon(rectangle);
	return 1;
}

/**
 * Tests edge case where rectangle width and height are 0 or negative 
*/
int test_create_rectangle3(){
	printf("8c. test_create_rectanglec()\n");
	if (create_rectangle(-3, 0) != NULL){
		return 0;
	} 
	return 1;
}

/**
 * Tests triangle  
*/
int test_create_triangle1(){
	printf("9a. test_create_triangle1()\n");
	Polygon *triangle = create_triangle(4,5);
	if (triangle->size != 3){
		free_polygon(triangle);
		return 0;
	} 
	//check all points
	if ((triangle->points[0]->x != 0) || (triangle->points[0]->y != 0)){
		free_polygon(triangle);
		return 0;
	}
	if ((triangle->points[1]->x != 4) || (triangle->points[1]->y != 0)){
		free_polygon(triangle);
		return 0;
	}
	if ((triangle->points[2]->x != 4) || (triangle->points[2]->y != 5)){
		free_polygon(triangle);
		return 0;
	}
	free_polygon(triangle);
	return 1;
}

/**
 * Tests triangle with equal width and height  
*/
int test_create_triangle2(){
	printf("9b. test_create_triangle2()\n");
	Polygon *triangle = create_triangle(3, 3);
	if (triangle->size != 3){
		return 0;
	} 
	//check all points
	if ((triangle->points[0]->x != 0) || (triangle->points[0]->y != 0)){
		free_polygon(triangle);
		return 0;
	}
	if ((triangle->points[1]->x != 3) || (triangle->points[1]->y != 0)){
		free_polygon(triangle);
		return 0;
	}
	if ((triangle->points[2]->x != 3) || (triangle->points[2]->y != 3)){
		free_polygon(triangle);
		return 0;
	}
	free_polygon(triangle);
	return 1;
}

/**
 * Tests edge case of creating triangle with 0 or negative width and height
*/
int test_create_triangle3(){
	printf("9c. test_create_triangle3()\n");
	if (create_triangle(-3, 0) != NULL){
		return 0;
	} 

	return 1;
}

/**
 * test finding area of a rectangle
*/
int test_calculate_polygon_area1(){
	printf("10a. test_calculate_polygon_area1()\n");
	Polygon *rectangle = create_rectangle(4,5);

	double expected = 20.0; // has to be double to compare with returned value
	double area = calculate_polygon_area(rectangle);
	if (area != expected) {
		free_polygon(rectangle);
		return 0;
	}
	free_polygon(rectangle);
	return 1;
}

/**
 * test finding area of a triangle
*/
int test_calculate_polygon_area2(){
	printf("10b. test_calculate_polygon_area2()\n");
	Polygon *triangle = create_triangle(4,5);

	double expected = 10.0; //20 divided by 2
	double area = calculate_polygon_area(triangle);
	if (area != expected) {
		free_polygon(triangle);
		return 0;
	}
	free_polygon(triangle);
	return 1;
}



/**
 * test finding area of a square
*/
int test_calculate_polygon_area3(){
	printf("10c. test_calculate_polygon_area3()\n");
	Polygon *square = create_rectangle(3, 3);

	double expected = 9.0; 
	double area = calculate_polygon_area(square);
	if (area != expected) {
		free_polygon(square);
		return 0;
	}
	free_polygon(square);
	return 1;
}


// this is a list of all the unit tests
int (*unitTests[])() = {
    test_swap1,
	test_swap2,
	test_swap3,
    test_create_array_of_ints_fib1,
	test_create_array_of_ints_fib2,
	test_create_array_of_ints_fib3,
    // add more test function names here
	test_reverse_array1,
	test_reverse_array2,
	test_reverse_array3,
	test_double_array_size1,
	test_double_array_size2,
	test_double_array_size3,
	test_copy_array_start_end_loop1,
	test_copy_array_start_end_loop2,
	test_copy_array_start_end_loop3,
	test_create_point1,
	test_create_point2,
	test_create_point3,
	test_create_polygon1,
	test_create_polygon2,
	test_create_rectangle1,
	test_create_rectangle2,
	test_create_rectangle3,
	test_create_triangle1,
	test_create_triangle2,
	test_create_triangle3,
	test_calculate_polygon_area1,
	test_calculate_polygon_area2,
	test_calculate_polygon_area3
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
