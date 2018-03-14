.equ STACK_TOP, 0x20000800
.text
.global _start
.code 16
.syntax unified

_start:

.word STACK_TOP, start
.type start, function
/* 主程序入口点 */
start:
	ldr sp, = 0x20000800
	ldr lr, = deadloop
	ldr pc, =main
deadloop:
	b deadloop
.end