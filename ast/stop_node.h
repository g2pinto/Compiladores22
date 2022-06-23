#ifndef __L22_AST_STOP_NODE_H__
#define __L22_AST_STOP_NODE_H__

#include <cdk/ast/basic_node.h>

namespace l22 {

  /**
   * Class for describing stop instruction nodes.
   */
  class stop_node: public cdk::basic_node {
      int _lvl;

  public:
    inline stop_node(int lineno, int lvl=1) :
        cdk::basic_node(lineno), _lvl(lvl) {
    }

    public:
    inline int lvl() {
      return _lvl;
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stop_node(this, level);
    }

  };

}

#endif