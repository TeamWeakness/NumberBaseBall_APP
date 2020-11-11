package com.weakness.numberbaseball;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class PlayballActivity extends AppCompatActivity {
    Intent playball_resultIntent;
    Button playball_backBtn;
    Button playball_checkBtn;
    EditText playball_inputNum;
    EditText playball_inputBall;
    EditText playball_inputStrike;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("playball");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_playball);

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
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    public native String main();
    public native String test();

}
// 새 C/C++ 파일을 프로젝트에 추가한 후에 CMake를 구성하여 네이티브 라이브러리에 포함해야 합니다. 이거 중요하다!!
// https://developer.android.com/studio/projects/configure-cmake?hl=ko