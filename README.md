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
ArduinoはformatにしたがってLEDを光らせる

## Lighting cloth format
一色目　二色目　モード
## 色
1~100 光の色相(0~360のMap) first_color\
101~200　予約色相\
### key 送る数値 モード
 0 何もない\
z 201　消灯\
x 202　赤色でテスト点灯\
k 203　一色目が走る\
l 204　二色目色が走る\
o 205　一色目ずっと光らせるモード\
p 206　二色目ずっと光らせるモード\