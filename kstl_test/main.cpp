#include<ntifs.h>
#include<ntddk.h>
#include<wdm.h>
#include "kmtest.h"
#include "kernelcmnlib/kernelstl.hpp"

template<typename... types>
void print(types... args)
{
	DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, args...);
}

struct MyData {
  int age;
  char* name;
};

SCENARIO("List test") {
  cmd::List<MyData> l;

  // 这种写法好像是类必须支持C++的initializer_list
  // l.pushBack({1, "1"});

  l.pushBack(MyData(1, (char*)"1"));
  l.pushBack(MyData(2, (char*)"2"));
  l.pushBack(MyData(3, (char*)"3"));
  l.pushBack(MyData(4, (char*)"4"));

  print("list size %d\n", l.getSize());

  l.removeIf([](MyData& Data) {
    if (Data.age == 1)
      return true;
    else
      return false;
  });

  print("list size %d\n", l.getSize());

  cmd::AtomicBool B;
  B = true;

  cmd::HashMap<int, char*> hm;

  hm.insert(1, (char*)"123");
}