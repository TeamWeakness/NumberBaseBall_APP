package com.weakness.numberbaseball;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class PlayballActivity extends AppCompatActivity {
    Intent playball_resultIntent;
    Button playball_backBtn;
    Button playball_submitBtn;
    EditText playball_inputNum;
    TextView playball_resStrike;
    TextView playball_resBall;
    public int inputNum;
    public int inputStrike;
    public int inputBall;
    public int[] res;
    public int firstNum;
    public int secondNum;
    public int thirdNum;
    public int callCnt;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("numberBaseball-lib");
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native int main(int inputNum,int firstNum, int secondNum, int thirdNum);
    public native static void dataInit();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_playball);

        res = new int[2];

        playball_inputNum = findViewById(R.id.playball_et_inputNum);

        playball_submitBtn = findViewById(R.id.playball_btn_submitBtn);
        playball_submitBtn.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View view) {

                inputNum = Integer.parseInt(playball_inputNum.getText().toString());
                firstNum = inputNum / 100;
                secondNum = inputNum % 100 / 10;
                thirdNum = inputNum % 100 % 10;
                if(firstNum == secondNum || secondNum == thirdNum || firstNum == thirdNum)
                {
                    Toast.makeText(PlayballActivity.this,"중복된 숫자는 입력할 수 없습니다.",Toast.LENGTH_SHORT).show();
                }
                else
                {
                    res = main(inputNum,firstNum,secondNum,thirdNum);
                    //Log.i("확인용","이거 데이터 오니? : " + res);

                }
            }
        });

        playball_backBtn = findViewById(R.id.playball_btn_backBtn);
        playball_backBtn.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {

                playball_resultIntent = new Intent();
                playball_resultIntent.putExtra("playball_back","playball에서 왔어요");
                setResult(RESULT_OK,playball_resultIntent);

                finish();
            }
        });
    }

}
// 새 C/C++ 파일을 프로젝트에 추가한 후에 CMake를 구성하여 네이티브 라이브러리에 포함해야 합니다. 이거 중요하다!!
// https://developer.android.com/studio/projects/configure-cmake?hl=ko