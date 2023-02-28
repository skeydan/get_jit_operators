test_that("cpp_jit_get_all_operators_names works", {
  ops <- cpp_jit_get_all_operators_names()
})

test_that("cpp_jit_get_operator_from_name works", {
  op <- cpp_jit_get_operator_from_name("aten::add")
  op
})

test_that("tbd") {


  # auto& ops = getAllOperatorsFor(Symbol::fromQualString("foo::bar"));
  # ASSERT_EQ(ops.size(), 1);
  #
  # auto& op = ops.front();
  # ASSERT_EQ(op->schema().name(), "foo::bar");
  #
  # ASSERT_EQ(op->schema().arguments().size(), 2);
  # ASSERT_EQ(op->schema().arguments()[0].name(), "_0");
  # ASSERT_EQ(op->schema().arguments()[0].type()->kind(), TypeKind::FloatType);
  # ASSERT_EQ(op->schema().arguments()[1].name(), "_1");
  # ASSERT_EQ(op->schema().arguments()[1].type()->kind(), TypeKind::TensorType);
  #
  # ASSERT_EQ(op->schema().returns()[0].type()->kind(), TypeKind::TensorType);
  #
  # Stack stack;
  # push(stack, 2.0f, at::ones(5));
  # op->getOperation()(stack);
  # at::Tensor output;
  # pop(stack, output);
  #
  # ASSERT_TRUE(output.allclose(at::full(5, 3.0f)));
}


