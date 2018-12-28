#include <iostream>
#include "string_m.h"
#include <gtest/gtest.h>
//test for functions append,length,get_buffer and String(const char*) constructor
TEST(String_append_lenght_and_constructor_test,two_strings){
  String s1("sergiy");
  String s2("shlapak");
  ASSERT_STREQ("sergiy",s1.get_buffer());
  ASSERT_STREQ("shlapak",s2.get_buffer());
  s1.append(s2);
  EXPECT_EQ(13,s1.length());
  ASSERT_STREQ("sergiyshlapak",s1.get_buffer());
}
//test for insert string function
TEST(String_insert_test,two_strings){
  String s1("Hello");
  String s2("World");
  s1.insert(s2,0);
  ASSERT_STREQ("WorldHello",s1.get_buffer());
}
//test for insert char function
TEST(String_insert_char_test,char_string){
  String s1("Hello");
  s1.insert('W',0);
  ASSERT_STREQ("WHello",s1.get_buffer());
}
//test for swap function
TEST(String_swap_test,two_strings){
  String s1("Hello");
  String s2("World");
  s1.swap(s2);
}
//test for resize function
TEST(String_resize_test,string_and_size){
  String s1("Hello World");
  s1.resize(5);
  EXPECT_EQ(5,s1.length());
  ASSERT_STREQ("Hello",s1.get_buffer());
}
//test for substr
TEST(String_substr_test,string){
  String s1("Hello World");
  String s2("World");
  int result = s1.substr(s2);
  EXPECT_EQ(6,result);
}
//test for clear and compare functions
TEST(String_compare_clear,STRING){
  String s1("Hello World");
  String s2("World");
  if(s1.compare(s2)){
    s2.clear();
  }
  EXPECT_EQ(0,s2.length());
}


int main(int argc, char *argv[]) {
    cout<<"some other examples"<<endl;
    String s1("Just common-or-garden string");
    String s2("hello");
    String s3;
    cout<<s1;
    cin>>s3;
    cout<<s3;
    s3=s2;
    cout<<s3;
    s3+=s1;
    cout<<s3;
    ::testing::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
}
