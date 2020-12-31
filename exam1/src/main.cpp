#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "exam.h"

/***
 * -------------------------------------------------------------------------------------------------------------------
 * 题目
 * -------------------------------------------------------------------------------------------------------------------
 * 无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。并将结果按字符串从小到大排序
 * 
 * 示例1:
 * - 输入：S = "qwe"
 * - 输出：["eqw", "ewq", "qew", "qwe", "weq", "wqe"]
 * 
 * 示例2:
 * - 输入：S = "ab"
 * - 输出：["ab", "ba"]
 * 
 * 要求：
 * 1. 仅修改exam.h文件，通过所有单元测试。
 * 2. 输出结果按照字典顺序排序
 * 3. exam.h以外的文件不得修改，修改会被覆盖。
 */
using testing::ElementsAre;

class PrepareTest:public testing::Test {
protected:
    Exam _exam;
};

TEST_F(PrepareTest, test0){
    EXPECT_THAT(_exam.output("qwe"), ElementsAre("eqw", "ewq", "qew", "qwe", "weq", "wqe"));
}

TEST_F(PrepareTest, test1){
    EXPECT_THAT(_exam.output("qw"), ElementsAre("qw", "wq"));
}

TEST_F(PrepareTest, test2){
    EXPECT_THAT(_exam.output("q"), ElementsAre("q"));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}