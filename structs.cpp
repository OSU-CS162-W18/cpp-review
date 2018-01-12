#include <iostream>

struct student {
  std::string name;
  int id;
  double gpa;
  struct student* partner;

};

int main(int argc, char const *argv[]) {
  struct student s1;

  s1.name = "Luke Skywalker";
  s1.id = 933111111;
  s1.gpa = 3.9;

  std::cout << s1.name << " " << s1.id << " " << s1.gpa << std::endl;

  struct student s2 = {
    .name = "Princess Leia",
    .id = 933222222,
    .gpa = 4.0
  };
  s2.partner = &s1;
  std::cout << s2.name << " " << s2.id << " " << s2.gpa << std::endl;

  struct student* s_dyn = new struct student;
  (*s_dyn).name = "Darth Vader";
  s_dyn->id = 933999999;
  s_dyn->gpa = 1.5;

  std::cout << s_dyn->name << " " << s_dyn->id << " " << s_dyn->gpa << std::endl;

  delete s_dyn;

}
