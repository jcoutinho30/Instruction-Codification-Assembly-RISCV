//Nome: José Renato Coutinho, RA: 238012
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//conversao binario para hexadecimal
char binToHex(const char* bin) {
    if (strcmp(bin, "0000") == 0)
        return '0';
    else if (strcmp(bin, "0001") == 0)
        return '1';
    else if (strcmp(bin, "0010") == 0)
        return '2';
    else if (strcmp(bin, "0011") == 0)
        return '3';
    else if (strcmp(bin, "0100") == 0)
        return '4';
    else if (strcmp(bin, "0101") == 0)
        return '5';
    else if (strcmp(bin, "0110") == 0)
        return '6';
    else if (strcmp(bin, "0111") == 0)
        return '7';
    else if (strcmp(bin, "1000") == 0)
        return '8';
    else if (strcmp(bin, "1001") == 0)
        return '9';
    else if (strcmp(bin, "1010") == 0)
        return 'A';
    else if (strcmp(bin, "1011") == 0)
        return 'B';
    else if (strcmp(bin, "1100") == 0)
        return 'C';
    else if (strcmp(bin, "1101") == 0)
        return 'D';
    else if (strcmp(bin, "1110") == 0)
        return 'E';
    else if (strcmp(bin, "1111") == 0)
        return 'F';
    return 'L';
}

//conversao hexadecimal para binario
char* hexadecimalToBinary(char hexadecimal) {
    char* binario = malloc(5 * sizeof(char));
    switch(hexadecimal) {
        case '0':
            sprintf(binario, "0000");
            break;
        case '1':
            sprintf(binario, "0001");
            break;
        case '2':
            sprintf(binario, "0010");
            break;
        case '3':
            sprintf(binario, "0011");
            break;
        case '4':
            sprintf(binario, "0100");
            break;
        case '5':
            sprintf(binario, "0101");
            break;
        case '6':
            sprintf(binario, "0110");
            break;
        case '7':
            sprintf(binario, "0111");
            break;
        case '8':
            sprintf(binario, "1000");
            break;
        case '9':
            sprintf(binario, "1001");
            break;
        case 'A':
            sprintf(binario, "1010");
            break;
        case 'B':
            sprintf(binario, "1011");
            break;
        case 'C':
            sprintf(binario, "1100");
            break;
        case 'D':
            sprintf(binario, "1101");
            break;
        case 'E':
            sprintf(binario, "1110");
            break;
        case 'F':
            sprintf(binario, "1111");
            break;
    }
    return binario;
}

//conversao para numero binario negativo -> complemento de dois
char* binaryToTwoComplement(char* binary, int nBits) {
    int i = 0;
    for (i = nBits - 1; i >= 0; i--) {
        if (*(binary + i) == '1')
            break;
    }
    for (int j = i - 1; j >= 0; j--) {
        if (*(binary + j) == '1')
            *(binary + j) = '0';
        else
            *(binary + j) = '1';
    }
    return binary;
}

//dar free depois
//conversao de decimal para numero binario de 12bits
char* decimalToBinary(int decimal) {
    char* binary = (char*)malloc(13 * sizeof(char)); // Tamanho 13 para acomodar o '\0'
    int i;
    for (i = 11; i >= 0; i--) {
        binary[i] = (decimal % 2) + '0'; // Converte o dígito binário para caractere '0' ou '1'
        decimal /= 2;
    }
    binary[12] = '\0'; // Adiciona o caractere nulo de terminação da string
    return binary;
}

//funcao geral de conversao de decimal para binario em que o usuario pode escolher o numero de bits
char* decimalToBinary_escolha_n_bits(int decimal, int num_bits){
    char* binary = (char*)malloc((num_bits + 1) * sizeof(char)); 
    int i;
    for (i = num_bits - 1; i >= 0; i--) {
        binary[i] = (decimal % 2) + '0'; 
        decimal /= 2;
    }
    binary[num_bits] = '\0'; 
    return binary;
}

//funcao para correspondencia de cada registrador na sua forma nominal (a0, t0, ra...) para sua forma em binario
char* reg_binario(char* reg) {
    char* resultado = malloc(6 * sizeof(char)); 
    if (strcmp(reg, "zero") == 0)
        strcpy(resultado, "00000");
    else if (strcmp(reg, "ra") == 0)
        strcpy(resultado, "00001");
    else if (strcmp(reg, "sp") == 0)
        strcpy(resultado, "00010");
    else if (strcmp(reg, "gp") == 0)
        strcpy(resultado, "00011");
    else if (strcmp(reg, "tp") == 0)
        strcpy(resultado, "00100");
    else if (strcmp(reg, "t0") == 0)
        strcpy(resultado, "00101");
    else if (strcmp(reg, "t1") == 0)
        strcpy(resultado, "00110");
    else if (strcmp(reg, "t2") == 0)
        strcpy(resultado, "00111");
    else if (strcmp(reg, "s0") == 0)
        strcpy(resultado, "01000");
    else if (strcmp(reg, "fp") == 0)
        strcpy(resultado, "01000");
    else if (strcmp(reg, "s1") == 0)
        strcpy(resultado, "01001");
    else if (strcmp(reg, "a0") == 0)
        strcpy(resultado, "01010");
    else if (strcmp(reg, "a1") == 0)
        strcpy(resultado, "01011");
    else if (strcmp(reg, "a2") == 0)
        strcpy(resultado, "01100");
    else if (strcmp(reg, "a3") == 0)
        strcpy(resultado, "01101");
    else if (strcmp(reg, "a4") == 0)
        strcpy(resultado, "01110");
    else if (strcmp(reg, "a5") == 0)
        strcpy(resultado, "01111");
    else if (strcmp(reg, "a6") == 0)
        strcpy(resultado, "10000");
    else if (strcmp(reg, "a7") == 0)
        strcpy(resultado, "10001");
    else if (strcmp(reg, "s2") == 0)
        strcpy(resultado, "10010");
    else if (strcmp(reg, "s3") == 0)
        strcpy(resultado, "10011");
    else if (strcmp(reg, "s4") == 0)
        strcpy(resultado, "10100");
    else if (strcmp(reg, "s5") == 0)
        strcpy(resultado, "10101");
    else if (strcmp(reg, "s6") == 0)
        strcpy(resultado, "10110");
    else if (strcmp(reg, "s7") == 0)
        strcpy(resultado, "10111");
    else if (strcmp(reg, "s8") == 0)
        strcpy(resultado, "11000");
    else if (strcmp(reg, "s9") == 0)
        strcpy(resultado, "11001");
    else if (strcmp(reg, "s10") == 0)
        strcpy(resultado, "11010");
    else if (strcmp(reg, "s11") == 0)
        strcpy(resultado, "11011");
    else if (strcmp(reg, "t3") == 0)
        strcpy(resultado, "11100");
    else if (strcmp(reg, "t4") == 0)
        strcpy(resultado, "11101");
    else if (strcmp(reg, "t5") == 0)
        strcpy(resultado, "11110");
    else if (strcmp(reg, "t6") == 0)
        strcpy(resultado, "11111");
    else {
        free(resultado); // Libera a memória alocada
        return NULL;
    }
    return resultado;
}




int main(void){
    
    int imm = 0;
    //a entrada recebe a instrucao como um todo, por exemplo "addi t0, a1, 5"
    char entrada[100];
    char *pt;

    //aqui a instrucao eh fragmentada em algumas partes: instru_1 contem a primeira componente da instrucao (por ex: 'lw')
    //enquanto reg_result recebe o proximo parametro(por ex: 'li a1, 1000', reg_result nesse caso seria a1)
    //a mesma logica é aplicada aos vetores seguintes, caso haja parametros a serem lidos, serao armazenados
    char instru_1[10];
    char reg_result[10];
    char reg_1[10];
    char reg_2[10];
    
    fgets(entrada, sizeof(entrada), stdin);

    // divide a string em tokens usando " ,\n()" como delimitadores
    pt = strtok(entrada, " ,\n()");

    // Copia o primeiro token para str1
    if (pt != NULL) {
        strncpy(instru_1, pt, sizeof(instru_1) - 1);
        instru_1[sizeof(instru_1) - 1] = '\0'; // adiciona o terminador nulo no final
    }

    // continua a divisão em tokens e copia para as outras strings
    int i = 1;
    while (pt != NULL && i < 4) {
        pt = strtok(NULL, " ,\n()");
        if (pt != NULL) {
            switch (i) {
                case 1:
                    strncpy(reg_result, pt, sizeof(reg_result) - 1);
                    reg_result[sizeof(reg_result) - 1] = '\0';
                    break;
                case 2:
                    strncpy(reg_1, pt, sizeof(reg_1) - 1);
                    reg_1[sizeof(reg_1) - 1] = '\0';
                    break;
                case 3:
                    strncpy(reg_2, pt, sizeof(reg_2) - 1);
                    reg_2[sizeof(reg_2) - 1] = '\0';
                    break;
            }
        }
        i++;
    }

    //instrucao addi completa para inteiros negativos e positivos
    if (strcmp(instru_1, "addi") == 0) {
        //caso em que o imediato eh positivo
        if(reg_2[0] != '-'){
            //funcao 'atoi' faz com que uma string seja interpretada como numero inteiro
            imm = atoi(reg_2);
            char* binary_imm = decimalToBinary(imm);
            char codif[61];
            strcpy(codif, binary_imm);
            strcat(codif, reg_binario(reg_1));
            strcat(codif, "000");
            strcat(codif, reg_binario(reg_result));
            strcat(codif, "0010011");
            //converte a instrucao de 32bits para 8 numeros de 4bits cada, para posteriormente converter para hexadecimal
            char separando[8][5];
            for (int i = 0; i < 8; i++) {
                strncpy(separando[i], codif + (i * 4), 4);
                separando[i][4] = '\0'; // adiciona o caractere nulo de terminação à string separada
            }
            printf("0x");
            printf("%c", binToHex(separando[0]));
            printf("%c", binToHex(separando[1]));
            printf("%c", binToHex(separando[2]));
            printf("%c", binToHex(separando[3]));
            printf("%c", binToHex(separando[4]));
            printf("%c", binToHex(separando[5]));
            printf("%c", binToHex(separando[6]));
            printf("%c\n", binToHex(separando[7]));
        free(binary_imm);
        }
        else{
            //bloco em que recebemos um imediato negativo
            //ajustando o valor deste imediato, que posteriormente ficara na forma de complemento de dois
            imm = atoi(reg_2);
            imm = imm * (-1);
            //binario na forma positiva
            char* binary_imm1 = decimalToBinary(imm);
            //complemento de dois
            char* binary_imm = binaryToTwoComplement(binary_imm1, 12);
            char codif[61];
            strcpy(codif, binary_imm);
            strcat(codif, reg_binario(reg_1));
            strcat(codif, "000");
            strcat(codif, reg_binario(reg_result));
            strcat(codif, "0010011");
            char separando[8][5];
            for (int i = 0; i < 8; i++) {
                strncpy(separando[i], codif + (i * 4), 4);
                separando[i][4] = '\0'; 
            }
            printf("0x");
            printf("%c", binToHex(separando[0]));
            printf("%c", binToHex(separando[1]));
            printf("%c", binToHex(separando[2]));
            printf("%c", binToHex(separando[3]));
            printf("%c", binToHex(separando[4]));
            printf("%c", binToHex(separando[5]));
            printf("%c", binToHex(separando[6]));
            printf("%c\n", binToHex(separando[7]));
        free(binary_imm1);
        }
}

    //codificando instrucao slli
    //mais eficiente criar uma funcao que recebe dois parametros: numero inteiro e a quantidade de bits p converter p binario
    //instrucao slli completa para numeros inteiros (nao ha aplicacao com imediatos negativos)
    if(strcmp(instru_1, "slli") == 0){
        imm = atoi(reg_2);
        char *binary_imm = decimalToBinary_escolha_n_bits(imm, 5);
        char codif[61];
        strcpy(codif, "0000000");
        strcat(codif, binary_imm);
        strcat(codif, reg_binario(reg_1));
        strcat(codif, "001");
        strcat(codif, reg_binario(reg_result));
        strcat(codif, "0010011");
        char separando[8][5];
        for (int i = 0; i < 8; i++) {
            strncpy(separando[i], codif + (i * 4), 4);
            separando[i][4] = '\0'; 
        }
        printf("0x");
        printf("%c", binToHex(separando[0]));
        printf("%c", binToHex(separando[1]));
        printf("%c", binToHex(separando[2]));
        printf("%c", binToHex(separando[3]));
        printf("%c", binToHex(separando[4]));
        printf("%c", binToHex(separando[5]));
        printf("%c", binToHex(separando[6]));
        printf("%c\n", binToHex(separando[7]));
    free(binary_imm);
    }

    if(strcmp(instru_1, "xor") == 0){
        char codif[61];
        strcpy(codif, "0000000");
        strcat(codif, reg_binario(reg_2));
        strcat(codif, reg_binario(reg_1));
        strcat(codif, "100");
        strcat(codif, reg_binario(reg_result));
        strcat(codif, "0110011");
        char separando[8][5];
        for (int i = 0; i < 8; i++) {
            strncpy(separando[i], codif + (i * 4), 4);
            separando[i][4] = '\0'; 
        }
        printf("0x");
        printf("%c", binToHex(separando[0]));
        printf("%c", binToHex(separando[1]));
        printf("%c", binToHex(separando[2]));
        printf("%c", binToHex(separando[3]));
        printf("%c", binToHex(separando[4]));
        printf("%c", binToHex(separando[5]));
        printf("%c", binToHex(separando[6]));
        printf("%c\n", binToHex(separando[7]));
    }

    if(strcmp(instru_1, "beq") == 0){
        char codif[61];
            imm = atoi(reg_2);
            imm = imm - 1000;
            if(imm < 0){
                imm = imm * (-1);
                char* binary_imm1 = decimalToBinary_escolha_n_bits(imm, 13);
                char* binary_imm = binaryToTwoComplement(binary_imm1, 13);
                binary_imm[12] = '\0';
                codif[0] = binary_imm[0];
                codif[1] = binary_imm[2];
                codif[2] = binary_imm[3];
                codif[3] = binary_imm[4];
                codif[4] = binary_imm[5];
                codif[5] = binary_imm[6];
                codif[6] = binary_imm[7];

                char* aux_reg2 = reg_binario(reg_1);
                char* aux_reg1 = reg_binario(reg_result);

                codif[7] = aux_reg2[0];
                codif[8] = aux_reg2[1];
                codif[9] = aux_reg2[2];
                codif[10] = aux_reg2[3];
                codif[11] = aux_reg2[4];
                codif[12] = aux_reg1[0];
                codif[13] = aux_reg1[1];
                codif[14] = aux_reg1[2];
                codif[15] = aux_reg1[3];
                codif[16] = aux_reg1[4];
                codif[17] = '0';
                codif[18] = '0';
                codif[19] = '0';
                codif[20] = binary_imm[8];
                codif[21] = binary_imm[9];
                codif[22] = binary_imm[10];
                codif[23] = binary_imm[11];
                codif[24] = binary_imm[1];
                codif[25] = '1';
                codif[26] = '1';
                codif[27] = '0';
                codif[28] = '0';
                codif[29] = '0';
                codif[30] = '1';
                codif[31] = '1';
                codif[32] = '\0';

                char separando[8][5];
                for (int i = 0; i < 8; i++) {
                    strncpy(separando[i], codif + (i * 4), 4);
                    separando[i][4] = '\0'; 
                }
                printf("0x");
                printf("%c", binToHex(separando[0]));
                printf("%c", binToHex(separando[1]));
                printf("%c", binToHex(separando[2]));
                printf("%c", binToHex(separando[3]));
                printf("%c", binToHex(separando[4]));
                printf("%c", binToHex(separando[5]));
                printf("%c", binToHex(separando[6]));
                printf("%c\n", binToHex(separando[7]));
            }

            else{
                char* binary_imm = decimalToBinary_escolha_n_bits(imm, 13);
                binary_imm[12] = '\0';
                codif[0] = binary_imm[0];
                codif[1] = binary_imm[2];
                codif[2] = binary_imm[3];
                codif[3] = binary_imm[4];
                codif[4] = binary_imm[5];
                codif[5] = binary_imm[6];
                codif[6] = binary_imm[7];
                char* aux_reg2 = reg_binario(reg_1);
                char* aux_reg1 = reg_binario(reg_result);
                codif[7] = aux_reg2[0];
                codif[8] = aux_reg2[1];
                codif[9] = aux_reg2[2];
                codif[10] = aux_reg2[3];
                codif[11] = aux_reg2[4];
                codif[12] = aux_reg1[0];
                codif[13] = aux_reg1[1];
                codif[14] = aux_reg1[2];
                codif[15] = aux_reg1[3];
                codif[16] = aux_reg1[4];
                codif[17] = '0';
                codif[18] = '0';
                codif[19] = '0';
                codif[20] = binary_imm[8];
                codif[21] = binary_imm[9];
                codif[22] = binary_imm[10];
                codif[23] = binary_imm[11];
                codif[24] = binary_imm[1];
                codif[25] = '1';
                codif[26] = '1';
                codif[27] = '0';
                codif[28] = '0';
                codif[29] = '0';
                codif[30] = '1';
                codif[31] = '1';
                codif[32] = '\0';
                char separando[8][5];
                for (int i = 0; i < 8; i++) {
                    strncpy(separando[i], codif + (i * 4), 4);
                    separando[i][4] = '\0'; 
                }
                printf("0x");
                printf("%c", binToHex(separando[0]));
                printf("%c", binToHex(separando[1]));
                printf("%c", binToHex(separando[2]));
                printf("%c", binToHex(separando[3]));
                printf("%c", binToHex(separando[4]));
                printf("%c", binToHex(separando[5]));
                printf("%c", binToHex(separando[6]));
                printf("%c\n", binToHex(separando[7]));
            }
    }

    if(strcmp(instru_1, "lw") == 0){
        char codif[61];
        int imm = atoi(reg_1);
        strcpy(codif, decimalToBinary_escolha_n_bits(imm, 12));
        strcat(codif, reg_binario(reg_2));
        strcat(codif, "010");
        strcat(codif, reg_binario(reg_result));
        strcat(codif, "0000011");
        char separando[8][5];
            for (int i = 0; i < 8; i++) {
                strncpy(separando[i], codif + (i * 4), 4);
                separando[i][4] = '\0'; 
            }
        printf("0x");
        printf("%c", binToHex(separando[0]));
        printf("%c", binToHex(separando[1]));
        printf("%c", binToHex(separando[2]));
        printf("%c", binToHex(separando[3]));
        printf("%c", binToHex(separando[4]));
        printf("%c", binToHex(separando[5]));
        printf("%c", binToHex(separando[6]));
        printf("%c\n", binToHex(separando[7]));
    }

    if(strcmp(instru_1, "sw") == 0){
        char codif[61];
        int imm = atoi(reg_1);
        char *binary_imm = decimalToBinary_escolha_n_bits(imm, 12);
        codif[0] = binary_imm[0];
        codif[1] = binary_imm[1];
        codif[2] = binary_imm[2];
        codif[3] = binary_imm[3];
        codif[4] = binary_imm[4];
        codif[5] = binary_imm[5];
        codif[6] = binary_imm[6];
        codif[7] = '\0';
        strcat(codif, reg_binario(reg_result));
        strcat(codif, reg_binario(reg_2));
        strcat(codif, "010");
        codif[20] = binary_imm[7];
        codif[21] = binary_imm[8];
        codif[22] = binary_imm[9];
        codif[23] = binary_imm[10];
        codif[24] = binary_imm[11];
        codif[25] = '\0';
        strcat(codif, "0100011");
        char separando[8][5];
            for (int i = 0; i < 8; i++) {
                strncpy(separando[i], codif + (i * 4), 4);
                separando[i][4] = '\0'; 
            }
        printf("0x");
        printf("%c", binToHex(separando[0]));
        printf("%c", binToHex(separando[1]));
        printf("%c", binToHex(separando[2]));
        printf("%c", binToHex(separando[3]));
        printf("%c", binToHex(separando[4]));
        printf("%c", binToHex(separando[5]));
        printf("%c", binToHex(separando[6]));
        printf("%c\n", binToHex(separando[7]));
        free(binary_imm);
    }

    if(strcmp(instru_1, "mul") == 0){
        char codif[61];
        strcpy(codif, "0000001");
        strcat(codif, reg_binario(reg_2));
        strcat(codif, reg_binario(reg_1));
        strcat(codif, "000");
        strcat(codif, reg_binario(reg_result));
        strcat(codif, "0110011");
        char separando[8][5];
            for (int i = 0; i < 8; i++) {
                strncpy(separando[i], codif + (i * 4), 4);
                separando[i][4] = '\0'; 
            }
        printf("0x");
        printf("%c", binToHex(separando[0]));
        printf("%c", binToHex(separando[1]));
        printf("%c", binToHex(separando[2]));
        printf("%c", binToHex(separando[3]));
        printf("%c", binToHex(separando[4]));
        printf("%c", binToHex(separando[5]));
        printf("%c", binToHex(separando[6]));
        printf("%c\n", binToHex(separando[7]));

    }

    if(strcmp(instru_1, "ret") == 0){
        char codif[61];
        strcpy(codif, "000000000000");
        strcat(codif, reg_binario("ra"));
        strcat(codif, "000");
        strcat(codif, reg_binario("zero"));
        strcat(codif, "1100111");
        char separando[8][5];
            for (int i = 0; i < 8; i++) {
                strncpy(separando[i], codif + (i * 4), 4);
                separando[i][4] = '\0'; 
            }
        printf("0x");
        printf("%c", binToHex(separando[0]));
        printf("%c", binToHex(separando[1]));
        printf("%c", binToHex(separando[2]));
        printf("%c", binToHex(separando[3]));
        printf("%c", binToHex(separando[4]));
        printf("%c", binToHex(separando[5]));
        printf("%c", binToHex(separando[6]));
        printf("%c\n", binToHex(separando[7]));
    }

    if(strcmp(instru_1, "call") == 0){
        imm = atoi(reg_result);
        imm = imm - 1000;
        if(imm < 0){
            //codificando jal
            imm = imm * (-1);
            char* binary_imm1 = decimalToBinary_escolha_n_bits(imm, 21);
            char* binary_imm = binaryToTwoComplement(binary_imm1, 21);
            char codif[61];
            codif[0] = binary_imm[0];
            codif[1] = binary_imm[10];
            codif[2] = binary_imm[11];
            codif[3] = binary_imm[12];
            codif[4] = binary_imm[13];
            codif[5] = binary_imm[14];
            codif[6] = binary_imm[15];
            codif[7] = binary_imm[16];
            codif[8] = binary_imm[17];
            codif[9] = binary_imm[18];
            codif[10] = binary_imm[19];
            codif[11] = binary_imm[9];
            codif[12] = binary_imm[1];
            codif[13] = binary_imm[2];
            codif[14] = binary_imm[3];
            codif[15] = binary_imm[4];
            codif[16] = binary_imm[5];
            codif[17] = binary_imm[6];
            codif[18] = binary_imm[7];
            codif[19] = binary_imm[8];
            codif[20] = '\0';
            strcat(codif, reg_binario("ra"));
            strcat(codif, "1101111");
            char separando[8][5];
                for (int i = 0; i < 8; i++) {
                    strncpy(separando[i], codif + (i * 4), 4);
                    separando[i][4] = '\0'; 
                }
            printf("0x");
            printf("%c", binToHex(separando[0]));
            printf("%c", binToHex(separando[1]));
            printf("%c", binToHex(separando[2]));
            printf("%c", binToHex(separando[3]));
            printf("%c", binToHex(separando[4]));
            printf("%c", binToHex(separando[5]));
            printf("%c", binToHex(separando[6]));
            printf("%c\n", binToHex(separando[7]));
            free(binary_imm1);
        }
        else{
            char* binary_imm = decimalToBinary_escolha_n_bits(imm, 21);
            char codif[61];
            codif[0] = binary_imm[0];
            codif[1] = binary_imm[10];
            codif[2] = binary_imm[11];
            codif[3] = binary_imm[12];
            codif[4] = binary_imm[13];
            codif[5] = binary_imm[14];
            codif[6] = binary_imm[15];
            codif[7] = binary_imm[16];
            codif[8] = binary_imm[17];
            codif[9] = binary_imm[18];
            codif[10] = binary_imm[19];
            codif[11] = binary_imm[9];
            codif[12] = binary_imm[1];
            codif[13] = binary_imm[2];
            codif[14] = binary_imm[3];
            codif[15] = binary_imm[4];
            codif[16] = binary_imm[5];
            codif[17] = binary_imm[6];
            codif[18] = binary_imm[7];
            codif[19] = binary_imm[8];
            codif[20] = '\0';
            strcat(codif, reg_binario("ra"));
            strcat(codif, "1101111");
            char separando[8][5];
                for (int i = 0; i < 8; i++) {
                    strncpy(separando[i], codif + (i * 4), 4);
                    separando[i][4] = '\0';
                }
            printf("0x");
            printf("%c", binToHex(separando[0]));
            printf("%c", binToHex(separando[1]));
            printf("%c", binToHex(separando[2]));
            printf("%c", binToHex(separando[3]));
            printf("%c", binToHex(separando[4]));
            printf("%c", binToHex(separando[5]));
            printf("%c", binToHex(separando[6]));
            printf("%c\n", binToHex(separando[7]));
            free(binary_imm);
        }
    }

    if(strcmp(instru_1, "lui") == 0){
        char codif[61];
        //como lui eh frequentemente utilizado para numeros muito grandes, preparei meu codigo de tal forma que o usuario tambem possa
        //entrar com um numero em Hexadecimal
        if(reg_1[0] == '0' && reg_1[1] == 'x'){
            char hex_bin[30];
            int iniciou = 1;
            for(int i = 2; i < (int)strlen(reg_1); i++){
                if(iniciou == 0)
                    strcat(hex_bin, hexadecimalToBinary(reg_1[i]));
                else{
                    strcpy(hex_bin, hexadecimalToBinary(reg_1[i]));
                    iniciou = 0;
                }
            }
            strcat(codif, hex_bin);
            strcat(codif, reg_binario(reg_result));
            strcat(codif, "0110111");
            char separando[8][5];
                for (int i = 0; i < 8; i++) {
                    strncpy(separando[i], codif + (i * 4), 4);
                    separando[i][4] = '\0';
                }
            printf("0x");
            printf("%c", binToHex(separando[0]));
            printf("%c", binToHex(separando[1]));
            printf("%c", binToHex(separando[2]));
            printf("%c", binToHex(separando[3]));
            printf("%c", binToHex(separando[4]));
            printf("%c", binToHex(separando[5]));
            printf("%c", binToHex(separando[6]));
            printf("%c\n", binToHex(separando[7]));
        }
        else{
            imm = atoi(reg_1);
            if(imm > 0){
                char *binary_imm = decimalToBinary_escolha_n_bits(imm, 20);
                strcpy(codif, binary_imm);
                strcat(codif, reg_binario(reg_result));
                strcat(codif, "0110111");
                char separando[8][5];
                    for (int i = 0; i < 8; i++) {
                        strncpy(separando[i], codif + (i * 4), 4);
                        separando[i][4] = '\0'; 
                    }
                printf("0x");
                printf("%c", binToHex(separando[0]));
                printf("%c", binToHex(separando[1]));
                printf("%c", binToHex(separando[2]));
                printf("%c", binToHex(separando[3]));
                printf("%c", binToHex(separando[4]));
                printf("%c", binToHex(separando[5]));
                printf("%c", binToHex(separando[6]));
                printf("%c\n", binToHex(separando[7]));
                free(binary_imm);
            }
            else{
                imm = imm * (-1);
                char *binary_imm1 = decimalToBinary_escolha_n_bits(imm, 20);
                char *binary_imm = binaryToTwoComplement(binary_imm1, 20);
                strcpy(codif, binary_imm);
                strcat(codif, reg_binario(reg_result));
                strcat(codif, "0110111");
                char separando[8][5];
                    for (int i = 0; i < 8; i++) {
                        strncpy(separando[i], codif + (i * 4), 4);
                        separando[i][4] = '\0'; 
                    }
                printf("0x");
                printf("%c", binToHex(separando[0]));
                printf("%c", binToHex(separando[1]));
                printf("%c", binToHex(separando[2]));
                printf("%c", binToHex(separando[3]));
                printf("%c", binToHex(separando[4]));
                printf("%c", binToHex(separando[5]));
                printf("%c", binToHex(separando[6]));
                printf("%c\n", binToHex(separando[7]));
                free(binary_imm1);
            }

        }

    }

}
