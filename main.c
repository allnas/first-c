#include "stdio.h"
#include "sys/time.h"
#include "string.h"

struct Transaction {
    int id;
    char info[32];
};

struct Block {
    int index;
    char hash[32];
    char previous_hash[32];
    long timestamp;
    int nonce;
    struct Transaction transactions[2];
};

struct Block block;

/**
 * ��������
 * @param block
 */
void printBlock(struct Block block);

void printBlock(struct Block block){
    printf("%d %s", block.timestamp, block.transactions[0].info);
}

int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    block.index = 1;
    strcpy(block.hash, "00c01b629d0d0fba452a0a632945f1f0fd1dd92a864d102112f8ccde3eaf516b");
    strcpy(block.previous_hash, "00ced8f1a7407460521d279364db6d48ccb8aa3ad839ea08220d7e8347d276ef");
    block.timestamp = tv.tv_sec;
    block.nonce = 1;
    block.transactions[0].id = 1;
    strcpy(block.transactions[0].info, "��ʶ�������ɵ�����");
    block.transactions[1].id = 2;
    strcpy(block.transactions[1].info, "�������߶�Ϊ2");

    printBlock(block);

    return 0;
}