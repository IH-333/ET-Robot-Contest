#include <stdio.h>

void main(intptr_t unused){
    ev3_sensor_config(EV3_PORT_1, COLOR_SENSOR);  //ポートは1、カラーセンサーを設定
    printf(ev3_color_sensor_get_color(EV3_PORT_1));
}