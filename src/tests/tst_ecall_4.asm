.data
str:	.byte	'k' 'a' 'l' 'l' 'e' 'y' 00
.text
	la a0, str
	li a7, 4
	ecall