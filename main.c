#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include "block.h"

typedef struct {
    int id;
    char info[32];
} Transaction;

typedef struct {
    int index;
    char hash[64];
    char previous_hash[64];
    long timestamp;
    int nonce;
    Transaction transactions[2];
} Block;

int block_show()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    block.index = 1;
    block.hash = "00c01b629d0d0fba452a0a632945f1f0fd1dd92a864d102112f8ccde3eaf516b";
    block.previous_hash = "00ced8f1a7407460521d279364db6d48ccb8aa3ad839ea08220d7e8347d276ef";
    block.timestamp = tv.tv_sec;
    block.nonce = 1;
    block.transactions[0].id = 1;
    block.transactions[0].info= "共识机制生成的区块";
    block.transactions[1].id = 2;
    block.transactions[1].info= "区块链高度为2";

    printBlock(block);

    return 0;
}

int main() {
    block_show();

    struct timeval tv;
    gettimeofday(&tv, NULL);

    Block block = {
            .index = 1,
            .hash = "00c01b629d0d0fba452a0a632945f1f0fd1dd92a864d102112f8ccde3eaf516b",
            .previous_hash = "00ced8f1a7407460521d279364db6d48ccb8aa3ad839ea08220d7e8347d276ef",
            .timestamp = tv.tv_sec,
            .nonce = 1,
            .transactions[0].id = 1,
            .transactions[0].info = "共识机制生成的区块",
            .transactions[1].id = 1,
            .transactions[1].info = "区块链高度为2",
    };
    printf("%ld %s", block.timestamp, block.transactions[1].info);

    return 0;
}