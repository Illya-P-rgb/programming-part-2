add_test([=[ShoppingListTest.AddRemoveCount]=]  /home/ilya/programming-part-2/variant15/build/my_tests [==[--gtest_filter=ShoppingListTest.AddRemoveCount]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ShoppingListTest.AddRemoveCount]=]  PROPERTIES WORKING_DIRECTORY /home/ilya/programming-part-2/variant15/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  my_tests_TESTS ShoppingListTest.AddRemoveCount)
