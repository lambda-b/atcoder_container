#!/usr/bin/env bash
set -euo pipefail

workspace="$1"
source_file="$2"
contest_dir="$(basename "$(dirname "$source_file")")"
problem="$(basename "$source_file" .rs)"
contest="${contest_dir,,}"
problem_lower="${problem,,}"
bin_name="${contest//-/_}_${problem_lower}"
test_dir="$(dirname "$source_file")/test/$problem"

"$workspace/scripts/rustbuild.sh" "$workspace" "$source_file"

if [[ ! -d "$test_dir" ]]; then
  url="https://atcoder.jp/contests/$contest/tasks/${contest}_${problem_lower}"
  if [[ "$(head -n 1 "$source_file")" =~ (https?://[^[:space:]]+) ]]; then
    url="${BASH_REMATCH[1]}"
  fi
  oj dl -d "$test_dir" "$url"
fi

oj test -c "$workspace/out/release/$bin_name" -d "$test_dir"
