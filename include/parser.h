```cpp
#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <memory>
#include <string>

#include "ast_node.h"

std::vector<std::unique_ptr<ASTNode>> parseExpression(const std::string& input);

#endif
