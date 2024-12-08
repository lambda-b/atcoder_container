#!/bin/bash

workspace=$1
dirname=$2
filename=$3

# コマンドを確認して存在しない場合インストール
if !(type "oj" > /dev/null 2>&1); then
  pip install --upgrade pip
  pip install online-judge-tools
  pip install setuptools
  pip install selenium
fi

# 作成コードをコンパイル & 実行スクリプト
compile_script="g++-12 $dirname/$filename.cpp -o $dirname/out/$filename -std=gnu++20 -I $workspace/include"
exe_script="$dirname/out/$filename"

# コンテストにアクセスするためのデータを成形
lastdir=`basename $dirname`
contest=`v=$lastdir; echo ${v,,}`
question=`v=$filename; echo ${v,,}`

echo "$lastdir-$filename will be execution!"

if [ ! -d "$dirname/test/$filename" ]; then
  # テストデータがない場合は取得
  url=https://atcoder.jp/contests/$contest/tasks/${contest}_$question
  if [[ `head $dirname/$filename.cpp -n 1` =~ ^.*(http.*)$ ]]; then
    # ファイル先頭にURLが定義されているときは使用する
    url=${BASH_REMATCH[1]}
  fi
  oj dl -d $dirname/test/$filename $url
fi

# コンパイルの実行
mkdir -p $dirname/out
g++-12 $dirname/$filename.cpp -o $dirname/out/$filename -std=gnu++20 -I $workspace/include

# テスト実行
oj test -c "$exe_script" -d $dirname/test/$filename
