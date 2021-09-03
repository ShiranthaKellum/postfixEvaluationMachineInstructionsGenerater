# postfixEvaluationMachineInstructionsGenerater
There is a C code

Assume a machine that has a single register and six instructions.

  LD A which places the operand A into the register.
  ST A which places the contents of the register into the variable A.
  AD A which adds the contents of variable A to the register.
  SB A which subtracts the contents of the variable A from the register.
  ML A which multiplies the contents of the register by the variable A.
  DV A which divides the contents of the register by the variable A.

This C a program that accepts a postfix expression containing single-letter operands and
the operators +,-,*, and / and which prints a sequence of instructions to evaluate the
expression and leave the result in the register.

This code has used variables of the form TEMPn as temporary variables.
