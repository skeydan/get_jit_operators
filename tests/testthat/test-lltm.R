test_that("rcpp_contrarian works", {
  t <- torch::torch_eye(2)
  expect_equal(as.numeric(rcpp_contrarian(t)$sum()), -2)
})
