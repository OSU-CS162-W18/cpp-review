#include <iostream>

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

}
