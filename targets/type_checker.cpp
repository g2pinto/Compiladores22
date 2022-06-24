#include <string>
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated
#include <cdk/types/primitive_type.h>

#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }

//---------------------------------------------------------------------------

void l22::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
    for (size_t i = 0; i < node->size(); i++){
      node->node(i)->accept(this, lvl + 2);
    }
}

//---------------------------------------------------------------------------

void l22::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void l22::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

void l22::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong type in unary logical expression");
  }
}
void l22::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void l22::type_checker::do_address_of_node(l22::address_of_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  node->type(cdk::reference_type::create(4, node->argument()->type()));
}
void l22::type_checker::do_size_of_node(l22::size_of_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->statement()->accept(this, lvl + 2);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}
void l22::type_checker::do_return_node(l22::return_node *const node, int lvl) {
  std::cout << "type_return_1\n";
  node->retval()->accept(this, lvl);
  std::cout << "type_return_2\n";
  // EMPTY TODO
}
void l22::type_checker::do_block_node(l22::block_node *const node, int lvl) {
  std::cout << "ola\n";
  if (node->declarations()){
    node->declarations()->accept(this, lvl + 2);
  }
  if (node->instructions()){
    node->instructions()->accept(this, lvl + 2);
  }
  std::cout << "ola2\n";

}
void l22::type_checker::do_stop_node(l22::stop_node *const node, int lvl) {
  // EMPTY (anything here?)
}
void l22::type_checker::do_again_node(l22::again_node *const node, int lvl) {
  // EMPTY  (anything here?)
}
void l22::type_checker::do_write_node(l22::write_node *const node, int lvl) {
  
  std::cout << "ola3\n";

  node->argument()->accept(this, lvl + 2);

  for (size_t i = 0; i < node->argument()->size(); i++)
  {
    auto type = dynamic_cast<cdk::expression_node *>(node->argument()->node(i))->type();
    if (type->name() == cdk::TYPE_POINTER)
      throw std::string("cannot print a pointer!");
  }
  std::cout << "ola4\n";

}


void l22::type_checker::do_variable_declaration_node(l22::variable_declaration_node *const node, int lvl) {
  if (node->initializer() != nullptr) {
    node->initializer()->accept(this, lvl + 2);

    if (node->is_typed(cdk::TYPE_INT)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (node->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT) && !node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (node->is_typed(cdk::TYPE_STRING)) {
      if (!node->initializer()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (node->is_typed(cdk::TYPE_POINTER)) {
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        auto in = (cdk::literal_node<int>*)node->initializer();
        if (in == nullptr || in->value() != 0) throw std::string("wrong type for initializer (pointer expected).");
      }
    } else {
      throw std::string("unknown type for initializer.");
    }
  }
  const std::string &id = node->variableId();

  std::shared_ptr<l22::symbol> symbol = std::make_shared<l22::symbol>(node->type(), id, true, node->qualifier());
  if (_symtab.insert(id, symbol)) {
    _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
  } else {
    throw std::string("variable '" + id + "' redeclared");
  }
}

void l22::type_checker::do_function_declaration_node(l22::function_declaration_node *const node, int lvl) {
  // EMPTY
}

void l22::type_checker::do_function_call_node(l22::function_call_node *const node, int lvl) {
  ASSERT_UNSPEC;

  auto function = ((l22::fundef_expression_node*)node->function());
  node->type(function->type());

  if (node->arguments()->size() == function->number_of_arguments())
  {
    node->arguments()->accept(this, lvl + 4);
    for (size_t ax = 0; ax < node->arguments()->size(); ax++)
    {
      if (node->argument(ax)->type() == function->argument(ax)->type())
        continue;
      //if (node->argument(ax)->is_typed(cdk::TYPE_DOUBLE) && node->argument(ax)->is_typed(cdk::TYPE_INT))
      //  continue;
      throw std::string("type mismatch for argument " + std::to_string(ax + 1));
    }
  }
  else
  {
    throw std::string(
        "number of arguments in call (" + std::to_string(node->arguments()->size()) + ") must match declaration.");
  } 
}
void l22::type_checker::do_stack_alloc_node(l22::stack_alloc_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);

  if (!node->argument()->is_typed(cdk::TYPE_INT))
  {
    throw std::string("Wrong type.");
  }

  node->type(cdk::reference_type::create(4, cdk::primitive_type::create(0, cdk::TYPE_UNSPEC)));
}
void l22::type_checker::do_identity_node(l22::identity_node *const node, int lvl) {
  // EMPTY
}
void l22::type_checker::do_fundef_expression_node(l22::fundef_expression_node *const node, int lvl) {
  //if (node->identifier() == "fir")
  //  node->identifier("_main");
  //else if (node->identifier() == "_main")
    //node->identifier("._main");
/*
  std::shared_ptr<fir::symbol> symbol = std::make_shared<fir::symbol>(node->type(), node->identifier(), true, node->qualifier());

  auto existent_symbol = _symtab.find(node->identifier());

  if (existent_symbol == nullptr)
  {
    _symtab.insert(node->identifier(), symbol);
    _parent->set_new_symbol(symbol);
    return;
  }                                                                 TODO

  if (node->returnVal())
    node->returnVal()->accept(this, lvl);

  //IF already exists
  if (node->arguments()->size() == existent_symbol->params()->size())
  {
    for (size_t i = 0; i < node->arguments()->size(); i++)
    {
      cdk::typed_node *newArgument = (cdk::typed_node *)node->arguments()->node(i);
      if (newArgument->type()->name() != existent_symbol->params()->at(i)->type()->name())
        throw std::string("declarations are not the same");
    }
    _symtab.replace(node->identifier(), symbol);
    _parent->set_new_symbol(symbol);
  }
  else
    throw std::string("declarations are not the same"); */
}

void l22::type_checker::do_index_node(l22::index_node *const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

void l22::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  std::cout << "type_int_1\n";
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  std::cout << "type_int_1\n";
}

void l22::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  std::cout << "type_string_1\n";
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
  std::cout << "type_string_2\n";
}

void l22::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}
void l22::type_checker::do_null_pointer_node(l22::null_pointer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::reference_type::create(4, cdk::primitive_type::create(0, cdk::TYPE_VOID)));
}

//---------------------------------------------------------------------------

void l22::type_checker::processUnaryExpression(cdk::unary_operation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in argument of unary expression");

  // in Simple, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_neg_node(cdk::neg_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void l22::type_checker::processBinaryExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in left argument of binary expression");

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in right argument of binary expression");

  // in Simple, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void l22::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  std::shared_ptr<l22::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr) {
    node->type(symbol->type());
  } else {
    throw id;
  }
}

void l22::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void l22::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;

  node->lvalue()->accept(this, lvl);
  if (!node->lvalue()->is_typed(cdk::TYPE_INT))
    throw std::string("wrong type in left argument of assignment expression");

  node->rvalue()->accept(this, lvl + 2);
  if (!node->rvalue()->is_typed(cdk::TYPE_INT))
    throw std::string("wrong type in right argument of assignment expression");

  if (!node->lvalue()->is_typed(cdk::TYPE_INT) || !node->rvalue()->is_typed(cdk::TYPE_INT))
    throw std::string("Invalid types in and");
  else
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------

void l22::type_checker::do_program_node(l22::program_node *const node, int lvl) {
  std::cout << "type_program_1\n";
  node->statements()->accept(this, lvl +2);
  std::cout << "type_program_2\n";
}

void l22::type_checker::do_evaluation_node(l22::evaluation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_read_node(l22::read_node *const node, int lvl) {
  try {
    node->argument()->accept(this, lvl);
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

//---------------------------------------------------------------------------

void l22::type_checker::do_while_node(l22::while_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_if_node(l22::if_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

void l22::type_checker::do_if_else_node(l22::if_else_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}
