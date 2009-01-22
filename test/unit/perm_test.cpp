// -*- C++ -*- Time-stamp: <09/01/23 01:08:45 ptr>

/*
 * Copyright (c) 2004-2009
 * Petr Ovtchenkov
 *
 * Copyright (c) 2004-2008
 * Francois Dumont
 *
 * Licensed under the Academic Free License Version 3.0
 *
 */

#include "perm_test.h"

#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

#include "iota.h"

#if !defined (STLPORT) || defined(_STLP_USE_NAMESPACES)
using namespace std;
#endif

int EXAM_IMPL(perm_test::prevprm0)
{
  int v1[3] = { 0, 1, 2 };
  prev_permutation(v1, v1 + 3);

  EXAM_CHECK(v1[0]==2);
  EXAM_CHECK(v1[1]==1);
  EXAM_CHECK(v1[2]==0);

  return EXAM_RESULT;
}

int EXAM_IMPL(perm_test::prevprm1)
{
  vector <int> v1(3);
  __iota(v1.begin(), v1.end(), 0);

  prev_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==2);
  EXAM_CHECK(v1[1]==1);
  EXAM_CHECK(v1[2]==0);
  prev_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==2);
  EXAM_CHECK(v1[1]==0);
  EXAM_CHECK(v1[2]==1);
  prev_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==0);
  prev_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==0);
  EXAM_CHECK(v1[2]==2);
  prev_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==0);
  EXAM_CHECK(v1[1]==2);//
  EXAM_CHECK(v1[2]==1);
  prev_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==0);
  EXAM_CHECK(v1[1]==1);
  EXAM_CHECK(v1[2]==2);
  prev_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==2);
  EXAM_CHECK(v1[1]==1);
  EXAM_CHECK(v1[2]==0);
  prev_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==2);
  EXAM_CHECK(v1[1]==0);
  EXAM_CHECK(v1[2]==1);
  prev_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==0);

  return EXAM_RESULT;
}

int EXAM_IMPL(perm_test::prevprm2)
{
  vector <int> v1(3);
  __iota(v1.begin(), v1.end(), 0);

  prev_permutation(v1.begin(), v1.end(), greater<int>());
  EXAM_CHECK(v1[0]==0);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==1);
  prev_permutation(v1.begin(), v1.end(), greater<int>());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==0);
  EXAM_CHECK(v1[2]==2);
  prev_permutation(v1.begin(), v1.end(), greater<int>());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==0);
  prev_permutation(v1.begin(), v1.end(), greater<int>());
  EXAM_CHECK(v1[0]==2);
  EXAM_CHECK(v1[1]==0);
  EXAM_CHECK(v1[2]==1);
  prev_permutation(v1.begin(), v1.end(), greater<int>());
  EXAM_CHECK(v1[0]==2);
  EXAM_CHECK(v1[1]==1);
  EXAM_CHECK(v1[2]==0);
  prev_permutation(v1.begin(), v1.end(), greater<int>());
  EXAM_CHECK(v1[0]==0);
  EXAM_CHECK(v1[1]==1);
  EXAM_CHECK(v1[2]==2);
  prev_permutation(v1.begin(), v1.end(), greater<int>());
  EXAM_CHECK(v1[0]==0);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==1);
  prev_permutation(v1.begin(), v1.end(), greater<int>());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==0);
  EXAM_CHECK(v1[2]==2);
  prev_permutation(v1.begin(), v1.end(), greater<int>());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==0);

  return EXAM_RESULT;
}

int EXAM_IMPL(perm_test::nextprm0)
{
  int v1[3] = { 0, 1, 2 };
  next_permutation(v1, v1 + 3);

  EXAM_CHECK(v1[0]==0);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==1);

  return EXAM_RESULT;
}

int EXAM_IMPL(perm_test::nextprm1)
{
  vector <int> v1(3);
  __iota(v1.begin(), v1.end(), 0);

  next_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==0);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==1);
  next_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==0);
  EXAM_CHECK(v1[2]==2);
  next_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==0);
  next_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==2);
  EXAM_CHECK(v1[1]==0);
  EXAM_CHECK(v1[2]==1);
  next_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==2);
  EXAM_CHECK(v1[1]==1);
  EXAM_CHECK(v1[2]==0);
  next_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==0);
  EXAM_CHECK(v1[1]==1);
  EXAM_CHECK(v1[2]==2);
  next_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==0);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==1);
  next_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==0);
  EXAM_CHECK(v1[2]==2);
  next_permutation(v1.begin(), v1.end());
  EXAM_CHECK(v1[0]==1);
  EXAM_CHECK(v1[1]==2);
  EXAM_CHECK(v1[2]==0);

  return EXAM_RESULT;
}

int EXAM_IMPL(perm_test::nextprm2)
{
  vector <char> v1(3);
  __iota(v1.begin(), v1.end(), 'A');

  next_permutation(v1.begin(), v1.end(), less<char>());
  EXAM_CHECK(v1[0]=='A');
  EXAM_CHECK(v1[1]=='C');
  EXAM_CHECK(v1[2]=='B');
  next_permutation(v1.begin(), v1.end(), less<char>());
  EXAM_CHECK(v1[0]=='B');
  EXAM_CHECK(v1[1]=='A');
  EXAM_CHECK(v1[2]=='C');
  next_permutation(v1.begin(), v1.end(), less<char>());
  EXAM_CHECK(v1[0]=='B');
  EXAM_CHECK(v1[1]=='C');
  EXAM_CHECK(v1[2]=='A');
  next_permutation(v1.begin(), v1.end(), less<char>());
  EXAM_CHECK(v1[0]=='C');
  EXAM_CHECK(v1[1]=='A');
  EXAM_CHECK(v1[2]=='B');
  next_permutation(v1.begin(), v1.end(), less<char>());
  EXAM_CHECK(v1[0]=='C');
  EXAM_CHECK(v1[1]=='B');
  EXAM_CHECK(v1[2]=='A');
  next_permutation(v1.begin(), v1.end(), less<char>());
  EXAM_CHECK(v1[0]=='A');
  EXAM_CHECK(v1[1]=='B');
  EXAM_CHECK(v1[2]=='C');
  next_permutation(v1.begin(), v1.end(), less<char>());
  EXAM_CHECK(v1[0]=='A');
  EXAM_CHECK(v1[1]=='C');
  EXAM_CHECK(v1[2]=='B');
  next_permutation(v1.begin(), v1.end(), less<char>());
  EXAM_CHECK(v1[0]=='B');
  EXAM_CHECK(v1[1]=='A');
  EXAM_CHECK(v1[2]=='C');
  next_permutation(v1.begin(), v1.end(), less<char>());
  EXAM_CHECK(v1[0]=='B');
  EXAM_CHECK(v1[1]=='C');
  EXAM_CHECK(v1[2]=='A');

  return EXAM_RESULT;
}
