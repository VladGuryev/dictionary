#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <experimental/string_view>
#include <map>
#include <set>
#include <vector>
#include <iostream>
//#include <string_view>
#include <deque>
#include <iterator>

using namespace std::experimental;
using namespace std;

struct Entry{
  explicit Entry(string_view str): source(str) {}
  string source;
  Entry* foreign = nullptr;
  bool operator<(const Entry& rhs) const{
    return source < rhs.source;
  }
};

class Translator {
public:
  Translator(){
  }
  ~Translator(){

  }
  void Add(string_view source, string_view target) {
    d_str.emplace_front(Entry(source));
    d_str.emplace_back(Entry(target));
    d_str.front().foreign = &d_str.back();
    d_str.back().foreign = &d_str.front();
  }
  string_view TranslateForward(string_view source) const{
   return extractStringFor(source);
  }
  string_view TranslateBackward(string_view target) const{
    return extractStringBack(target);
  }

private:
   deque<Entry> d_str;
   string_view extractStringFor(string_view sv) const;
   string_view extractStringBack(string_view sv) const;
};


string_view Translator::extractStringFor(string_view sv) const{
  string cmp(sv);
  for(size_t i = 0; i < d_str.size() / 2 ; ++i){
    if(d_str.at(i).source == cmp)
      return d_str.at(i).foreign->source;
    else
     continue;
  }

  return "";
}

string_view Translator::extractStringBack(string_view sv) const{
  string cmp(sv);
  for(size_t i = d_str.size() - 1; i > d_str.size() / 2 - 1 ; --i){
    if(d_str.at(i).source == cmp)
      return d_str.at(i).foreign->source;
    else
     continue;
  }

  return "";
}

#endif // TRANSLATOR_H
