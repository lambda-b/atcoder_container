#!/usr/bin/env bash
set -euo pipefail

workspace="$1"
source_file="$2"
contest_dir="$(basename "$(dirname "$source_file")")"
problem="$(basename "$source_file" .rs)"
bin_name="${contest_dir,,}_${problem,,}"
bin_name="${bin_name//-/_}"
output_dir="$(dirname "$source_file")/out"
build_dir="$output_dir/.cargo-target"

cargo build --release --target-dir "$build_dir" --bin "$bin_name" --manifest-path "$workspace/Cargo.toml"
cp "$build_dir/release/$bin_name" "$output_dir/$problem"
