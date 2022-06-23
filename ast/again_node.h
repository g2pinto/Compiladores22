#ifndef __L22_AST_AGAIN_NODE_H__
#define __L22_AST_AGAIN_NODE_H__

#include <cdk/ast/basic_node.h>

namespace l22 {

  /**
   * Class for describing again instruction nodes.
   */
  class again_node: public cdk::basic_node {
      int _lvl;

  public:
    inline again_node(int lineno, int lvl=1) :
        cdk::basic_node(lineno), _lvl(lvl) {
    }

    public:
    inline int lvl() {
      return _lvl;
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_again_node(this, level);
    }

  };

}

#endif