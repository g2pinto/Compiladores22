#ifndef __L22_AST_PROGRAM_NODE_H__
#define __L22_AST_PROGRAM_NODE_H__

#include <cdk/ast/basic_node.h>

namespace l22 {

  /**
   * Class for describing program nodes.
   */
  class program_node: public cdk::basic_node {
    cdk::basic_node *_statements;

  public:
    inline program_node(int lineno, cdk::basic_node *statements) :
        cdk::basic_node(lineno), _statements(statements) {
          std::cout << "new program\n";
          std::cout << "\n\n\n";
          std::cout << statements->label() << "\n\n";
    }

  public:
    inline cdk::basic_node *statements() {
      std::cout << _statements->label() << "\n\n";
      return _statements;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_program_node(this, level);
    }

  };

} // l22

#endif
