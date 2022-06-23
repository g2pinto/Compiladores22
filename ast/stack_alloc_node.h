
#ifndef __L22_AST_STACK_ALLOC_NODE_H__
#define __L22_AST_STACK_ALLOC_NODE_H__

#include <cdk/ast/unary_operation_node.h>

namespace l22 {

  /**
   * Class for describing memory allocation nodes.
   */
  class stack_alloc_node: public cdk::unary_operation_node {
      int _size;
  public:
    inline stack_alloc_node(int lineno, cdk::expression_node *argument, int size) :
        cdk::unary_operation_node(lineno, argument), _size(size) {
    }

    public:
    inline int size() {
      return _size;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stack_alloc_node(this, level);
    }

  };

} // fir

#endif