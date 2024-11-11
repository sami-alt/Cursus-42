# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 07:25:35 by nlouis            #+#    #+#              #
#    Updated: 2024/11/02 14:37:24 by nlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

# Library name
NAME 	= libft.a

# Directory for test executables
TEST_BIN_DIR	= bin

# Test source files (must start with 'test_')
TEST_SRCS	= $(wildcard test*.c)

# Test executables (output binaries in TEST_BIN_DIR)
TEST_EXEC	= $(TEST_SRCS:%.c=$(TEST_BIN_DIR)/%)

# **************************************************************************** #
#                                   TEST RULES                                 #
# **************************************************************************** #

# Test target: Compiles all tests and runs them, reporting passed and failed counts
test: $(TEST_EXEC)
	@echo "\033[0;32m✅ All tests compiled successfully. Running tests...\033[0m"
	@passed=0; failed=0; \
	for exec in $(TEST_EXEC); do \
		if ./$$exec; then \
			passed=$$((passed + 1)); \
			echo "\033[0;32m[PASS]\033[0m $$exec"; \
		else \
			failed=$$((failed + 1)); \
			echo "\033[0;31m[FAIL]\033[0m $$exec"; \
		fi; \
	done; \
	echo "\n\033[0;32mPassed: $$passed\033[0m"; \
	echo "\033[0;31mFailed: $$failed\033[0m"; \
	if [ $$failed -gt 0 ]; then exit 1; else exit 0; fi

# Rule to compile each test executable
$(TEST_BIN_DIR)/%: %.c $(NAME)
	@mkdir -p $(TEST_BIN_DIR)
	@echo "\033[0;33mCompiling test $<...\033[0m"
	@gcc -Wall -Wextra -Werror -I . $< -L. -lft -o $@

# Clean test executables
clean_tests:
	@echo "\033[0;33m🧹 Cleaning test executables...\033[0m"
	@rm -rf $(TEST_BIN_DIR)

# Rebuild tests (clean and compile again)
re_tests: clean_tests test

# **************************************************************************** #
#                                   PHONY                                      #
# **************************************************************************** #

.PHONY: test clean_tests re_tests

# **************************************************************************** #
#                                 END OF FILE                                  #
# **************************************************************************** #
