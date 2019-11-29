#include <iostream>
#include <string>
#include "Stack.h"
#include "test121.h"

using std::cout;
using std::endl;
using std::string;

void test_empty() {
    TEST_HEADER
    
    {
        Stack<int> stack;
        
        EXPECT_TRUE(stack.empty());
        
        stack.push(1);
        
        EXPECT_FALSE(stack.empty());
        
        stack.pop();
        
        EXPECT_TRUE(stack.empty());
    }
    
    {
        Stack<string> stack;
        
        EXPECT_TRUE(stack.empty());
        
        stack.push("1");
        
        EXPECT_FALSE(stack.empty());
        
        stack.pop();
        
        EXPECT_TRUE(stack.empty());
    }
    
    TEST_FOOTER
}

void test_push_pop_peek() {
    TEST_HEADER
    
    Stack<int> stack;
    
    // test push
    stack.push(8);
    
    EXPECT_EQ(8, stack.peek());
    
    stack.push(6);
    
    EXPECT_EQ(6, stack.peek());
    
    stack.push(7);
    
    EXPECT_EQ(7, stack.peek());
    
    stack.push(5);
    
    EXPECT_EQ(5, stack.peek());
    
    stack.push(3);
    
    EXPECT_EQ(3, stack.peek());
    
    stack.push(0);
    
    EXPECT_EQ(0, stack.peek());
    
    stack.push(9);
    
    EXPECT_EQ(9, stack.peek());
    
    // test peek
    stack.peek() = 10;
    
    EXPECT_EQ(10, stack.peek());
    
    // test pop
    stack.pop();
    
    EXPECT_EQ(0, stack.peek());
    
    stack.pop();
    
    EXPECT_EQ(3, stack.peek());
    
    stack.pop();
    
    EXPECT_EQ(5, stack.peek());
    
    stack.pop();
    
    EXPECT_EQ(7, stack.peek());
    
    stack.pop();
    
    EXPECT_EQ(6, stack.peek());
    
    stack.pop();
    
    EXPECT_EQ(8, stack.peek());
    
    TEST_FOOTER
}

void test_rule_of_three() {
    TEST_HEADER
    
    {
        Stack<int> s1;
        s1.push(1);
        s1.push(2);
        s1.push(3);
        
        // copy constructor
        Stack<int> s2 = s1;
        
        EXPECT_EQ(3, s1.peek());
        EXPECT_EQ(3, s2.peek());
        
        s2.peek() = 4;
        
        EXPECT_EQ(3, s1.peek());
        EXPECT_EQ(4, s2.peek());
        
        s2.pop();
        
        EXPECT_EQ(3, s1.peek());
        EXPECT_EQ(2, s2.peek());
        
        s1.pop();
        
        EXPECT_EQ(2, s1.peek());
        EXPECT_EQ(2, s2.peek());
        
        s1.push(3);
        
        EXPECT_EQ(3, s1.peek());
        EXPECT_EQ(2, s2.peek());
    }
    
    {
        Stack<char> s1;
        s1.push('a');
        s1.push('b');
        s1.push('c');
        
        Stack<char> s2;
        s2.push('d');
        s2.push('e');
        s2.push('f');
        
        EXPECT_EQ('c', s1.peek());
        EXPECT_EQ('f', s2.peek());
        
        // copy assignment
        s2 = s1;
        
        EXPECT_EQ('c', s1.peek());
        EXPECT_EQ('c', s2.peek());
        
        s1.peek() = 'z';
        
        EXPECT_EQ('z', s1.peek());
        EXPECT_EQ('c', s2.peek());
        
        s1.push('d');
        
        EXPECT_EQ('d', s1.peek());
        EXPECT_EQ('c', s2.peek());
        
        // copy (self-)assignment
        s1 = s1;
        
        EXPECT_EQ('d', s1.peek());
        EXPECT_EQ('c', s2.peek());
        
        s1.pop();
        
        EXPECT_EQ('z', s1.peek());
        EXPECT_EQ('c', s2.peek());
        
        s1.pop();
        s1.pop();
        s1.pop();
        
        EXPECT_TRUE(s1.empty());
        EXPECT_FALSE(s2.empty());
        EXPECT_EQ('c', s2.peek());
        
        s2.push('d');
        
        EXPECT_TRUE(s1.empty());
        EXPECT_EQ('d', s2.peek());    
    }
    
    TEST_FOOTER
}

int main() {
    
    test_push_pop_peek();
    test_empty();
    test_rule_of_three();
    
    
    cout << "TOTAL" << endl;
    cout << "-----" << endl;
    cout << passed << "/" << (passed + failed) << " tests passed." << endl;    
    
    return 0;
}