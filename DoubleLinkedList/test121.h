#ifndef TEST121_H
#define TEST121_H

#include <iostream>
#include <string>

using std::string;
using std::to_string;
using std::cerr;
using std::cout;
using std::endl;

#define MAKE_TEST_MSSG make_test_mssg(__FILE__, __FUNCTION__, __LINE__)

#define ASSERT_TRUE(X) assert_true(X,MAKE_TEST_MSSG)
#define ASSERT_FALSE(X) assert_true(X,MAKE_TEST_MSSG)
#define ASSERT_EQ(X,Y) assert_eq(X,Y,MAKE_TEST_MSSG)
#define ASSERT_NEQ(X,Y) assert_neq(X,Y,MAKE_TEST_MSSG)

#define EXPECT_TRUE(X) expect_true(X,MAKE_TEST_MSSG)
#define EXPECT_FALSE(X) expect_false(X,MAKE_TEST_MSSG)
#define EXPECT_EQ(X,Y) expect_eq(X,Y,MAKE_TEST_MSSG)
#define EXPECT_NEQ(X,Y) expect_neq(X,Y,MAKE_TEST_MSSG)
#define EXPECT_LT(X,Y) expect_lt(X,Y,MAKE_TEST_MSSG)
#define EXPECT_LEQ(X,Y) expect_leq(X,Y,MAKE_TEST_MSSG)
#define EXPECT_GT(X,Y) expect_gt(X,Y,MAKE_TEST_MSSG)
#define EXPECT_GEQ(X,Y) expect_geq(X,Y,MAKE_TEST_MSSG)

#define TEST_HEADER cout << __FUNCTION__ << endl; int p = passed; int f = failed;
#define TEST_FOOTER cout << "\t" << (passed-p) << "/" << (passed-p + failed-f) << " tests passed." << endl;

int passed = 0;
int failed = 0;

template <typename T>
void fail(const T& lhs, const T& rhs, const string mssg="") {
    cerr << "[FAIL] " << mssg << endl;
    cerr << "  lhs: " << lhs << endl;
    cerr << "  rhs: " << rhs << endl;
    failed++;
}

void fail(const bool expected, const bool actual, const string mssg="") {
    cerr << "[FAIL] " << mssg << endl;
    cerr << "  expected: " << expected << endl;
    cerr << "    actual: " << actual << endl;
    failed++;
}

void assert_true(const bool actual, const string mssg="") {
    if (!actual) {
        fail(true, actual, mssg+"\nexpected true");
        abort();
    }
    passed++;
}

void assert_false(const bool actual, const string mssg="") {
    if (actual) {
        fail(false, actual, mssg+"\nexpected false");
        abort();
    }
    passed++;
}

template <typename T>
void assert_eq(const T& actual, const T& expected, const string mssg="") {
    if (!(actual == expected)) {
        fail(expected, actual, mssg+"\nexpected ==");
        abort();
    }
    passed++;
}

template <typename T>
void assert_neq(const T& actual, const T& expected, const string mssg="") {
    if (actual == expected) {
        fail(expected, actual, mssg+"\nexpected !=");
        abort();
    }
    passed++;
}

bool expect_true(const bool actual, const string mssg="") {
    if (!actual) {
        fail(true, actual, mssg+"\nexpected true");
        return false;
    }
    passed++;
    return true;
}

bool expect_false(const bool actual, const string mssg="") {
    if (actual) {
        fail(false, actual, mssg+"\nexpected false");
        return false;
    }
    passed++;
    return true;
}

template <typename T>
bool expect_eq(const T& actual, const T& expected, const string mssg="") {
    if (!(actual == expected)) {
        fail(expected, actual, mssg+"\nexpected ==");
        return false;
    }
    passed++;
    return true;
}

template <typename T>
bool expect_neq(const T& actual, const T& expected, const string mssg="") {
    if (actual == expected) {
        fail(expected, actual, mssg+"\nexpected !=");
        return false;
    }
    passed++;
    return true;
}

template <typename T>
bool expect_lt(const T& lhs, const T& rhs, const string mssg="") {
    if (!(lhs < rhs)) {
        fail(lhs, rhs, mssg+"\nexpected <");
        return false;
    }
    passed++;
    return true;
}

template <typename T>
bool expect_leq(const T& lhs, const T& rhs, const string mssg="") {
    if (!(lhs <= rhs)) {
        fail(lhs, rhs, mssg+"\nexpected <=");
        return false;
    }
    passed++;
    return true;
}

template <typename T>
bool expect_gt(const T& lhs, const T& rhs, const string mssg="") {
    if (!(lhs > rhs)) {
        fail(lhs, rhs, mssg+"\nexpected >");
        return false;
    }
    passed++;
    return true;
}

template <typename T>
bool expect_geq(const T& lhs, const T& rhs, const string mssg="") {
    if (!(lhs >= rhs)) {
        fail(lhs, rhs, mssg+"\nexpected >=");
        return false;
    }
    passed++;
    return true;
}

string make_test_mssg(const char* file, const char* function, int line) {
    string mssg = "line ";
    mssg += to_string(line);
    mssg += " in ";
    mssg += file;
    mssg += ":";
    mssg += function;
    mssg += ":";
    return mssg;
}

#endif