#ここではベースイメージという、構築する環境の基礎となるイメージをDockerHubなどから選び記述します。
#今回は、Ubuntuイメージを使用します
ARG VARIANT="jammy"
FROM mcr.microsoft.com/devcontainers/base:${VARIANT}

#作成する環境の時間設定を日本時間にしておきます。これにより、ビルドが中断されなくなります。
ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# C++23 / debug / format / test tools
RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    gnupg \
    && curl -fsSL "https://keyserver.ubuntu.com/pks/lookup?op=get&search=0xC8EC952E2A0E1FBDC5090F6A2C277A0A352154E5" \
        | gpg --dearmor -o /usr/share/keyrings/ubuntu-toolchain-r-test.gpg \
    && echo "deb [signed-by=/usr/share/keyrings/ubuntu-toolchain-r-test.gpg] https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu jammy main" \
        > /etc/apt/sources.list.d/ubuntu-toolchain-r-test.list \
    && curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key \
        | gpg --dearmor -o /usr/share/keyrings/apt.llvm.org.gpg \
    && echo "deb [signed-by=/usr/share/keyrings/apt.llvm.org.gpg] http://apt.llvm.org/jammy/ llvm-toolchain-jammy-21 main" \
        > /etc/apt/sources.list.d/apt.llvm.org.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
    clang-format-21 \
    clangd-21 \
    g++-15 \
    gcc-15 \
    gdb \
    language-pack-ja \
    python3 \
    python3-pip \
    python3-setuptools \
    time \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN update-locale LANG=ja_JP.UTF-8

ENV LANG="ja_JP.UTF-8" \
    LANGUAGE="ja_JP:ja" \
    LC_ALL="ja_JP.UTF-8" \
    TZ="Asia/Tokyo" \
    TERM="xterm"

# Node.js のセットアップ (n 経由でインストール)
# nodejs/npm は n を入れるためだけに使い、インストール後に削除する
RUN apt-get update && apt-get install -y --no-install-recommends nodejs npm \
    && npm install -g n \
    && n 24.13.0 \
    && apt-get purge -y nodejs npm \
    && apt-get autoremove -y \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN npm install -g @openai/codex

RUN python3 -m pip install --no-cache-dir --upgrade pip setuptools online-judge-tools

CMD ["bash"]
