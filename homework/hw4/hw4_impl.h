#ifndef HW4_IMPL_H
#define HW4_IMPL_H

#include <string>
#include <vector>

#include "hw4.h"

typedef long long int ll;

std::vector<int> stringMatch_naive(std::string const& text,
                                   std::string const& pattern)
{
  // Implemente aqui el método mas ingenuo para resolver el problema de string
  // matching.
  std::vector<int> ret;

  int sz = text.size();
  for(int i = 0; i < sz; i++) {
    int c = i;
    while(c < sz && c - i < pattern.size() && text[c] == pattern[c - i]) c++;
    if(c - i == pattern.size()) ret.push_back(i);
  }

  return ret;
}


std::vector<int> stringMatch_RabinKarp(std::string const& text,
                                       std::string const& pattern)
{
  // Implemente aqui el algoritmo de Rabin-Karp para resolver el problema
  // de string matching.

  const ll mod = 1e9 + 7;
  std::vector<int> ret;

  const ll b = 5;
  int pattern_sz = pattern.size();
  int text_sz = text.size();
  
  ll pattern_hash = 0;
  ll text_hash = 0;
  ll pow_b = 1;
  for(int i = 0; i < pattern_sz; i++) {
    pattern_hash = (pattern_hash * b + (pattern[i] - 'a' + 1)) % mod;
    text_hash = (text_hash * b + (text[i] - 'a' + 1)) % mod;
  }

  for(int i = 1; i <= pattern_sz - 1; i++) {
    pow_b = (pow_b * b) % mod;
  }

  if(text_hash == pattern_hash){
    ret.push_back(0);
  }
  for(int i = pattern_sz; i < text_sz; i++) {
    text_hash = ((text_hash - (text[i - pattern_sz] - 'a' + 1) * pow_b) * b + (text[i] - 'a' + 1) + mod) % mod;
    if(text_hash == pattern_hash) ret.push_back(i - pattern_sz + 1);
  }

  return ret;
}

std::vector<int> stringMatch_KnuthMorrisPratt(std::string const& text,
                                              std::string const& pattern)
{
  std::vector<int> ret;
  
  std::string s = pattern + "#" + text;
  int text_sz = s.size();
  int pattern_sz = pattern.size();

  std::vector<int> pi(text_sz);

  for(int i = 1;i<text_sz;i++){
    int j = pi[i-1];
    while(j > 0 && s[i] != s[j]) j = pi[j-1];
    if(s[i] == s[j]) j++;
    pi[i] = j;
  }

  for(int i = pattern_sz;i<text_sz;i++){
    if(pi[i] == pattern_sz){
      ret.push_back(i - 2 * pattern_sz);
    }
  }
  return ret;
}


#endif
