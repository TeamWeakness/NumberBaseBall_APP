//
// Created by Administrator on 2020-11-10.
//

#include "myHeader.h"
typedef struct numberBB_info
{
    //int viewNumAry[9][10][10]; // 언젠가 필요할까?
    int viewNum[999];
    /*int fisrtNum[9];
    int secondNum[10];
    int thirdNum[10];*/
    int randNum[3];
    int inputNum[3];
    int strike;
    int ball;

}NumberBB;

int dataInit(NumberBB* nbb);
void initDataPrint(NumberBB nbb);

extern "C"
JNIEXPORT jstring JNICALL
Java_com_weakness_numberbaseball_PlayballActivity_main(JNIEnv* env,jobject /* this */)
{
    return env->NewStringUTF("이렇게 하는건가??");
}


extern "C" JNIEXPORT jstring JNICALL // 이건 메소드마다 추가 해줘야 하는건가?? 왜 메소드별로 없으면 오류가 날까..?
Java_com_weakness_numberbaseball_PlayballActivity_test(JNIEnv *env, jobject thiz) {
// TODO: implement test()
}