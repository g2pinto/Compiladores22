#ifndef __L22_AST_RETURN_NODE_H__
#define __L22_AST_RETURN_NODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/basic_node.h>

namespace l22 {

  /**
   * Class for describing size of nodes.
   */
  class return_node: public cdk::basic_node {
    cdk::expression_node *_retval;

  public:
    inline return_node(int lineno, cdk::expression_node *retval) :
        cdk::basic_node(lineno), _retval(retval) {
          std::cout << "\n\nnew write\n";
          std::cout << retval->label() << "\n\n";
    }

    inline return_node(int lineno) :
      cdk::basic_node(lineno){
    }

  public:
    inline cdk::expression_node *retval() {
      return _retval;
    }


    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }


  };

} // l22

#endif