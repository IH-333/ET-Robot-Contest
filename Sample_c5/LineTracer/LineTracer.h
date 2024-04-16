/* ライントレーサーロボットの挙動を柔軟に制御するために使用 */

/* #ifdef __cplusplus は、C++ コンパイラでコードが処理されている場合に、
    条件を実行するためのプリプロセッサディレクティブ */
#ifdef __cplusplus
/* extern "C" { は、C++ コンパイラに対して、
    以下のブロック内の関数や変数が C 言語の形式で定義されていることを示す */
extern "C" {
#endif

/* 下記の項目は各ロボットに合わせて変えること */

    /* ライントレーサーの挙動を制御するための定数やマクロが定義 */
    /* カラーセンサの輝度設定 */
    /* WHITE_BRIGHTNESS と BLACK_BRIGHTNESS は、
        カラーセンサーがラインの白と黒をどのように検出するかを定義する*/
    #define WHITE_BRIGHTNESS  (180)
    #define BLACK_BRIGHTNESS  (10) 

    /* ステアリング操舵量の係数 */
    /* STEERING_COEF は、ステアリングの感度を表す */
    #define STEERING_COEF     (0.2F) 

    /* 走行基準スピード */
    /* BASE_SPEED は、モーターの基準速度を定義 */
    #define BASE_SPEED        (40) 

    /* ライントレースエッジ切り替え */
    /* LEFT_EDGE と RIGHT_EDGE は、ラインを検出したときの走行エッジの方向を定義 */
    #define LEFT_EDGE         (-1) 
    #define RIGHT_EDGE        (1) 

    /* #ifdef __cplusplus と #endif で囲まれたブロックは、
        C++ コンパイラの場合にのみ処理される */
    #ifdef __cplusplus
    }
    #endif
