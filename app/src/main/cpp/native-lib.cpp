//
// Created by Administrator on 2020-11-09.
//


//*  1. 랜덤난수 생성해서 사용자가 입력한 3자리 숫자(중복불가)를 랜덤난수와 비교하여 숫자만 맞으면 ball 숫자와 위치가 맞으면 strike 출력 최종적으로 3strike가 되면 게임 종료
//    2. 위 프로그램을 사용하면 입력한 숫자와 비교하여 나온 ball과 strike 그리고 입력한 3자리 숫자를 입력하면 모든 경우의 수를 출력 */
//
//#include"myHeader.h"
//
//typedef struct numberBB_info
//{
//    //int viewNumAry[9][10][10]; // 언젠가 필요할까?
//    int viewNum[999];
//    /*int fisrtNum[9];
//    int secondNum[10];
//    int thirdNum[10];*/
//    int randNum[3];
//    int inputNum[3];
//    int strike;
//    int ball;
//
//}NumberBB;
//
//int dataInit(NumberBB* nbb);
//void initDataPrint(NumberBB nbb);
//int numberInput(NumberBB* nbb);
//int playBall(NumberBB* nbb);
//int nRound(NumberBB* nbb);
//int hintAlg(NumberBB* nbb);
//int hintPrint(NumberBB nbb);
//
//int main(int argc, char* argv[])
//{
//    NumberBB nbb = { 0, };
//
//    dataInit(&nbb);
//    playBall(&nbb);
//
//    return 0;
//
//}
//int dataInit(NumberBB* nbb)
//{
//    // 뷰 값(100~999)로 초기화 [999]
//    for (int row = 0; row < 999; row++)
//    {
//        nbb->viewNum[row] = row + 1;
//
//        if (nbb->viewNum[row] < 100) // 배열에 100 이하의 정수를 가진 값을 -1로 초기화
//        {
//            nbb->viewNum[row] = -1;
//        }
//        else if (nbb->viewNum[row] / 100 == nbb->viewNum[row] % 100 / 10) // 100의 자리 수와 10의 자리 수가 같은 숫자라면 -1로 초기화
//        {
//            nbb->viewNum[row] = -1;
//        }
//        else if(nbb->viewNum[row] / 100 == nbb->viewNum[row] % 100 % 10) // 100의 자리 수와 1의 자리 수가 같은 숫자라면 -1로 초기화
//        {
//            nbb->viewNum[row] = -1;
//        }
//        else if(nbb->viewNum[row] % 100 / 10 == nbb->viewNum[row] % 100 % 10) // 10의 자리 수와 1의 자리 수가 같은 숫자라면 -1로 초기화
//        {
//            nbb->viewNum[row] = -1;
//        }
//    }
//
//    // 뷰 값(100~999)로 초기화 [9][10][10](언젠가 필요할까?)
//    /*for (int hundredsP = 0; hundredsP < 9; hundredsP++)
//    {
//        for (int tensP = 0; tensP < 10; tensP++)
//        {
//            for (int onesP = 0; onesP < 10; onesP++)
//            {
//                nbb->viewNumAry[hundredsP][tensP][onesP] = ((hundredsP + 1) * 100) + (tensP * 10) + onesP;
//            }
//        }
//    }*/
//
//    // 뷰 값(100~999)로 초기화 [9],[10],[10]
//    /*for (int row = 0;row < 10;row++)
//    {
//        if (row != 9)
//        {
//            nbb->fisrtNum[row] = row + 1;
//        }
//        nbb->secondNum[row] = row;
//        nbb->thirdNum[row] = row;
//    }*/
//
//    // 랜덤 값 초기화
//    /*srand((unsigned int)time(NULL));
//    nbb->randNum[0] = rand() % 9 + 1;
//    for (int row = 1; row < 3; row++)
//    {
//        nbb->randNum[row] = rand() % 9;
//    }*/
//    nbb->randNum[0] = 3;
//    nbb->randNum[1] = 5;
//    nbb->randNum[2] = 6;
//    return 0;
//}
//int numberInput(NumberBB* nbb)
//{
//    int dis = 0;
//    while (1)
//    {
//        dis = inputInt_s("중복되지 않는 3자리 숫자를 입력하세요 (123 ~ 987) : ");
//        if (dis < 100 || dis > 999)
//        {
//            printf("중복되지 않는 123 ~ 987 사이의 숫자만 입력하라고!!!!!!!\n");
//            continue;
//        }
//        else
//        {
//            nbb->inputNum[0] = (int)floor(dis / 100);
//            dis %= 100;
//            nbb->inputNum[1] = (int)floor(dis / 10);
//            dis %= 10;
//            nbb->inputNum[2] = dis;
//            if (nbb->inputNum[0] == nbb->inputNum[1] || nbb->inputNum[0] == nbb->inputNum[2] || nbb->inputNum[1] == nbb->inputNum[2])
//            {
//                printf("중복된 숫자는 입력이 불가능합니다.\n");
//                continue;
//            }
//            break;
//        }
//    }
//    return 0;
//}
//void initDataPrint(NumberBB nbb)
//{
//    int cnt = 0;
//    // 뷰 값 출력 [999]
//    //for (int row = 0; row < 999; row++)
//    //{
//    //    /*if (row != 0 && row % 10 == 0)
//    //    {
//    //        printf("\n");
//    //    }*/
//    //    if (nbb.viewNum[row] != -1)
//    //    {
//    //        printf("%5d", nbb.viewNum[row]);
//    //        cnt++;
//    //        if (cnt % 20 == 0)
//    //        {
//    //            printf("\n");
//    //        }
//    //    }
//    //}
//    //printf("\n");
//
//    // 뷰 값 출력 [9][10][10] (언젠가 필요할까?)
//    /*for (int hundredsP = 0; hundredsP < 9; hundredsP++)
//    {
//        for (int tensP = 0; tensP < 10; tensP++)
//        {
//            for (int onesP = 0; onesP < 10; onesP++)
//            {
//                printf("viewNumAry[%d][%d][%d] : %d\n", hundredsP, tensP, onesP, nbb.viewNumAry[hundredsP][tensP][onesP]);
//            }
//        }
//    }*/
//
//    // 뷰 값 출력 [9],[10],[10]
//    /*for (int row = 0; row < 10; row++)
//    {
//        if (row != 9)
//        {
//            printf("firstNum[%d] : %d\t",row,nbb.fisrtNum[row]);
//        }
//        else
//        {
//            printf("\t\t");
//        }
//        printf("secondNum[%d] : %d\tthirdNum[%d] : %d\n", row, nbb.secondNum[row],row,nbb.thirdNum[row]);
//    }*/
//
//    // 랜덤 값 출력
//    printf("랜덤 값 : ");
//    for (int row = 0; row < 3; row++)
//    {
//        printf("%d", nbb.randNum[row]);
//    }
//    printf("\n");
//
//
//
//    // 입력 값 출력
//    printf("입력 값 : ");
//    for (int row = 0; row < 3; row++)
//    {
//        printf("%d", nbb.inputNum[row]);
//    }
//    printf("\n");
//
//    printf("strike : %d\tball : %d\n", nbb.strike, nbb.ball);
//
//}
//int playBall(NumberBB* nbb)
//{
//    int out = 0;
//    printf("============================= 게임을 시작합니다 =============================\n");
//    while (1)
//    {
//        nbb->strike = 0;
//        nbb->ball = 0;
//        if (out == 3)
//        {
//            printf("3strike!! 정답입니다!\n");
//            break;
//        }
//        numberInput(&(*nbb));
//        out = nRound(&(*nbb));
//        initDataPrint(*nbb);
//        hintAlg(&(*nbb));
//        hintPrint(*nbb);
//
//    }
//
//    return 0;
//}
//int nRound(NumberBB* nbb)
//{
//    for (int row = 0; row < 3; row++)
//    {
//        for (int col = 0; col < 3; col++)
//        {
//            if (row == col && nbb->randNum[row] == nbb->inputNum[col])
//            {
//                nbb->strike++;
//            }
//            else if (row != col && nbb->randNum[row] == nbb->inputNum[col])
//            {
//                nbb->ball++;
//            }
//
//        }
//    }
//    if (nbb->strike == 3)
//    {
//        return 3;
//    }
//    else
//    {
//        return 0;
//    }
//}
//int hintAlg(NumberBB* nbb)
//{
//    // 0스0볼은 out 그럼 그 숫자들은 제외 필요하다고 생각하는 정보는 (스트라이크, 볼, 입력한 값)
//    /* 123입력 0스트라이크 1볼일경우 100의 자리에 1이 나올 수 없고 10의 자리에는 2가 나올 수 없고 1의 자리에는 3이 나올 수 없다.  */
//    int temp[3];
//    int s = 0, b = 0;
//    for (int row = 0; row < 3; row++)
//    {
//        for (int col = 0; col < 999; col++)
//        {
//            temp[0] = nbb->viewNum[col] / 100; // 100의 자리
//            temp[1] = nbb->viewNum[col] % 100 / 10; // 10의 자리
//            temp[2] = nbb->viewNum[col] % 100 % 10; // 1의 자리
//            for (int hei = 0; hei < 3;hei++)
//            {
//
//                if (row == hei && nbb->inputNum[row] == temp[hei])
//                {
//                    s++;
//                    if (s == nbb->strike)
//                    {
//
//                    }
//                    else
//                    {
//                        nbb->viewNum[col] = -1;
//                    }
//                }
//                else if (row != hei && nbb->inputNum[row] == temp[hei])
//                {
//                    b++;
//                    if (b == nbb->ball)
//                    {
//
//                    }
//                    else
//                    {
//                        nbb->viewNum[col] = -1;
//                    }
//                }
//
//            }
//            s = 0;
//            b = 0;
//        }
//    }
//    return 0;
//}
//int hintPrint(NumberBB nbb)
//{
//    int cnt = 0;
//
//    // 뷰 값 출력 [999]
//    for (int row = 0; row < 999; row++)
//    {
//        /*if (row != 0 && row % 10 == 0)
//        {
//            printf("\n");
//        }*/
//        if (nbb.viewNum[row] != -1)
//        {
//            printf("%5d", nbb.viewNum[row]);
//            cnt++;
//            if (cnt % 20 == 0)
//            {
//                printf("\n");
//            }
//        }
//    }
//    printf("\n");
//
//    return 0;
//}
/*  1. 랜덤난수 생성해서 사용자가 입력한 3자리 숫자(중복불가)를 랜덤난수와 비교하여 숫자만 맞으면 ball 숫자와 위치가 맞으면 strike 출력 최종적으로 3strike가 되면 게임 종료
    2. 위 프로그램을 사용하여 나온 ball, strike, 입력한 3자리 숫자로 경우의 수 출력  */
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
int numberInput(NumberBB* nbb);
int playBall(NumberBB* nbb);
int nRound(NumberBB* nbb);
int hintAlg(NumberBB* nbb);
int hintPrint(NumberBB nbb);

extern "C" JNIEXPORT jstring JNICALL


Java_com_weakness_numberbaseball_MainActivity_main(JNIEnv* env,jobject /* this */)
{
    return env->NewStringUTF("이렇게 하는건가??");
}


int main(int argc, char* argv[])
{
    NumberBB nbb = { 0, };

    dataInit(&nbb);
    playBall(&nbb);

    return 0;

}
int dataInit(NumberBB* nbb)
{
    int firstNum;
    int secondNum;
    int thirdNum;
    // 뷰 값(100~999)로 초기화 [999]
    for (int row = 0; row < 999; row++)
    {
        nbb->viewNum[row] = row + 1; // 초기 값 넣기

        firstNum = nbb->viewNum[row] / 100; // 100의 자리숫자 넣기
        secondNum = nbb->viewNum[row] % 100 / 10; // 10의 자리 숫자 넣기
        thirdNum = nbb->viewNum[row] % 100 % 10; // 1의 자리 숫자 넣기

        if (nbb->viewNum[row] < 100) // 배열에 100 이하의 정수를 가진 값을 -1로 초기화
        {
            nbb->viewNum[row] = -1;
        }
        else if (firstNum == secondNum) // 100의 자리 수와 10의 자리 수가 같은 숫자라면 -1로 초기화
        {
            nbb->viewNum[row] = -1;
        }
        else if (firstNum == thirdNum) // 100의 자리 수와 1의 자리 수가 같은 숫자라면 -1로 초기화
        {
            nbb->viewNum[row] = -1;
        }
        else if (secondNum == thirdNum) // 10의 자리 수와 1의 자리 수가 같은 숫자라면 -1로 초기화
        {
            nbb->viewNum[row] = -1;
        }
        //printf("%d\n", nbb->viewNum[row]);
    }

    // 뷰 값(100~999)로 초기화 [9][10][10](언젠가 필요할까?)
    /*for (int hundredsP = 0; hundredsP < 9; hundredsP++)
    {
        for (int tensP = 0; tensP < 10; tensP++)
        {
            for (int onesP = 0; onesP < 10; onesP++)
            {
                nbb->viewNumAry[hundredsP][tensP][onesP] = ((hundredsP + 1) * 100) + (tensP * 10) + onesP;
            }
        }
    }*/

    // 뷰 값(100~999)로 초기화 [9],[10],[10]
    /*for (int row = 0;row < 10;row++)
    {
        if (row != 9)
        {
            nbb->fisrtNum[row] = row + 1;
        }
        nbb->secondNum[row] = row;
        nbb->thirdNum[row] = row;
    }*/

    // 랜덤 값 초기화

    int row = 1;
    srand((unsigned int)time(NULL));
    nbb->randNum[0] = rand() % 9 + 1;
    while(1)
    {
        nbb->randNum[row] = rand() % 9;
        if (nbb->randNum[row - 1] == nbb->randNum[row])
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
    /*nbb->randNum[0] = 3;
    nbb->randNum[1] = 5;
    nbb->randNum[2] = 6;*/
    return 0;
}
int numberInput(NumberBB* nbb)
{
    int dis = 0;
    while (1)
    {
        dis = inputInt_s("중복되지 않는 3자리 숫자를 입력하세요 (123 ~ 987) : ");
        if (dis < 100 || dis > 999)
        {
            printf("중복되지 않는 123 ~ 987 사이의 숫자만 입력하세요.\n");
            continue;
        }
        else
        {
            nbb->inputNum[0] = dis / 100;
            nbb->inputNum[1] = dis % 100 / 10;
            nbb->inputNum[2] = dis % 100 % 10;
            if (nbb->inputNum[0] == nbb->inputNum[1] || nbb->inputNum[0] == nbb->inputNum[2] || nbb->inputNum[1] == nbb->inputNum[2])
            {
                printf("중복된 숫자는 입력이 불가능합니다.\n");
                continue;
            }
            break;
        }
    }
    return 0;
}
void initDataPrint(NumberBB nbb)
{
    int cnt = 0;
    // 뷰 값 출력 [999]
    /*for (int row = 0; row < 999; row++)
    {
        //if (row != 0 && row % 10 == 0)
        //{
        //    printf("\n");
        //}
        if (nbb.viewNum[row] != -1)
        {
            printf("%5d", nbb.viewNum[row]);
            cnt++;
            if (cnt % 20 == 0)
            {
                printf("\n");
            }
        }
    }
    printf("\n");*/

    // 뷰 값 출력 [9][10][10] (언젠가 필요할까?)
    /*for (int hundredsP = 0; hundredsP < 9; hundredsP++)
    {
        for (int tensP = 0; tensP < 10; tensP++)
        {
            for (int onesP = 0; onesP < 10; onesP++)
            {
                printf("viewNumAry[%d][%d][%d] : %d\n", hundredsP, tensP, onesP, nbb.viewNumAry[hundredsP][tensP][onesP]);
            }
        }
    }*/

    // 뷰 값 출력 [9],[10],[10]
    /*for (int row = 0; row < 10; row++)
    {
        if (row != 9)
        {
            printf("firstNum[%d] : %d\t",row,nbb.fisrtNum[row]);
        }
        else
        {
            printf("\t\t");
        }
        printf("secondNum[%d] : %d\tthirdNum[%d] : %d\n", row, nbb.secondNum[row],row,nbb.thirdNum[row]);
    }*/

    // 랜덤 값 출력
    printf("랜덤 값 : ");
    for (int row = 0; row < 3; row++)
    {
        printf("%d", nbb.randNum[row]);
    }
    printf("\n");



    // 입력 값 출력
    printf("입력 값 : ");
    for (int row = 0; row < 3; row++)
    {
        printf("%d", nbb.inputNum[row]);
    }
    printf("\n");

    printf("strike : %d\tball : %d\n", nbb.strike, nbb.ball);

}
int playBall(NumberBB* nbb)
{
    int out = 0;
    printf("============================= 게임을 시작합니다 =============================\n");
    while (1)
    {
        nbb->strike = 0;
        nbb->ball = 0;
        if (out == 3)
        {
            printf("3strike!! 정답입니다!\n");
            break;
        }
        numberInput(nbb);
        out = nRound(nbb);
        initDataPrint(*nbb);
        hintAlg(nbb);
        hintPrint(*nbb);

    }

    return 0;
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
int hintAlg(NumberBB* nbb)
{
    /* 0스0볼은 out 그럼 그 숫자들은 제외 필요하다고 생각하는 정보는 (스트라이크, 볼, 입력한 값)
     123입력 0스트라이크 1볼일경우 100의 자리에 1이 나올 수 없고 10의 자리에는 2가 나올 수 없고 1의 자리에는 3이 나올 수 없다.  */
    int temp[3];
    int strike = 0, ball = 0;

    for (int col = 0; col < 999; col++) // 출력해줄 값들을 돌릴 viewNum배열에서 하나씩 받아와 자리에 temp배열에 자릿수 별로 나눠 저장한다.
    {
        temp[0] = nbb->viewNum[col] / 100; // 100의 자리
        temp[1] = nbb->viewNum[col] % 100 / 10; // 10의 자리
        temp[2] = nbb->viewNum[col] % 100 % 10; // 1의 자리
        for (int row = 0; row < 3; row++) // inputNum배열을 row변수로 컨트롤 하기위한 for문
        {
            for (int hei = 0; hei < 3;hei++) // temp배열을 hei변수로 컨트롤 하기위한 for문
            {
                if (row == hei && nbb->inputNum[row] == temp[hei]) // inputNum와 temp의 방번호와 값이 같다면
                {
                    strike++;
                }
                else if (row != hei && nbb->inputNum[row] == temp[hei]) // inputNum와 temp의 방번호가 같지 않고 값은 같다면
                {
                    ball++;
                }
            }
        }
        /* 입력한 값과 랜덤값 결과의 strike와 ball을 입력한 값과 출력값 결과의 strike와 ball이 같지 않다면 해당 viewNum의 col번방에 viewNum값을 -1로 초기화
        즉.. */
        if (strike != nbb->strike || ball != nbb->ball)
        {
            nbb->viewNum[col] = -1;
        }
        strike = 0;
        ball = 0;
    }
    return 0;
}
int hintPrint(NumberBB nbb)
{
    int cnt = 0;

    // 뷰 값 출력 [999]
    for (int row = 0; row < 999; row++)
    {
        /*if (row != 0 && row % 10 == 0)
        {
            printf("\n");
        }*/
        if (nbb.viewNum[row] != -1)
        {
            printf("%5d", nbb.viewNum[row]);
            cnt++;
            if (cnt % 20 == 0)
            {
                printf("\n");
            }
        }
    }
    printf("\n");

    return 0;
}
