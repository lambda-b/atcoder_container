ARG VARIANT="jammy"
FROM mcr.microsoft.com/devcontainers/base:${VARIANT}

ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/${TZ} /etc/localtime \
    && echo ${TZ} > /etc/timezone

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    build-essential \
    language-pack-ja \
    python3 \
    python3-pip \
    python3-setuptools \
    pkg-config \
    time \
    && curl -fsSL https://raw.githubusercontent.com/tj/n/master/bin/n -o /tmp/n \
    && install /tmp/n /usr/local/bin/n \
    && n 24.13.0 \
    && hash -r \
    && npm install -g @openai/codex \
    && python3 -m pip install --no-cache-dir --upgrade pip setuptools online-judge-tools \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* /tmp/n

RUN update-locale LANG=ja_JP.UTF-8

ENV LANG="ja_JP.UTF-8" \
    LANGUAGE="ja_JP:ja" \
    LC_ALL="ja_JP.UTF-8" \
    TERM="xterm"

CMD ["bash"]
