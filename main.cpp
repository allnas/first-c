#include <iostream>
#include <sys/time.h>

struct Transaction {
    int id;
    char *info;
};

struct Block {
    int index;
    char *hash;
    char *previous_hash;
    long timestamp;
    int nonce;
    struct Transaction transactions[2];
};

struct Block block;


int main() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    block.index = 1;
    block.hash = "00c01b629d0d0fba452a0a632945f1f0fd1dd92a864d102112f8ccde3eaf516b";
    block.previous_hash = "00ced8f1a7407460521d279364db6d48ccb8aa3ad839ea08220d7e8347d276ef";
    block.timestamp = tv.tv_sec;
    block.nonce = 1;
    block.transactions[0].id = 1;
    block.transactions[0].info = "共识机制生成的区块";
    block.transactions[1].id = 2;
    block.transactions[1].info = "区块链高度为2";

    printf("%d %s", block.timestamp, block.transactions[0].info);

    return 0;
}
