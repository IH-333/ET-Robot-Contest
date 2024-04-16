/* メインの起動タスクがセンサーやモーターを設定し、ライントレースを開始 */

/* ヘッダーファイル app.h を含めるための命令 */
/* 標準入出力用のヘッダーファイル <stdio.h> を含めるための命令 */
#include "app.h"
#include <stdio.h>

/* メインタスク(起動時にのみ関数コールされる) */
    /* main_task 関数の定義 */
    /* メインの起動タスクを表す */
    /* unused は未使用の引数を表すための変数 */
    void main_task(intptr_t unused) {

        /* センサー入力ポートの設定 */
        /* 各センサーのポートを指定して設定 */
        ev3_sensor_config(touch_sensor ,TOUCH_SENSOR);
        ev3_sensor_config(color_sensor ,COLOR_SENSOR);
        ev3_sensor_config(sonar_sensor ,ULTRASONIC_SENSOR);
        ev3_sensor_config(gyro_sensor  ,GYRO_SENSOR);
        
        /* モーター出力ポートの設定 */
        /* 各モーターのポートと種類を指定して設定 */
        ev3_motor_config(arm_motor     ,LARGE_MOTOR);
        ev3_motor_config(left_motor    ,MEDIUM_MOTOR);
        ev3_motor_config(right_motor   ,MEDIUM_MOTOR);
        
        /* ライントレースを開始したことを示すメッセージをコンソールに出力 */
        printf("Start Line Trace!!\n");
        
        /* ライントレースタスクの起動 */
        /* 周期タスク LINE_TRACER_TASK_CYC を起動 */
        /* ライントレースタスクが定期的に実行 */
        sta_cyc(LINE_TRACER_TASK_CYC);

        /* タスク終了 */
        ext_tsk();
    }
