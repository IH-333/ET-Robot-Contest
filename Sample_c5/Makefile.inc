/* MAKEFILE_LIST は、現在のMakefileのファイル名を含む空白区切りのリストを保持 */
/* lastword 関数は、空白で区切られたリストの最後の単語を取得 */
/* 現在のMakefileのファイル名を取得 */
/* dir 関数は、パスからディレクトリ部分を取得 */
/* mkfile_path には、このMakefileのパスが格納 */
mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

/* APPL_COBJS は、アプリケーションのオブジェクトファイルのリストを表す */
/* LineTracer.o を追加 */
APPL_COBJS +=\
LineTracer.o\

/* APPL_LIBS は、アプリケーションがリンクする必要のあるライブラリを指定 */
/* 標準数学ライブラリである libm を追加 */
APPL_LIBS += -lm

/* APPL_DIRS は、アプリケーションのソースコードが含まれるディレクトリのリスト */
/* LineTracer ディレクトリを追加 */
APPL_DIRS += $(mkfile_path)LineTracer

/* INCLUDES は、プリプロセッサに対する追加のインクルードディレクトリを指定 */
/* LineTracer ディレクトリを追加 */
INCLUDES += \
	-I$(mkfile_path)LineTracer\
