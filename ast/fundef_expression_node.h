#ifndef __FIR_AST_FUNCTION_DEFINITION_H__
#define __FIR_AST_FUNCTION_DEFINITION_H__


#include <string>
#include <cdk/ast/typed_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>
#include "ast/block_node.h"

namespace l22 {

  /**
   * Class for describing function definition nodes.
   */
  class fundef_expression_node: public cdk::expression_node {
    cdk::sequence_node *_arguments;
    l22::block_node *_block;

  public:
    fundef_expression_node(int lineno, cdk::sequence_node *arguments, l22::block_node *block, std::shared_ptr<cdk::basic_type> returnType) :
        cdk::expression_node(lineno), _arguments(arguments), _block(block) {
      type(returnType);
    }

    fundef_expression_node(int lineno,std::shared_ptr<cdk::basic_type> funType,
                         cdk::sequence_node *arguments, l22::block_node *block, std::shared_ptr<cdk::basic_type> returnType) :
        cdk::expression_node(lineno), _arguments(arguments), _block(block) {
      type(returnType);
    }

  public:
    cdk::sequence_node* arguments() {
      return _arguments;
    }
    cdk::expression_node* argument(size_t ax) {
      return dynamic_cast<cdk::expression_node*>(_arguments->node(ax));
    }
    l22::block_node* block() {
      return _block;
    }
    size_t number_of_arguments(){
      return _arguments->size();
    }


    void accept(basic_ast_visitor *sp, int level) {
      sp->do_fundef_expression_node(this, level);
    }

  };

} // l22

#endif