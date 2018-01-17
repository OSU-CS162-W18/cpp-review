#include <iostream>

/*
 * This function takes a reference to an int as an argument.  Since the
 * argument is a reference, it can be modified within the function, and the
 * change will take effect in the calling function.
 */
void make_it_32(int& it) {
  it = 32;
}

/*
 * This function demonstrates how an array can be dynamically allocated within
 * a function and returned back to the calling function.
 */
int* create_array(int n) {
  int* array = new array[n];
  return array;
}

int main(int argc, char const *argv[]) {
  /*
   * Here we're making an int variable n and a pointer variable n_ptr.  n_ptr
   * holds the *address* of n (i.e. it points to n).
   */
  int n = 16;
  int* n_ptr = &n;

  /*
   * When we print the *value* stored in n_ptr, we can see it's the same as
   * the *address* of n.  We can use the * operator to dereference n_ptr, i.e.
   * to get the value stored at the memory address to which n_ptr points.
   */
  std::cout << "n_ptr: " << n_ptr << std::endl;
  std::cout << "&n: " << &n << std::endl;
  std::cout << "*n_ptr: " << *n_ptr << std::endl;

  /*
   * We can also use the dereference operator to *update* the value stored at
   * the memory address to which n_ptr points.  When we print the value of n
   * after doing this, we can see that it has changed.
   */
  *n_ptr = 8;
  std::cout << "n: " << n << std::endl;

  /*
   * A reference can be used very much like a pointer.  Here we make a new
   * variable n_ref that references n.  We can also use this reference to
   * update the value stored in n.
   */
  int& n_ref = n;
  n_ref = 4;
  std::cout << "n: " << n << std::endl;

  /*
   * Because the argument to make_it_32() is a reference, the change made to
   * the argument in that function will affect the value of n here.
   */
  make_it_32(n);
  std::cout << "n: " << n << std::endl;

  /*
   * This is how a single value can be dynamically allocated (i.e. allocated
   * on the heap).  When we have a pointer to a single value like this, we can
   * free the memory using the delete operator.
   */
  int* n_dyn = new int;
  delete n_dyn;

  /*
   * Here's how we create a statically-allocated (i.e. allocated on the call
   * stack) 1D array and a statically-allocated 2D array.  The first 8 values
   * of the 1D array are initialized.  The values that aren't explicitly
   * initialized here (i.e. the last 2 values) will be initialized to 0.
   */
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8};
  int array2d[3][3];

  /*
   * This is how we dynamically allocate an array.
   */
  int* array_dyn = new int[8];

  /*
   * We can access the elements of a dynamically-allocated array using the []
   * operator, just like we do with a statically-allocated array.
   */
  array_dyn[0] = 5;
  array_dyn[4] = 20;

  /*
   * The bracket operators above are equivalent to the pointer arithmatic
   * below.  Specifically, array_dyn[0] is equivalent to *array_dyn (or
   * *(array_dyn + 0)), and *(array_dyn + 4) is equivalent to array_dyn[4].
   */
  *array_dyn = 10;
  *(array_dyn + 4) = 10;

  std::cout << std::endl;
  std::cout << "array_dyn[0]: " << array_dyn[0] << std::endl;
  std::cout << "array_dyn[4]: " << array_dyn[4] << std::endl;

  /*
   * Pointer arithmetic can be useful for stepping through an array, like
   * below.  Each iteration of this loop is equivalent to running the following
   * line:
   *
   * array_dyn[i] = i * 10;
   */
  for (int i = 0, * ptr = array_dyn; i < 8; i++, ptr++) {
    *ptr = i * 10;
  }

  /*
   * To free a dynamically-allocated array, we need to use the delete[]
   * operator.
   */
  delete[] array_dyn;


  /*
   * A 2D array is actually an 1D array of 1D arrays.  To allocate a 2D array,
   * we first need to allocate the outer 1D array, and then we can allocate
   * each of the inner 1D arrays, like we do below.
   */
  int** matrix = new int*[3];
  for (int i = 0; i < 3; i++) {
    matrix[i] = new int[3];
  }

  /*
   * Freeing a dynamically-allocated 2D array mirrors the way that array was
   * allocated: we first need to loop through the array and free each of the
   * inner arrays.  Only after each of these is freed (using the delete[]
   * operator) can we free the outer array (also using delete[]).
   */
  for (int i = 0; i < 3; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;

  /*
   * Here, array2 is allocated by the function create_array().  We can still
   * free it using delete[] in main().
   */
  int* array2 = create_array(10);
  delete[] array2;

}
