# 資料スライド

1. 題名,グループ名,メンバー
2. システム概要
3. ニーズ
4. 使った知識
5. 使い方
6. 実演
7. 感想

## 実演動画



実際に使ってみます

まず,木の場合の入力をしてみます.

16個の頂点があって,

頂点12と1,3と1,4と16などと言ったものが隣あっているときのグラフです.

どのようなグラフなのでしょうか.

16
12 1
3 1
4 16
7 12
6 2
2 15
5 16
14 16
10 11
3 10
3 13
8 6
16 8
9 12
4 3

./a.out > o1

実行結果を貼り付けて…

このようなグラフになるようです.

次は,頂点同士の繋がりが行列で与えられている場合を見てみます

この01は,1のところは辺が有ることを示しています.

1行目,2列が1であることは,頂点1と2が辺で繋がれていることを示しています.

```in
6
010110
101001
010100
101000
100000
010000
```

./a.out 0 1 1 > o1

今回は,無向グラフで,辺関係が行列であることを示すために,2つ目の引数を1,3つ目を1に設定しています.

実行結果を貼り付けて…グラフが可視化できました



無向グラフを根付きグラフにしたり,

根を指定した頂点に設定する.

連結でないグラフを表示する.

重み付きグラフを可視化する.などと言ったことも出来ます.

一番の長所は,根を指定した頂点にしてくれることだと感じています.



見ないで
