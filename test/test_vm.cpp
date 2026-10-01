```cpp
#include <gtest/gtest.h>
#include "vm.h"
#include "ast_node.h"

TEST(VmTest, SimpleExecution) {
    std::vector<std::unique_ptr<ASTNode>> nodes = {
        std::make_unique<NumberNode>(1.0),
        std::make_unique<UnaryNode>(UnaryNode::NodeType::NEGATE, std::make_unique<NumberNode>(2.0))
    };
    int result = execute(nodes);
    ASSERT_EQ(result, -1);
}

TEST(VmTest, ComplexExecution) {
    std::vector<std::unique_ptr<ASTNode>> nodes = {
        std::make_unique<NumberNode>(1.0),
        std::make_unique<BinaryNode>(BinaryNode::NodeType::ADD, std::make_unique<NumberNode>(2.0), std::make_unique<NumberNode>(3.0))
    };
    int result = execute(nodes);
    ASSERT_EQ(result, 6);
}
