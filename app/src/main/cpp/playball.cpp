//
// Created by Administrator on 2020-11-10.
//

#include "myHeader.h"
typedef struct numberBB_info
{
    int randNum[3];
    int inputNum[3];
    int strike;
    int ball;

}NumberBB;

int playBall(NumberBB* nbb);
int nRound(NumberBB* nbb);

static NumberBB nbb = { 0, };

extern "C"
JNIEXPORT jint JNICALL // 이건 메소드마다 추가 해줘야 하는건가?? 왜 메소드별로 없으면 오류가 날까..?
Java_com_weakness_numberbaseball_PlayballActivity_main(JNIEnv* env,jobject /* this */, jint inputNum ,jint firstNum, jint secondNum, jint thirdNum)
{
    int res[2] = {0, };

    nbb.strike;
    nRound(&nbb);
    res[0] = nbb.strike;
    res[1] = nbb.ball;

    return (jint)res;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_weakness_numberbaseball_PlayballActivity_dataInit(JNIEnv* env,jclass )
{
    // 랜덤 값 초기화
    int row = 1;
    srand((unsigned int)time(NULL));
    nbb.randNum[0] = rand() % 9 + 1;
    while(1)
    {
        nbb.randNum[row] = rand() % 9;
        if (nbb.randNum[row - 1] == nbb.randNum[row])
        {
            continue;
        }
        else
        {
            if (row == 2)
            {
                break;
            }
            row++;
        }
    }
}

int nRound(NumberBB* nbb)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (row == col && nbb->randNum[row] == nbb->inputNum[col])
            {
                nbb->strike++;
            }
            else if (row != col && nbb->randNum[row] == nbb->inputNum[col])
            {
                nbb->ball++;
            }

        }
    }
    if (nbb->strike == 3)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
