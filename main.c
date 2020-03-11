#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include "block.h"

#define BLOCK_SIZE 2

typedef struct {
    int id;
    char info[32];
} Transaction2;

typedef struct {
    int index;
    char hash[64];
    char previous_hash[64];
    long timestamp;
    int nonce;
    Transaction2 transactions[BLOCK_SIZE];
} Block2;

struct dynamicArray {
    //表示数组实际长度
    int size;
    //表示数组的最大长度
    int capicity;
    //接收用户输入的值的首地址的指针
    int *ptr;
};

void printBlock(struct Block block) {
    printf("%d %s\n", block.index, block.transactions[0].info);
}

int block_show() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    block.index = 1;
    block.hash = "00c01b629d0d0fba452a0a632945f1f0fd1dd92a864d102112f8ccde3eaf516b";
    block.previous_hash = "00ced8f1a7407460521d279364db6d48ccb8aa3ad839ea08220d7e8347d276ef";
    block.timestamp = tv.tv_sec;
    block.nonce = 1;
    block.transactions[0].id = 1;
    block.transactions[0].info = "共识机制生成的区块";

    printBlock(block);

    struct Block block = {
            .index = 2,
            .hash = "00c01b629d0d0fba452a0a632945f1f0fd1dd92a864d102112f8ccde3eaf516b",
            .previous_hash = "00ced8f1a7407460521d279364db6d48ccb8aa3ad839ea08220d7e8347d276ef",
            .timestamp = tv.tv_sec,
            .nonce = 1,
            .transactions[0].id = 1,
            .transactions[0].info = "共识机制生成的区块",
    };
    printf("%ld %s\n", block.timestamp, block.transactions[0].info);

    Block2 block2 = {
            .index = 3,
            .hash = "00c01b629d0d0fba452a0a632945f1f0fd1dd92a864d102112f8ccde3eaf516b",
            .previous_hash = "00ced8f1a7407460521d279364db6d48ccb8aa3ad839ea08220d7e8347d276ef",
            .timestamp = tv.tv_sec,
            .nonce = 1,
            .transactions[0].id = 1,
            .transactions[0].info = "共识机制生成的区块",
            .transactions[1].id = 1,
            .transactions[1].info = "区块链高度为2",
    };
    printf("%ld %s\n", block2.timestamp, block2.transactions[1].info);

    return 0;
}

int main() {
    block_show();

    return 0;
}