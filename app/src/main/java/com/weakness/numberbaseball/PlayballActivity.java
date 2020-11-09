package com.weakness.numberbaseball;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class PlayballActivity extends AppCompatActivity {
    Intent playball_resultIntent;
    Button playball_backBtn;

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
}