#!/bin/bash
set -euo pipefail

failed=0

for cpp in cpp*; do
  [ -d "$cpp" ] || continue

  for ex in "$cpp"/ex*; do
    [ -d "$ex" ] || continue

    if [ -f "$ex/Makefile" ]; then
      echo "→ make in $ex"
      if ! (cd "$ex" && make); then
        echo "✗ FAILED: $ex"
        failed=1
      fi
    fi
  done
done

exit "$failed"