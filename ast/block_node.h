#ifndef __L22_AST_BLOCK_NODE_H__
#define __L22_AST_BLOCK_NODE_H__

#include <cdk/ast/basic_node.h>

namespace l22 {

  /**
   * Class for describing block nodes.
   */
  class block_node: public cdk::basic_node {
    cdk::basic_node *_declarations, *_instructions;

  public:
    inline block_node(int lineno, cdk::basic_node *declarations, cdk::basic_node *instructions) :
        cdk::basic_node(lineno), _declarations(declarations), _instructions(instructions) {
          std::cout << "new block\n";
          //std::cout << declarations->label() <<"\n";
          //std::cout << instructions->label() <<"\n";
    }

  public:
    inline cdk::basic_node *declarations() {
      return _declarations;
    }
    inline cdk::basic_node *instructions() {
      return _instructions;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_block_node(this, level);
    }

  };

} // l22

#endif