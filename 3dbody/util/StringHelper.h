
#ifndef INC_3DBODY_STRING_HELPER_H
#define INC_3DBODY_STRING_HELPER_H

#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>

#ifdef GF_WIN

#include <windows.h>
#include <winnls.h>
#include <iostream>
#include <codecvt>

#endif

namespace gf {
using std::vector;
using std::string;

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

/**
 * this function converts utf8 to normal string.
 * @param str utf8 encoded string.
 * @return naive string.
 */
inline string utf8String(const std::string &str) {
  string ret;
#ifdef GF_WIN

  int     nwLen  = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
  wchar_t *pwBuf = new wchar_t[nwLen + 1];
  memset(pwBuf, 0, nwLen*2 + 2);
  MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);

  int  nLen  = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1,
								   NULL, NULL, NULL, NULL);
  char *pBuf = new char[nLen + 1];
  memset(pBuf, 0, nLen + 1);
  WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
  ret = pBuf;
  delete[] pwBuf;
  delete[] pBuf;

#elif defined(GF_LINUX)
  //FIXME: linux support.

#endif

  return ret;
}

/**
 * this function converts normal string to utf8 encoded string ,can be used in chinese characters.
 * @param str naive string.
 * @return utf8 encoded string.
 *
 */
inline string stringUtf8(const std::string &str) {
#ifdef GF_WIN
  int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
  wchar_t *pwBuf = new wchar_t[nwLen + 1];    //一定要加1，不然会出现尾巴
  ZeroMemory(pwBuf, nwLen*2 + 2);
  ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
  int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
  char *pBuf = new char[nLen + 1];
  ZeroMemory(pBuf, nLen + 1);
  ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

  std::string strRet(pBuf);

  delete[]pwBuf;
  delete[]pBuf;
  pwBuf = NULL;
  pBuf  = NULL;
  return strRet;
#elif defined(GF_LINUX)
  //FIXME: linux support.

#endif

}

}

#endif //INC_3DBODY_STRING_HELPER_H
