#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Counter
PASSED=0
FAILED=0

# Function to run a test
run_test() {
	local test_name="$1"
	local args="$2"
	local should_fail="$3"
	
	echo -e "${YELLOW}Testing: $test_name${NC}"
	echo "Command: ./PmergeMe $args"
	
	output=$(./PmergeMe $args 2>&1)
	exit_code=$?
	
	if [ "$should_fail" = "true" ]; then
		# Check if output contains error-related keywords
		if echo "$output" | grep -q "Error\|Invalid\|error\|Usage"; then
			echo -e "${GREEN}✓ PASSED (correctly failed)${NC}"
			((PASSED++))
		else
			echo -e "${RED}✗ FAILED (should have failed but didn't)${NC}"
			echo "Output: $output"
			((FAILED++))
		fi
	else
		if [ $exit_code -eq 0 ]; then
			echo -e "${GREEN}✓ PASSED${NC}"
			echo "$output" | head -3
			((PASSED++))
		else
			echo -e "${RED}✗ FAILED${NC}"
			echo "Output: $output"
			((FAILED++))
		fi
	fi
	echo ""
}

# Build first
echo -e "${YELLOW}Building...${NC}"
make clean > /dev/null 2>&1
make > /dev/null 2>&1
if [ ! -f "./PmergeMe" ]; then
	echo -e "${RED}Build failed!${NC}"
	exit 1
fi
echo -e "${GREEN}Build successful${NC}\n"

# Test cases
echo -e "${YELLOW}=== EDGE CASES ===${NC}\n"

# Single number
run_test "Single number" "42" "false"

# Two numbers
run_test "Two numbers (sorted)" "1 2" "false"
run_test "Two numbers (unsorted)" "2 1" "false"

# Three numbers
run_test "Three numbers" "3 1 2" "false"

# Duplicates
run_test "Duplicates" "5 5 5 5" "false"
run_test "Mixed with duplicates" "3 1 3 2 1" "false"

# Already sorted
run_test "Already sorted" "1 2 3 4 5" "false"

# Reverse sorted
run_test "Reverse sorted" "5 4 3 2 1" "false"

# Large number of elements
run_test "100 random numbers" "$(for i in {1..100}; do echo $((RANDOM % 1000)); done | tr '\n' ' ')" "false"

# Stress test with 3000 random numbers
run_test "3000 random numbers (1-1000)" "$(shuf -i 1-1000 -n 3000 | tr '\n' ' ')" "false"

# Error cases
echo -e "${YELLOW}=== ERROR CASES ===${NC}\n"

# Negative number
run_test "Negative number" "-5 3 1" "true"

# Non-numeric input
run_test "Non-numeric input" "abc 123" "true"

# Floating point
run_test "Floating point" "1.5 2.3 1.1" "true"

# Mixed valid and invalid
run_test "Mixed valid and invalid" "123 abc 456" "true"

# Empty input
run_test "No arguments" "" "true"

# Special cases
echo -e "${YELLOW}=== SPECIAL CASES ===${NC}\n"

# Zero
run_test "Zero value" "0 1 2" "false"

# Large numbers
run_test "Large numbers" "1000000 999999 1000001" "false"

# All zeros
run_test "All zeros" "0 0 0 0" "false"

# One number repeated many times
run_test "42 repeated" "42 42 42 42 42 42 42 42 42 42" "false"

# Summary
echo -e "${YELLOW}=== TEST SUMMARY ===${NC}"
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"
TOTAL=$((PASSED + FAILED))
echo "Total: $TOTAL"

if [ $FAILED -eq 0 ]; then
	echo -e "${GREEN}All tests passed!${NC}"
	exit 0
else
	echo -e "${RED}Some tests failed!${NC}"
	exit 1
fi
