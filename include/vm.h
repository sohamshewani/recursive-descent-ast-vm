```cpp
#ifndef VM_H
#define VM_H

#include <vector>
#include <memory>

#include "ast_node.h"

int execute(const std::vector<std::unique_ptr<ASTNode>>& astNodes);

#endif
