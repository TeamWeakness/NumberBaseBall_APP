package com.weakness.numberbaseball;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    final int CALLHELPER = 101;
    final int CALLPLAYBALL = 102;

    Button playball_bnt;
    Button helper_btn;
    Intent helperIntent;
    Intent playBallIntent;
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        playball_bnt = findViewById(R.id.main_bnt_playballbtn);
        playball_bnt.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                playBallIntent = new Intent(getApplicationContext(),PlayballActivity.class);
                startActivityForResult(playBallIntent,CALLPLAYBALL);
            }
        });

        helper_btn = findViewById(R.id.main_bnt_helperBtn);
        helper_btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                helperIntent = new Intent(getApplicationContext(),HelperActivity.class);
                startActivityForResult(helperIntent,CALLHELPER);
            }
        });
    }
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(resultCode == RESULT_OK)
        {
            switch (requestCode)
            {
                case CALLPLAYBALL:
                    Log.i("확인용",data.getExtras().getString("playball_back"));
                    break;
                case CALLHELPER:
                    Log.i("확인용",data.getExtras().getString("helper_back"));
                    break;
            }
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String main();
}



// https://maternalgrandfather.tistory.com/entry/this%EC%99%80-getApplicationContext%EC%9D%98-%EC%B0%A8%EC%9D%B4%EC%A0%90%EC%9D%80
// http://dev.youngkyu.kr/36
// 위 사이트는 Intent 클래스의 생성자의 첫번째 전달인자로 this와 getApplicationContext()의 차이점을 설명한 사이트이다. 나중에 참고하여 정리하도록 하자.