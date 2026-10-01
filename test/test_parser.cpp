```cpp
#include <gtest/gtest.h>
#include "parser.h"

TEST(ParserTest, SimpleParse) {
    std::vector<std::unique_ptr<ASTNode>> nodes = parseExpression("1 + 2");
    ASSERT_EQ(nodes.size(), 3);
}

TEST(ParserTest, ComplexParse) {
    std::vector<std::unique_ptr<ASTNode>> nodes = parseExpression("(1 + 2) * 3");
    ASSERT_EQ(nodes.size(), 4);
}
