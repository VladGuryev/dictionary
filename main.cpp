#include <string>
#include <experimental/string_view>
#include <iostream>

#include "translator.h"
#include "test_runner.h"
#include "profile.h"

using namespace std::experimental;
using namespace std;

void TestSimple ()
{
  Translator translator;
  translator.Add (string ("okno"), string ("window"));
  translator.Add (string ("stol"), string ("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateForward("stol"), "table");
  ASSERT_EQUAL(translator.TranslateForward("table"), "");
  ASSERT_EQUAL(translator.TranslateForward("window"), "");

  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("window"), "okno");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
  ASSERT_EQUAL(translator.TranslateBackward("okno"), "");

  translator.Add (string ("stol"), string ("table2"));
  translator.Add (string ("stol"), string ("table3"));
  ASSERT_EQUAL(translator.TranslateForward("stol"), "table3");
  ASSERT_EQUAL(translator.TranslateBackward("table3"), "stol");
}

string_view fun(){
  string* str = new string("abcd");
  string_view sv(*str);
  delete str;
  return sv;
}

int main ()
{
  TestRunner tr;
  RUN_TEST (tr, TestSimple);

  //cout << fun() << endl;
  return 0;
}
