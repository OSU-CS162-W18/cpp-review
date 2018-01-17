#include <iostream>

/*
 * A struct is a user-defined data type that can be used to aggregate data
 * about a specific entity (e.g. a student).  Below is the syntax for creating
 * a new type of struct to model a single student.  The struct contains 4
 * fields to hold the student's name, their ID, their GPA, and a pointer to
 * another student who is this student's partner.
 */
struct student {
  std::string name;
  int id;
  double gpa;
  struct student* partner;

};

int main(int argc, char const *argv[]) {
  /*
   * An instance of a struct can be statically allocated like below.  The
   * fields of a struct value can be accessed using the dot (.) operator.
   */
  struct student s1;
  s1.name = "Luke Skywalker";
  s1.id = 933111111;
  s1.gpa = 3.9;
  std::cout << s1.name << " " << s1.id << " " << s1.gpa << std::endl;

  /*
   * A statically-allocated struct can be initialized using a designated
   * initializer, like we do here for Leia.
   */
  struct student s2 = {
    .name = "Princess Leia",
    .id = 933222222,
    .gpa = 4.0
  };
  std::cout << s2.name << " " << s2.id << " " << s2.gpa << std::endl;

  /*
   * A single struct value can be dynamically allocated, like we do here.
   * When we have a pointer to a struct, we need to dereference the pointer
   * before we can access the fields of the struct.  This can be done using
   * the -> operator, which is functionally equivalent to (*s_dyn)..
   */
  struct student* s_dyn = new struct student;
  (*s_dyn).name = "Darth Vader";
  s_dyn->id = 933999999;
  s_dyn->gpa = 1.5;
  std::cout << s_dyn->name << " " << s_dyn->id << " " << s_dyn->gpa << std::endl;

  s1.partner = s_dyn;
  s2.partner = &s1;
  s_dyn->partner = &s2;

  /*
   * A single dynamically-allocated struct can be freed using delete.
   */
  delete s_dyn;

}
