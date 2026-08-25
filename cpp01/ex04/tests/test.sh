#!/bin/bash
# test.sh - functional tests for ex04 (replace)

cd "$(dirname "$0")/.."

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

PASS=0
FAIL=0

make -s re > /dev/null

check_ok() {
	local desc="$1"
	local file="$2"
	local s1="$3"
	local s2="$4"
	local expected_file="$5"

	rm -f "tests/$file.replace"
	if ./replace "tests/$file" "$s1" "$s2" > /dev/null 2>&1 \
		&& diff -q "tests/$file.replace" "$expected_file" > /dev/null 2>&1; then
		echo -e "${GREEN}[PASS]${NC} $desc"
		PASS=$((PASS + 1))
	else
		echo -e "${RED}[FAIL]${NC} $desc"
		FAIL=$((FAIL + 1))
	fi
}

check_fail() {
	local desc="$1"
	shift
	if ! ./replace "$@" > /dev/null 2>&1; then
		echo -e "${GREEN}[PASS]${NC} $desc"
		PASS=$((PASS + 1))
	else
		echo -e "${RED}[FAIL]${NC} $desc"
		FAIL=$((FAIL + 1))
	fi
}

expected=$(mktemp)
printf 'bonjour un monde\nun chat mange un poisson\nun chien aime un chat\n' > "$expected"
check_ok "replaces every occurrence of s1" basic.txt "le" "un" "$expected"
rm -f "$expected"

expected=$(mktemp)
cp tests/none.txt "$expected"
check_ok "leaves content untouched when s1 absent" none.txt "zzz" "yyy" "$expected"
rm -f "$expected"

expected=$(mktemp)
: > "$expected"
check_ok "handles an empty file" empty.txt "foo" "bar" "$expected"
rm -f "$expected"

expected=$(mktemp)
printf 'bb\nababab\n' > "$expected"
check_ok "consumes matched chars without overlapping re-matches" overlap.txt "aa" "b" "$expected"
rm -f "$expected"

expected=$(mktemp)
printf 'fXXr' > "$expected"
check_ok "matches a pattern spanning two lines (real newline)" span.txt $'oo\nba' "XX" "$expected"
rm -f "$expected"

check_fail "wrong argument count is rejected" "tests/basic.txt" "le"
check_fail "missing file is rejected" "tests/does_not_exist.txt" "le" "un"

rm -f tests/*.replace

echo
echo "Results: $PASS passed, $FAIL failed"

[ "$FAIL" -eq 0 ]
