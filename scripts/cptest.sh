#!/bin/bash

set -euo pipefail

workspace="$1"
dirname="$2"
filename="$3"

exe_script="$dirname/out/$filename"

# コンテストにアクセスするためのデータを成形
lastdir="$(basename "$dirname")"
contest="${lastdir,,}"
question="${filename,,}"

echo "$lastdir-$filename will be execution!"

if [ ! -d "$dirname/test/$filename" ]; then
  # テストデータがない場合は取得
  url=https://atcoder.jp/contests/$contest/tasks/${contest}_$question
  if [[ "$(head "$dirname/$filename.cpp" -n 1)" =~ ^.*(http.*)$ ]]; then
    # ファイル先頭にURLが定義されているときは使用する
    url=${BASH_REMATCH[1]}
  fi
  oj dl -d "$dirname/test/$filename" "$url"
fi

# コンパイルの実行
mkdir -p "$dirname/out"
g++-15 "$dirname/$filename.cpp" -o "$dirname/out/$filename" -std=gnu++23 -O2 -Wall -Wextra -DONLINE_JUDGE -DATCODER -I "$workspace/include"

# テスト実行
oj test -c "$exe_script" -d "$dirname/test/$filename"
