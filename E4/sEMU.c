#include <stdint.h>
#include <string.h>
#include <stdio.h>


int8_t PC = 0;
int8_t R[4] = {0, 0, 0, 0};
int8_t M[24] = {1, 0 ,0 ,100 
                ,1 ,1 ,1 ,1
                ,1 ,2 ,2 ,1
                ,2 ,1 ,1 ,2
                ,3 ,-8,0 ,1
                ,4 ,-4,0 ,1}; 


void inst_cycle(void);
int main(){
    int n = 1;
    while (n){
        inst_cycle();
        n++;
        if (n == 100){
            n = 0;
        }
    }
}

void inst_cycle(){
    int opcode[4];
    for (int i = 0; i < 4; i++){
        opcode[i] = M[PC + i];
    }
    int rs1 = R[opcode[2]];
    int rs2 = R[opcode[3]];

    int Imm = rs1 + opcode[3];
    int Reg = rs1 + rs2;
    int B = (rs1 - rs2) > 0;

    switch (opcode[0])
    {
    case 1:
        R[opcode[1]] = Imm; 
        break;
    case 2:
        R[opcode[1]] = Reg; 
        break;
    case 3: 
        if (B){
            PC = PC + opcode[1];
        }
        break;
    case 4:
        if (!B){
            PC = PC + opcode[1];
        }
        break;
    
    default:
        
        break;
    }
    
    
    PC = PC + 4;
    printf("寄存器：");
    for (int i = 0; i < 4; i++) {
        printf("%d ", R[i]);
    }
    printf("   PC = %d\n",PC);

}

