#ここではベースイメージという、構築する環境の基礎となるイメージをDockerHubなどから選び記述します。
#今回は、Ubuntuイメージを使用します
ARG VARIANT="hirsute"
FROM mcr.microsoft.com/vscode/devcontainers/base:${VARIANT}


#作成する環境の時間設定を日本時間にしておきます。これにより、ビルドが中断されなくなります。
ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# コンパイラのインストール
RUN apt update && apt install -y gcc-12
RUN apt update && apt install -y g++-12

# c++を動かすためのGDBをインストール
RUN apt update && apt install -y gdb

# c++の言語サーバインストール
RUN apt update && apt install -y clangd

# c++のフォーマッタのインストール
RUN apt update && apt install -y clang-format

# 自動テストを行うための依存パッケージをインストール
# この設定の他にpipによるパッケージインストールも必要
RUN apt update && apt install -y time

#日本語化の設定
RUN apt update && apt install -y language-pack-ja  g++
RUN update-locale LANG=ja_JP.UTF-8

ENV LANG="ja_JP.UTF-8" \
    LANGUAGE="ja_JP:ja" \
    LC_ALL="ja_JP.UTF-8" \
    LC_ALL="ja_JP.UTF-8" \
    TZ="JST-9" \
    TERM="xterm"

CMD ["bash"]
