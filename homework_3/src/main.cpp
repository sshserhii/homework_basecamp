#include "date.h"
#include <gtest/gtest.h>

TEST(date, initialization){
  string str= "12.11.1997";
  Date date_1(str);
  EXPECT_EQ(12,date_1.getDay());
  EXPECT_EQ(11,date_1.getMonth());
  EXPECT_EQ(1997,date_1.getYear());
}

TEST(date, minus_check){
  string str= "12.11.1997";
  Date date_1(str);
  string str1= "11.12.1996";
  Date date_2(str1);
  Date date_result;
  date_result = date_1 - date_2;
  EXPECT_EQ(1,date_result.getDay());
  EXPECT_EQ(1,date_result.getMonth());
  EXPECT_EQ(1,date_result.getYear());
}
int main(int argc, char *argv[]){

  Date date_1;
  cin>>date_1;
  cout<<date_1;
  Date date_2;
  cin>>date_2;
  cout<<date_2;
  Date result_date;
  result_date = date_1 - date_2;
  
  ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
