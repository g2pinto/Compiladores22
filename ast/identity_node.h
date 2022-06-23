#ifndef __L22_AST_IDENTITY_H__
#define __L22_AST_IDENTITY_CALL_H__

#include <cdk/ast/basic_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/nil_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/typed_node.h>
#include <cdk/types/basic_type.h>

namespace l22 {

    /**
     * Class for describing identity nodes.
     */
    class identity_node: public cdk::unary_operation_node {

    public:
      inline identity_node(int lineno, cdk::expression_node *argument) :
          unary_operation_node(lineno, argument) {
      }

      void accept(basic_ast_visitor *sp, int level) {
          sp->do_identity_node(this, level);
      }

    };

} // l22

#endif