#!/usr/bin/env bash
set -euo pipefail

workspace="$1"
source_file="$2"
contest_dir="$(basename "$(dirname "$source_file")")"
problem="$(basename "$source_file" .rs)"
bin_name="${contest_dir,,}_${problem,,}"
bin_name="${bin_name//-/_}"

cargo build --release --target-dir "$workspace/out" --bin "$bin_name" --manifest-path "$workspace/Cargo.toml"
