.data
test:	.byte	0xA0
.text
	la t0, test
	lb t1, 0(t0)