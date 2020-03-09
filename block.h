//
// Created by allnas on 2020/3/7.
//

#ifndef FIRST_C_COMMON_H
#define FIRST_C_COMMON_H

#endif //FIRST_C_COMMON_H

struct Transaction {
    int id;
    char* info;
};

struct Block {
    int index;
    char* hash;
    char* previous_hash;
    long timestamp;
    int nonce;
    struct Transaction transactions[1];
};

struct Block block;

/**
 * 函数声明
 * @param block
 */
void printBlock(struct Block block);