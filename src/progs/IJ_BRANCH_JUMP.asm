.data
w1: 	.word 46
w2: 	.word 77
w3: 	.word 600
c1: 	.asciz "Numbers for beq,bne: "
c2: 	.asciz " and "
c3: 	.asciz "\nNumber for bgtz,blez: "
nl: 	.asciz "\n"
beq_s: 	.asciz "Instruction beq activated.\n"
beq_n: 	.asciz "Instruction beq not activated.\n"
bne_s: 	.asciz "Instruction bne activated.\n"
bne_n: 	.asciz "Instruction bne not activated.\n"
bgtz_s: .asciz "Instruction bgtz activated.\n"
bgtz_n: .asciz "Instruction bgtz not activated.\n"
blez_s: .asciz "Instruction blez activated.\n"
blez_n: .asciz "Instruction blez not activated.\n"

.text
	lw s0, w1
	lw s1, w2
	lw s2, w3
	
	la a0, c1
	jal sprint
	addi a0, s0, 0
	jal iprint
	la a0, c2
	jal sprint
	addi a0, s1, 0
	jal iprint
	la  a0, c3
	jal sprint
	addi a0, s2, 0
	jal iprint
	la a0, nl
	jal sprint
	jal sprint
	
	beq s0, s1, L1
	la a0, beq_n
	j U1
L1:
	la a0, beq_s
U1:
	jal sprint
	
	bne s0, s1, L2
	la  a0, bne_n
	j U2
L2:
	la  a0, bne_s
U2:
	jal sprint
	
	bgtz s2, L3
	la a0, bgtz_n
	j U3
L3:
	la a0, bgtz_s
U3:
	jal sprint
	
	blez s2, L4
	la  a0, blez_n
	j U4
L4:
	la a0, blez_s
U4:
	jal sprint

	la a0, nl
	jal sprint
	
	jal end

sprint:
	li a7, 4
	ecall
	ret
	
iprint:
	li a7, 1
	ecall
	ret

end:
	li a7, 10
	ecall
