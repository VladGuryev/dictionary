#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <experimental/string_view>
#include <map>
#include <set>
#include <vector>
#include <iostream>
//#include <string_view>
#include <deque>

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
    set<Entry>::iterator it = entries_f.find(Entry(source));
    set<Entry>::iterator it2 = entries_b.find(Entry(target));
    if(it != entries_f.end()){
      entries_f.erase(it);
    }
    if(it2 != entries_b.end()){
      entries_b.erase(it);
    }

    Entry* s = new Entry(source);
    Entry* t = new Entry(target);
    s->foreign = t;
    t->foreign = s;
    entries_f.insert(*s);
    entries_b.insert(*t);
  }
  string_view TranslateForward(string_view source) const{
   return extractString(source, entries_f);
  }
  string_view TranslateBackward(string_view target) const{
    return extractString(target, entries_b);
  }

private:
   map<string*, string*> sources;
   map<string*, string*> targets;
   deque<string> d_str;
   string_view extractString(string_view sv, set<Entry> entries) const;
   set<Entry> entries_f;
   set<Entry> entries_b;
};


string_view Translator::extractString(string_view sv,
                                      set<Entry> entries) const{
  auto it = entries.find(Entry(sv));
  if(it == entries.end()){
    return "";
  } else {
    return (*it).foreign->source;
  }
}

#endif // TRANSLATOR_H
