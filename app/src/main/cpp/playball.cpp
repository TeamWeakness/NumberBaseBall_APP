//
// Created by Administrator on 2020-11-10.
//

#include "myHeader.h"
typedef struct numberBB_info
{
    int viewNum[999];
    int randNum[3];
    int inputNum[3];
    int strike;
    int ball;

}NumberBB;

int nRound(NumberBB* nbb);

static NumberBB nbb = { 0, };


extern "C"
JNIEXPORT jint JNICALL
Java_com_weakness_numberbaseball_PlayballActivity_dataInit(JNIEnv* env,jclass )
{
    int firstNum;
    int secondNum;
    int thirdNum;
    // 뷰 값(100~999)로 초기화 [999]
    for (int row = 0; row < 999; row++) {
        nbb.viewNum[row] = row + 1; // 초기 값 넣기

        firstNum = nbb.viewNum[row] / 100; // 100의 자리숫자 넣기
        secondNum = nbb.viewNum[row] % 100 / 10; // 10의 자리 숫자 넣기
        thirdNum = nbb.viewNum[row] % 100 % 10; // 1의 자리 숫자 넣기

        if (nbb.viewNum[row] < 100) // 배열에 100 이하의 정수를 가진 값을 -1로 초기화
        {
            nbb.viewNum[row] = -1;
        } else if (firstNum == secondNum) // 100의 자리 수와 10의 자리 수가 같은 숫자라면 -1로 초기화
        {
            nbb.viewNum[row] = -1;
        } else if (firstNum == thirdNum) // 100의 자리 수와 1의 자리 수가 같은 숫자라면 -1로 초기화
        {
            nbb.viewNum[row] = -1;
        } else if (secondNum == thirdNum) // 10의 자리 수와 1의 자리 수가 같은 숫자라면 -1로 초기화
        {
            nbb.viewNum[row] = -1;
        }
    }
    // 랜덤 값 초기화
    srand((unsigned int)time(NULL));
    while (1)
    {
        nbb.randNum[0] = rand() % 9 + 1;
        nbb.randNum[1] = rand() % 10;
        nbb.randNum[2] = rand() % 10;
        if (nbb.randNum[0] != nbb.randNum[1] && nbb.randNum[0] != nbb.randNum[2] && nbb.randNum[1] != nbb.randNum[2])
        {
            break;
        }
    }
    return (jint)(nbb.randNum[0]*100 + nbb.randNum[1]*10 + nbb.randNum[2]);
}

extern "C"
JNIEXPORT jintArray JNICALL // 이건 메소드마다 추가 해줘야 하는건가?? 왜 메소드별로 없으면 오류가 날까..? 대충은 activity에서 c함수를 호출하때는 필요한 것 같다.
Java_com_weakness_numberbaseball_PlayballActivity_playball(JNIEnv* env,jobject /* this */ ,jint firstNum, jint secondNum, jint thirdNum)
{
    jintArray res;
    res = (*env).NewIntArray(2);
    int tempInt[2] = {0,};

    nbb.strike = 0;
    nbb.ball = 0;

    nbb.inputNum[0] = firstNum;
    nbb.inputNum[1] = secondNum;
    nbb.inputNum[2] = thirdNum;
    nRound(&nbb);
    tempInt[0] = nbb.strike;
    tempInt[1] = nbb.ball;
    env->SetIntArrayRegion(res,0,2,tempInt);

    return res;
}
extern "C"
JNIEXPORT jintArray JNICALL
Java_com_weakness_numberbaseball_PlayballActivity_hint(JNIEnv* env, jobject , jint firstNum, jint secondNum, jint thirdNum, jint resStrike, jint resBall)
{
    jintArray res;
    res = (*env).NewIntArray(999);
    /* 0스0볼은 out 그럼 그 숫자들은 제외 필요하다고 생각하는 정보는 (스트라이크, 볼, 입력한 값)
        123입력 0스트라이크 1볼일경우 100의 자리에 1이 나올 수 없고 10의 자리에는 2가 나올 수 없고 1의 자리에는 3이 나올 수 없다.  */
    int temp[3];
    int strike = 0, ball = 0;

    for (int col = 0; col < 999; col++) // 출력해줄 값들을 돌릴 viewNum배열에서 하나씩 받아와 자리에 temp배열에 자릿수 별로 나눠 저장한다.
    {
        temp[0] = nbb.viewNum[col] / 100; // 100의 자리
        temp[1] = nbb.viewNum[col] % 100 / 10; // 10의 자리
        temp[2] = nbb.viewNum[col] % 100 % 10; // 1의 자리
        for (int row = 0; row < 3; row++) // inputNum배열을 row변수로 컨트롤 하기위한 for문
        {
            for (int hei = 0; hei < 3;hei++) // temp배열을 hei변수로 컨트롤 하기위한 for문
            {
                if (row == hei && nbb.inputNum[row] == temp[hei]) // inputNum와 temp의 방번호와 값이 같다면
                {
                    strike++;
                }
                else if (row != hei && nbb.inputNum[row] == temp[hei]) // inputNum와 temp의 방번호가 같지 않고 값은 같다면
                {
                    ball++;
                }
            }
        }
        /* 입력한 값과 랜덤값 결과의 strike와 ball을 입력한 값과 출력값 결과의 strike와 ball이 같지 않다면 해당 viewNum의 col번방에 viewNum값을 -1로 초기화
        즉.. */
        if (strike != resStrike || ball != resBall)
        {
            nbb.viewNum[col] = -1;
        }
        strike = 0;
        ball = 0;
    }

    env->SetIntArrayRegion(res,0,999,nbb.viewNum);
    return res;
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