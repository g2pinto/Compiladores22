#ifndef __L22_AST_DECLARATION_VARAIABLE_NODE_H__
#define __L22_AST_DECLARATION_VARAIABLE_NODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/typed_node.h>
#include <cdk/types/basic_type.h>

namespace l22 {

  /**
   * Class for describing declaration variable nodes.
   */
  class variable_declaration_node: public cdk::typed_node {
    int _qualifier;
    std::string _variableId;
    cdk::expression_node *_initializer;

    public:
    variable_declaration_node(int lineno, int qualifier, std::shared_ptr<cdk::basic_type> varType, const std::string &variableId,
                              cdk::expression_node *initializer):
        cdk::typed_node(lineno), _qualifier(qualifier), _variableId(variableId), _initializer(initializer) {
          type(varType);
    }
    public:
    
    int qualifier() {
      return _qualifier;
    }
    std::string &variableId() {
      return _variableId;
    }
    cdk::expression_node *initializer() {
      return _initializer;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_declaration_node(this, level);
    }

  };

}
#endif