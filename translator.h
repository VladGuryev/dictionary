#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <experimental/string_view>
#include <map>
#include <vector>
#include <iostream>
//#include <string_view>
#include <deque>

using namespace std::experimental;
using namespace std;

class Translator {
public:
  Translator(){
  }
  ~Translator(){
//    for(const auto& item: v_str_ptr){
//      delete item;
//    }
//    v_str_ptr.clear();
  }
  void Add(string_view source, string_view target) {
   // string* src = new string(source);
   // string* trg = new string(target);
    //if(d_str.)

    d_str.emplace_front(source);
    d_str.emplace_back(target);

    sources[&d_str.front()] = &d_str.back();
    targets[&d_str.back()] = &d_str.front();
  }
  string_view TranslateForward(string_view source) const{
   return extractString(source, sources);
  }
  string_view TranslateBackward(string_view target) const{
    return extractString(target, targets);
  }

private:
   map<string*, string*> sources;
   map<string*, string*> targets;
   deque<string> d_str;
   string_view extractString(string_view sv,
                             map<string*, string*> dict) const;
};


string_view Translator::extractString(string_view sv,
                                      map<string *, string *> dict) const{

//  auto it = dict.find(sv);
//  if(it == dict.end())
//    return "";
//  else{
//    return *it->second;
//  }
  string str_tmp = string(sv);
  map<string*, string *>::iterator it = dict.begin();
  while(true){
    if ((it == dict.end()) || (*it->first == sv))
      break;
    ++it;
  }

  if(it == dict.end()){
    return "";
  } else {
    return *it->second;
  }
}

#endif // TRANSLATOR_H
