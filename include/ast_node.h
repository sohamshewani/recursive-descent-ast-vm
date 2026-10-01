```cpp
#ifndef AST_NODE_H
#define AST_NODE_H

#include <iostream>
#include <string>
#include <memory>

enum class NodeType {
    NUMBER,
    BINARY,
    UNARY
};

class ASTNode {
public:
    ASTNode(NodeType type) : type_(type) {}
    virtual ~ASTNode() {}

    NodeType getType() const { return type_; }

    virtual void accept(std::ostream& os) const = 0;

protected:
    NodeType type_;
};

class NumberNode : public ASTNode {
public:
    NumberNode(double value) : ASTNode(NodeType::NUMBER), value_(value) {}

    void accept(std::ostream& os) const override {
        os << value_;
    }

private:
    double value_;
};

class BinaryNode : public ASTNode {
public:
    BinaryNode(NodeType type, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : ASTNode(type), left_(std::move(left)), right_(std::move(right)) {}

    std::unique_ptr<ASTNode> getLeft() const { return left_; }
    std::unique_ptr<ASTNode> getRight() const { return right_; }

    void accept(std::ostream& os) const override {
        os << "(";
        getLeft()->accept(os);
        os << " ";
        os << getOperator();
        os << " ";
        getRight()->accept(os);
        os << ")";
    }

private:
    std::unique_ptr<ASTNode> left_;
    std::unique_ptr<ASTNode> right_;
    virtual std::string getOperator() const = 0;
};

class UnaryNode : public ASTNode {
public:
    UnaryNode(NodeType type, std::unique_ptr<ASTNode> operand) : ASTNode(type), operand_(std::move(operand)) {}

    std::unique_ptr<ASTNode> getOperand() const { return operand_; }

    void accept(std::ostream& os) const override {
        os << "(";
        os << getOperator();
        os << " ";
        getOperand()->accept(os);
        os << ")";
    }

private:
    std::unique_ptr<ASTNode> operand_;
    virtual std::string getOperator() const = 0;
};

#endif
