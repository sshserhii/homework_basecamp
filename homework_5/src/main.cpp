#include "vintage_port.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(port,init){
  Port p1("Bordo","dry",5);
  ASSERT_STREQ("Bordo",p1.getBrand());
  ASSERT_STREQ("dry",p1.getStyle());
  EXPECT_EQ(5,p1.getBottles());
}
TEST(porn, copy_constructor){
  Port p1("Bordo","dry",5);
  Port p2(p1);
  ASSERT_STREQ("Bordo",p2.getBrand());
  ASSERT_STREQ("dry",p2.getStyle());
  EXPECT_EQ(5,p2.getBottles());
}
TEST(port,Operator){
  Port p1("Bordo","dry",5);
  Port p3("Aouxrea","semi-sweet",3);
  p1=p3;
  ASSERT_STREQ("Aouxrea",p3.getBrand());
  ASSERT_STREQ("semi-sweet",p3.getStyle());
  EXPECT_EQ(3,p3.getBottles());
}
TEST(VintagePort, init){
  VintagePort vp1("Aouxrea",3,"Bordo",2);
  ASSERT_STREQ("Aouxrea",vp1.getBrand());
  ASSERT_STREQ("vintage",vp1.getStyle());
  ASSERT_STREQ("Bordo",vp1.getNickname());
  EXPECT_EQ(3,vp1.getBottles());
  EXPECT_EQ(2,vp1.getYear());
}
int main(int argc, char *argv[]) {
  Port p1("Bordo","dry",5);
  Port p2(p1);
  cout<<p1;
  cout<<p2;
  Port p3("Aouxrea","semi-sweet",3);
  p2=p3;
  cout<<p3;
  p3.Show();
  VintagePort vp1("Aouxrea",3,"Bordo",2);
  cout<<vp1;
  vp1.Show();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
