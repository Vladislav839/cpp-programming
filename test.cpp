#include "pch.h"
#include "../Stack_calculator/Stack.h"
#include "../Stack_calculator/calculator.h"

TEST(calculator, Calculate_method_test) {
  Calculator calc;
  calc.set_expression("2+2*2");
  EXPECT_EQ(calc.calculate(), 6);
  calc.set_expression("10 + 2 * 6");
  EXPECT_EQ(calc.calculate(), 22);
  calc.set_expression("100 * 2 + 12");
  EXPECT_EQ(calc.calculate(), 212);
  calc.set_expression("100*(2+12)");
  EXPECT_EQ(calc.calculate(), 1400);
  calc.set_expression("100 * ( 2 + 12 ) / 14");
  EXPECT_EQ(calc.calculate(), 100);
}

TEST(stack, Stack_push_tests) {
  Stack<int> st;
  st.push(15);
  ASSERT_EQ(st.top(), 15);
  st.push(25);
  ASSERT_EQ(st.top(), 25);
  st.push(37);
  ASSERT_EQ(st.top(), 37);
}

TEST(stack, Stack_pop_tests) {
  Stack<int> st;
  st.push(15);
  st.push(27);
  st.push(93);
  st.pop();
  ASSERT_EQ(st.top(), 27);
  st.pop();
  ASSERT_EQ(st.top(), 15);
}

TEST(stack, Stack_top_tests) {
  Stack<int> st;
  st.push(15);
  ASSERT_EQ(st.top(), 15);
  st.push(29);
  ASSERT_EQ(st.top(), 29);
}

TEST(stack, stack_size_tests) {
  Stack<int> st;
  ASSERT_EQ(st.Size(), 0);
  st.push(15);
  st.push(27);
  st.push(93);
  ASSERT_EQ(st.Size(), 3);
  st.pop();
  ASSERT_EQ(st.Size(), 2);
}

TEST(stack, stack_empty_tests) {
  Stack<int> st;
  ASSERT_TRUE(st.empty());
  st.push(10);
  ASSERT_FALSE(st.empty());
}

TEST(stack, operator_ind) {
  Stack<int> st;
  st.push(15);
  st.push(27);
  st.push(93);
  ASSERT_EQ(st[2], 93);
  ASSERT_EQ(st[1], 27);
  ASSERT_EQ(st[0], 15);
}

TEST(stack, operator_eq) {
  Stack<int> st1;
  st1.push(15);
  st1.push(27);
  st1.push(93);
  Stack<int> st2;
  st2.push(15);
  st2.push(27);
  st2.push(93);
  ASSERT_TRUE(st1 == st2);
  st2.push(25);
  ASSERT_FALSE(st1 == st2);
}

TEST(stack, operator_not_eq) {
  Stack<int> st1;
  st1.push(15);
  st1.push(27);
  st1.push(93);
  Stack<int> st2;
  st2.push(15);
  st2.push(27);
  st2.push(93);
  ASSERT_FALSE(st1 != st2);
  st2.push(25);
  ASSERT_TRUE(st1 != st2);
}