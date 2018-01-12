#include <iostream>

void make_it_32(int& it) {
  it = 32;
}

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


  make_it_32(n);
  std::cout << "n: " << n << std::endl;

  int* n_dyn = new int;
  delete n_dyn;

  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8};
  int array2d[3][3];

  int* array_dyn = new int[8];

  array_dyn[0] = 5;
  array_dyn[4] = 20;

  *array_dyn = 10;
  *(array_dyn + 4) = 10;

  std::cout << std::endl;
  std::cout << "array_dyn[0]: " << array_dyn[0] << std::endl;
  std::cout << "array_dyn[4]: " << array_dyn[4] << std::endl;

  for (int i = 0, * ptr = array_dyn; i < 8; i++, ptr++) {
    *ptr = i * 10;
    // array_dyn[i] = i * 10;
  }

  int** matrix = new int*[3];
  for (int i = 0; i < 3; i++) {
    matrix[i] = new int[3];
  }

  for (int i = 0; i < 3; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;

  delete[] array_dyn;

  int* array2 = create_array(10);
  delete[] array2;

}
