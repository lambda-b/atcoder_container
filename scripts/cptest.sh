#!/bin/bash

workspace=$1
dirname=$2
filename=$3

# 作成コードをコンパイル & 実行スクリプト
compile_script="g++ $dirname/$filename.cpp -o $dirname/out/$filename -std=c++17 -I $workspace/include"
exe_script="$dirname/out/$filename"

# コンテストにアクセスするためのデータを成形
lastdir=`basename $dirname`
contest=`v=$lastdir; echo ${v,,}`
question=`v=$filename; echo ${v,,}`

echo "$lastdir-$filename will be execution!"

if [ ! -d "$workspace/test/$lastdir/$filename" ]; then
  # テストデータがない場合は取得
  oj dl -d test/$lastdir/$filename https://atcoder.jp/contests/$contest/tasks/${contest}_$question
fi

# コンパイルの実行
mkdir -p $dirname/out
g++ $dirname/$filename.cpp -o $dirname/out/$filename -std=c++17 -I $workspace/include

# テスト実行
oj test -c "$exe_script" -d test/$lastdir/$filename
