
#ifndef INC_3DBODY_STRING_HELPER_H
#define INC_3DBODY_STRING_HELPER_H

#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>
#include  <include/nfd.h>
#include <cctype>
#ifdef GF_WIN

#include <windows.h>
#include <winnls.h>
#include <iostream>
#include <codecvt>

#endif

namespace gf {

using std::string;

extern nfdfilteritem_t cvtFilter(const char *each) {
  nfdfilteritem_t res;
  string_view     temp = string_view(each).substr(1);
//  char            *copy;
//  copy = (char *)malloc(strlen(each) - 1);
//  for (int i = 1; i < strlen(each); i++) {
//	copy[i - 1] = each[i];
//  }
  res.name = temp.data();
  res.spec = temp.data();
  return res;
}

/**
 * this method is used to parse string by token.
 * @param str string to be parsed.
 * @param token regex token.
 * @return
 */
inline vector<string> parseStdStringByRegex(const string &str, const string &token) {
  vector<string> ret;
  std::regex     pattern(token);
  std::smatch    results;
  if (std::regex_match(str.cbegin(), str.cend(), results, pattern)) {
	auto it = results.begin();
	while (it!=results.end()) {
	  ret.emplace_back(*it);
	  it++;
	}
  }
  return ret;
}

/**
 * this method is used to parse string by white space.
 * @param str string to be parsed.
 * @return parsed list.
 */
inline vector<string> parseStdStringBySpace(const string &str) {
  if (str.find(" ")==std::string::npos)return vector<string>();
  vector<string>     ret;
  std::istringstream iss(str);
  string             temp;
  while (iss >> temp) {
	if (temp.size()) ret.emplace_back(temp);
	temp = "";
  }
  return ret;
}

inline vector<string> parseStringByDoubleSpace(string &str) {
  if (str.empty())return vector<string>();
  for (int           i    = 0; i < str.size(); i++) {
	if (str[i]==' ' && i < str.size() - 1 && str[i + 1]==' ')str[i] = '\n';
  }
  vector<string>     ret;
  std::istringstream iss(str);
  string             line = "";
  while (std::getline(iss, line)) {
	if (!line.empty()) {
	  line.erase(0, line.find_first_not_of(' '));
	  if (!line.empty())ret.emplace_back(line);
	}
	continue;
  }
  return ret;
}

/**
 * this method is used to parse string by comma.
 * @param str string to be parsed.
 * @return parsed list.
 */
inline vector<string> parseStdStringByComma(const string &str) {
  string             temp = str;
  for (int           i    = 0; i < temp.size(); i++) {
	if (temp[i]==';')temp[i] = ' ';
  }
  vector<string>     ret;
  std::istringstream iss(temp);
  string             item;
  while (iss >> item) {
	if (item.size())ret.emplace_back(item);
  }
  return ret;
}

/**
 * this method is used to parse trim white space of string.
 * @param str string to be trimmed.
 * @return trimmed string.
 */
inline string &trim(string &str) {
  if (str.empty())return str;
  str.erase(0, str.find_first_not_of(' '));
  str.erase(str.find_last_not_of(' ') + 1);
  return str;
}

}

#endif //INC_3DBODY_STRING_HELPER_H
