/*
 * This file demonstrates how to use the std::sort() function.  For more about
 * std::sort(), check out its documentation:
 *
 * http://www.cplusplus.com/reference/algorithm/sort/
 */

#include <iostream>

/*
 * You need to #include <algorithm> to be able to use std::sort().
 */
#include <algorithm>

/*
 * In this file, we'll work on sorting an array of these student structures.
 */
struct student {
  std::string name;
  float gpa;
};

/*
 * Below is some testing data (names and GPAs) for 10 students.
 */
#define N_STUDENTS 10

const std::string NAMES[N_STUDENTS] = {
  "Luke Skywalker",
  "Princess Leia",
  "Han Solo",
  "Rey",
  "Poe Dameron",
  "Finn",
  "Jynn Erso",
  "Darth Vader",
  "Kylo Ren",
  "R2-D2"
};

const float GPAS[N_STUDENTS] = {
  3.9,
  4.0,
  2.67,
  3.95,
  3.25,
  3.67,
  3.5,
  2.25,
  1.67,
  4.0
};

/*
 * When sorting structs, std::sort() needs us to give it a function to tell it
 * how to compare those structs.  The function takes two arguments to hold two
 * things to compare and should return true if the first thing goes before the
 * second thing in sorted order.  It should return false if the second thing
 * should go before the first thing.
 *
 * Here we have two different functions to compare students based on their GPA.
 * The first one is used to sort students by descending GPA (high GPAs first,
 * low GPAs last) by returning true when the first student's GPA is greater
 * than the second student's.  The second function is used to sort students by
 * ascending GPA (low GPAs first, high GPAs last) by returning true when the
 * first student's GPA is less than the second student's.
 */
bool cmp_students_desc_gpa(const struct student& s1, const struct student& s2) {
  return (s1.gpa > s2.gpa);
}

bool cmp_students_asc_gpa(const struct student& s1, const struct student& s2) {
  return (s1.gpa < s2.gpa);
}

int main(int argc, char const *argv[]) {

  /*
   * Here, we're dynamically allocating and initializing an array of students.
   */
  struct student* students = new struct student[N_STUDENTS];
  for (int i = 0; i < N_STUDENTS; i++) {
    students[i].name = NAMES[i];
    students[i].gpa = GPAS[i];
    std::cout << students[i].name << "\t\t" << students[i].gpa << std::endl;
  }

  /*
   * This is our call to std::sort().  To sort an array, the first argument
   * is a pointer to the beginning of the array, and the second argument is a
   * pointer to the end of the array (here, students + N_STUDENTS points to
   * the memory address immediately *after the array; it's the same as
   * &students[N_STUDENTS]).  The third argument is the function we'll use to
   * compare elements in the array.
   */
  std::sort(students, students + N_STUDENTS, cmp_students_asc_gpa);

  /*
   * Now when we print the students, they're in sorted order.
   */
  std::cout << std::endl << std::endl;
  for (int i = 0; i < N_STUDENTS; i++) {
    std::cout << students[i].name << "\t\t" << students[i].gpa << std::endl;
  }

  delete[] students;

  return 0;
}
