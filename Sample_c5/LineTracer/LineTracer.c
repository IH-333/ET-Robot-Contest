/* ヘッダーファイルのインクルード */
    /* app.h と LineTracer.h をインクルード */
    /* 必要な関数や定数を利用できるようにしている */
    #include "app.h"
    #include "LineTracer.h"
    
    /* stdio.h は、標準入出力関連の機能を利用するためのもの */
    #include <stdio.h>

/* 関数プロトタイプ宣言 */
    /* 静的な関数のプロトタイプ宣言 */
    /* steering_amount_calculation 関数と motor_drive_control 関数のプロトタイプを宣言 */
    static int16_t steering_amount_calculation(void);
    static void motor_drive_control(int16_t);

/* ライントレースタスク(100msec周期で関数コールされる) */
    /* tracer_task 関数の定義 */
    /* 周期的に実行されるタスク */
    /* ライントレースを行う */
    void tracer_task(intptr_t unused) {

        /* int16_t 型の変数 steering_amount を宣言 */
        /* ステアリング操舵量の計算 */
        int16_t steering_amount;
        
        /* steering_amount_calculation 関数の呼び出し */
        /* ステアリング操舵量の計算 */
        /* steering_amount に代入 */
        steering_amount = steering_amount_calculation();

        /* motor_drive_control 関数の呼び出し */
        /* 走行モータ制御 */
        /* 計算されたステアリング操舵量に基づいてモーターの制御 */
        motor_drive_control(steering_amount);

        /* タスク終了 */
        ext_tsk();
    }

/* ステアリング操舵量の計算 */
    /* steering_amount_calculation 関数の定義 */
    /* ステアリング操舵量を計算するための関数 */
    static int16_t steering_amount_calculation(void){

        /* 変数の宣言 */
        /* 目標輝度値・差分値・ステアリング操舵量・カラーセンサの値を格納するための変数を宣言 */
        uint16_t  target_brightness; /* 目標輝度値 */
        float32_t diff_brightness;   /* 目標輝度との差分値 */
        int16_t   steering_amount;   /* ステアリング操舵量 */
        rgb_raw_t rgb_val;           /* カラーセンサ取得値 */

        /* 目標輝度値の計算 */
        /* カラーセンサーから読み取った白と黒の輝度の平均値を目標輝度値として設定 */
        target_brightness = (WHITE_BRIGHTNESS - BLACK_BRIGHTNESS) / 2;

        /* カラーセンサ値の取得 */
        /* カラーセンサーからRGB値を取得 */
        /* この値を使って実際の輝度値を計算 */
        ev3_color_sensor_get_rgb_raw(color_sensor, &rgb_val);

        /* 目標輝度値とカラーセンサ値の差分を計算 */
        diff_brightness = (float32_t)(target_brightness - rgb_val.g);

        /* ステアリング操舵量を計算 */
        /* 差分値にステアリングの係数を乗算して、ステアリング操舵量を求める */
        steering_amount = (int16_t)(diff_brightness * STEERING_COEF);

        /* 計算されたステアリング操舵量を返す */
        return steering_amount;
    }

/* 走行モータ制御 */
    /* motor_drive_control 関数の定義 */
    /* モーターの制御を行う関数 */
    static void motor_drive_control(int16_t steering_amount){

        /* 左右のモーターのパワーを格納する変数を宣言 */
        /* 左右モータ設定パワー */
        int left_motor_power, right_motor_power; 

        /* 左右モータ駆動パワーの計算(走行エッジを右にする場合はRIGHT_EDGEに書き換えること) */
        /* ステアリング操舵量に応じて、左右のモーターの速度を調整 */
        left_motor_power  = (int)(BASE_SPEED + (steering_amount * LEFT_EDGE));
        right_motor_power = (int)(BASE_SPEED - (steering_amount * LEFT_EDGE));

        /* 左右モータ駆動パワーの設定 */
        /* 計算されたモーターのパワーをモーターに設定 */
        ev3_motor_set_power(left_motor, left_motor_power);
        ev3_motor_set_power(right_motor, right_motor_power);

        /* 関数を終了 */
        return;
    }
