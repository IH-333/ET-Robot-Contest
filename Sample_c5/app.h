/* C++ コンパイラでのみ有効になる条件付きコンパイルのディレクティブ */
#ifdef __cplusplus
/* C++ コンパイラに対して、このブロック内の関数や変数が C 言語として解釈されるように指示 */
extern "C" {
#endif

/* EV3 プラットフォームで使用される API ヘッダーファイルをインクルード */
/* EV3 プラットフォーム向けの関数や定義を提供 */
#include "ev3api.h"

/* タスク優先度 */
/* メインタスクの優先度を定義 */
/* TMIN_APP_TPRI は TOPPERS/ASP カーネルで定義されたマクロで、
    アプリケーションタスクの最低優先度を表す */
#define MAIN_PRIORITY    (TMIN_APP_TPRI + 1) /* メインタスク */

/* ライントレースタスクの優先度を定義 */
/* メインタスクよりも優先度が低くなるように設定されている */
#define TRACER_PRIORITY  (TMIN_APP_TPRI + 2) /* ライントレースタスク */

/* タスク周期の定義 */
/* ライントレースタスクの周期を定義 */
/* ここでは 100msec (ミリ秒) ごとにタスクが実行されることが期待されている */
#define LINE_TRACER_PERIOD  (100 * 1000) /* ライントレースタスク:100msec周期 */

/* センサーポートの定義 */
/* センサーポートを示す変数の静的な宣言 */
/* sensor_port_t 型の定数が定義 */
static const sensor_port_t
    touch_sensor    = EV3_PORT_1, /* タッチセンサの定義 */
    color_sensor    = EV3_PORT_2, /* カラーセンサの定義 */
    sonar_sensor    = EV3_PORT_3, /* 音波センサの定義 */
    gyro_sensor     = EV3_PORT_4; /* ジャイロセンサの定義 */

/* モーターポートの定義 */
/* モーターポートを示す変数の静的な宣言 */
/* motor_port_t 型の定数が定義 */
static const motor_port_t
    arm_motor       = EV3_PORT_A, /* アームモーターの定義 */
    left_motor      = EV3_PORT_C, /* 左モーターの定義 */
    right_motor     = EV3_PORT_B; /* 右モーターの定義 */

/* STACK_SIZE が定義されていない場合の条件付きコンパイルのディレクティブ */
/* STACK_SIZE が事前に定義されていない場合に、次の行の #define STACK_SIZE が有効になる */
#ifndef STACK_SIZE

/* スタックサイズを定義 */
/* スタックは、関数呼び出しやローカル変数のために使用されるメモリ領域 */
/* スタックサイズは 4096 バイト */
#define STACK_SIZE      (4096)

/* #ifndef STACK_SIZE の条件付きコンパイルブロックの終了を示すディレクティブ */
/* STACK_SIZE */
#endif

/* TOPPERS_MACRO_ONLY が定義されていない場合の条件付きコンパイルのディレクティブ */
/* TOPPERS_MACRO_ONLY は、マクロのみが含まれており、
    関数の定義が含まれていないことを示すために使用 */
#ifndef TOPPERS_MACRO_ONLY

/* main_task 関数のプロトタイプ宣言 */
/* この関数はメインタスクのエントリーポイント */
extern void main_task(intptr_t exinf);

/* tracer_task 関数のプロトタイプ宣言 */
/* この関数はライントレースタスクのエントリーポイント */
extern void tracer_task(intptr_t exinf);

/* #ifndef TOPPERS_MACRO_ONLY の条件付きコンパイルブロックの終了を示すディレクティブ */
#endif /* TOPPERS_MACRO_ONLY */

/* C++ コンパイラでのみ有効になる条件付きコンパイルのディレクティブ */
#ifdef __cplusplus
}
#endif
