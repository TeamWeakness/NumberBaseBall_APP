package com.weakness.numberbaseball;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;

import java.util.Random;

public class HelperActivity extends AppCompatActivity {

    Button helper_backBtn ;
    Button helper_helpBtn;
    Intent helper_resultIntent;
    TableLayout helper_tableLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_helper);

        Random random = new Random();
        random.setSeed(System.currentTimeMillis());


        helper_backBtn = findViewById(R.id.helper_btn_backBtn);
        helper_backBtn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                helper_resultIntent = new Intent();
                helper_resultIntent.putExtra("helper_back","helper에서 왔어요");
                setResult(RESULT_OK,helper_resultIntent);
                finish();
            }
        });

        helper_helpBtn = findViewById(R.id.helper_btn_hintBtn);
        helper_helpBtn.setOnClickListener(new View.OnClickListener(){
            @RequiresApi(api = Build.VERSION_CODES.LOLLIPOP)
            @Override
            public void onClick(View view) {
                helper_tableLayout = findViewById(R.id.helper_tableL_hintTableL);
                helper_tableLayout.setStretchAllColumns(true); // 축소 기능으로 자식 뷰의 개수 또는 크기가 넓어져서 부모의 크기를 넘어서도 각각 자식들의 열너비를 줄여 부모의 전체 크기를 채우도록 하는 속성
                helper_tableLayout.setShrinkAllColumns(true); // 확장 기능으로 자식 뷰의 개수 또는 크기가 작아서 부모의 크기에 못미치더라도 각각의 자식들의 열너비를 늘여 부모의 전체 크기를 채우도록 하는 속성
                TableRow tableRow = new TableRow(HelperActivity.this);
                tableRow.setLayoutParams(new TableRow.LayoutParams(
                        ViewGroup.LayoutParams.WRAP_CONTENT,
                        ViewGroup.LayoutParams.WRAP_CONTENT));

                for(int i = 0 ; i < 10; i++)
                {
                    TextView textView = new TextView(HelperActivity.this);
                    textView.setText(String.valueOf(random.nextInt(899)+100)); // 테스트 값
                    textView.setGravity(Gravity.CENTER);
                    textView.setPadding(15,10,15,10);
                    textView.setBackground(getDrawable(R.drawable.hint_textview_background));
                    tableRow.addView(textView);

                }
                helper_tableLayout.addView(tableRow);
            }
        });


    }


}

// putExtra(key,value) 첫번째 전달인자는 key값이고 두번째 전달인자는 보내줄 값이다. 그럼 받는 쪽에서는 getExtra(key,value)로 key를 입력하면
// https://profecessorleejaeman.tistory.com/entry/%EC%9E%90%EB%B0%94%EC%97%90%EC%84%9C-C-%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC-%ED%95%A8%EC%88%98-%ED%98%B8%EC%B6%9C%ED%95%98%EA%B8%B0