# AtCoder Rust solutions

AtCoder向けのRust環境と過去問の解答です。全ての解答をルートの単一Cargoパッケージにまとめ、各問題を独立したバイナリとして、元の構成を踏襲した `src/ABC.../A.rs` などに置いています。

## 環境

Dev ContainerではAtCoderのRust環境に合わせたRust 1.89.0と、`rustfmt`、Clippy、`cargo-equip`、`online-judge-tools` を使えます。AtCoder LibraryのRust移植版 `ac-library-rs` と入力用の `proconio` はルートの `Cargo.toml` で管理します。

## 解答の実行

例として ABC372 D は次のように実行します。

```sh
cargo run --release --bin abc372_d
```

新しい問題は `src/ABC488/A.rs` のようにコンテスト別ディレクトリにファイルを作成し、通常のRustプログラムを書きます。Rustファイルを開いた状態で `Ctrl+Shift+B` を押すと、その問題を `out/` にビルドし、AtCoderのサンプルを取得して `oj test` を実行します。取得したサンプルは問題ディレクトリ内の `test/` に保存されます。どちらもGit管理対象外です。

## AtCoder Library

```rust
use ac_library::{Dsu, ModInt998244353, Segtree};
```

提出用に依存クレートを展開する場合は、たとえば次を実行します。

```sh
cargo equip --exclude-atcoder-crates --resolve-cfgs --remove docs --minify libs --rustfmt --check --bin abc372_d
```

## 手動の確認

```sh
cargo fmt --all --check
cargo clippy --all-targets
cargo build --release --bins
```
