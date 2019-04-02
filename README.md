# lighting_cloth_v2
This is the project for lighting cloth for "gokilive" (lighting cloth version2)

衣装：白衣\
ライト：LEDテープ (ws2813b)\
LEDの配置：\
<img width=700 alt="全体図" src="/Users/yusuke/tparty/light_cloth_v2/lighting_cloth_v2/haiti.jpg">

2019/03/20段階での設計\
PC(Openframeworks)から有線で服のArduinoとシリアル通信をする\
このとき、lighting cloth formatにしたがって通信する\
LEDテープは全て直列に繋がっている\
電源は最終的にはモバイルバッテリーとする。とりあえずはACアダプター5V2Aを使用する\
ArduinoはformatにしたがってLEDを光らせる\

## Lighting cloth format
255\
一フレーム目の...
一個目のLEDのr 一個目のLEDのg 一個目のLEDのb 二個目のLEDのr 二個目のLEDのg 二個目のLEDのb .... 最後のLEDのr 最後のLEDのg 最後のLEDのb\
255\
二フレーム目の...\
...\
255\
(今回はLEDは全部でN個)\
シリアル通信では0~255の値を送ることができるが、0はチェック用に使うのでr,g,b<=254とする

ex)\
255(ここで初期化) 254 1 1 254 1 1 254 1 2 254 1 3 ... 104 104 104\
255(ここで初期化) 254 1 1 254 14 14 254 15 15 ...\
255(ここで初期化) ...\
...




