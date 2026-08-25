#!/bin/bash
# test.sh - functional tests for ex05 (harl)
# main() has no argv, it hardcodes DEBUG/INFO/WARNING/ERROR/SCREAMING FOR NO REASON,
# so this just builds once and checks every expected line shows up in the output.

cd "$(dirname "$0")/.."

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

PASS=0
FAIL=0

make -s re > /dev/null

output=$(./harl)

check() {
	local desc="$1"
	local expected="$2"

	if echo "$output" | grep -qF "$expected"; then
		echo -e "${GREEN}[PASS]${NC} $desc"
		PASS=$((PASS + 1))
	else
		echo -e "${RED}[FAIL]${NC} $desc"
		echo "  expected to contain: $expected"
		FAIL=$((FAIL + 1))
	fi
}

check "DEBUG level triggered"   "[ DEBUG ]"
check "INFO level triggered"    "[ INFO ]"
check "WARNING level triggered" "[ WARNING ]"
check "ERROR level triggered"   "[ ERROR ]"
check "unknown level fallback"  "[ Probably complaining about insignificant problems ]"

echo
echo "Results: $PASS passed, $FAIL failed"

[ "$FAIL" -eq 0 ]
