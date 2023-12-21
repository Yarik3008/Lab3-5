#include "MyStack.h"

#include <gtest.h>

TEST(TStack, can_create)
{
	ASSERT_NO_THROW(TStack<int> s1(10));
}

TEST(TStack, can_get_size)
{
	TStack<int> s1(2);
	ASSERT_EQ(2, s1.GetSize());
}

TEST(TStack, can_get_top)
{
	TStack<int> s1(2);
	ASSERT_EQ(0, s1.GetTop());
}

TEST(TStack, can_push_element)
{
	TStack<int> s1(1);
	ASSERT_NO_THROW(s1.Push(10));
}

TEST(TStack, cant_push_element_when_stack_is_full)
{
	TStack<int> s1(1);
	s1.Push(10);
	ASSERT_ANY_THROW(s1.Push(10));
}

TEST(TStack, can_pop_element)
{
	TStack<int> s1(1);
	s1.Push(10);
	ASSERT_NO_THROW(s1.Get());
}

TEST(TStack, cant_pop_element_when_stack_is_empty)
{
	TStack<int> s1(1);
	ASSERT_ANY_THROW(s1.Get());
}


TEST(TStack, can_get_top_element)
{
	TStack<int> s1(1);
	s1.Push(10);
	ASSERT_EQ(10, s1.TopView());
}

TEST(TStack, can_check_is_empty)
{
	TStack<int> s1(2);
	ASSERT_EQ(true, s1.IsEmpty());
	s1.Push(1);
	ASSERT_EQ(false, s1.IsEmpty());
}

TEST(TStack, can_check_is_full)
{
	TStack<int> s1(1);
	ASSERT_EQ(false, s1.IsFull());
	s1.Push(1);
	ASSERT_EQ(true, s1.IsFull());
}
