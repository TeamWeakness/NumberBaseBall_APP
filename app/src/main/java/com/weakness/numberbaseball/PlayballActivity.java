package com.weakness.numberbaseball;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;
import java.util.Random;

public class PlayballActivity extends AppCompatActivity implements TextView.OnEditorActionListener {
    Intent playball_resultIntent;
    Button playball_backBtn;
    Button playball_submitBtn;
    Button playball_hintBtn;
    EditText playball_inputNum;
    TextView playball_resStrike;
    TextView playball_resBall;
    TableLayout playball_tableL_hintTableL;
    TableLayout playball_tableL_historyTableL;
    public int inputNum;
    public int[] inputRes;
    public int[] hintRes;
    public int firstNum;
    public int secondNum;
    public int thirdNum;

    InputMethodManager keyManager;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("numberBaseball-lib");
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native static int dataInit();
    public native int[] playball(int firstNum, int secondNum, int thirdNum);
    public native int[] hint(int firstNum, int secondNum, int thirdNum, int strike, int ball);


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_playball);
        int testMessage;
        Random random = new Random();
        random.setSeed(System.currentTimeMillis());

        testMessage = dataInit();
        Log.i("확인용","이거 데이터 오니? : " + testMessage);
        inputRes = new int[2];
        hintRes = new int[999];

        playball_inputNum = findViewById(R.id.playball_et_inputNum);

        playball_resStrike = findViewById(R.id.playball_tv_resStrike);
        playball_resBall = findViewById(R.id.playball_tv_resBall);
        playball_tableL_hintTableL = findViewById(R.id.playball_tableL_hintTableL);
        playball_tableL_historyTableL = findViewById(R.id.playball_tableL_historyTableL);


        
        // 확인 버튼 클릭 리스너
        playball_submitBtn = findViewById(R.id.playball_btn_submitBtn);
        playball_submitBtn.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View view) {
                // 확인 버튼 클릭시 키보드를 내리기 위한 매니저
                keyManager = (InputMethodManager)getSystemService(INPUT_METHOD_SERVICE);
                keyManager.hideSoftInputFromWindow(getCurrentFocus().getWindowToken(), InputMethodManager.HIDE_NOT_ALWAYS);

                String getNull = playball_inputNum.getText().toString();
                if(getNull == null || getNull.equals(""))
                {
                    Toast.makeText(PlayballActivity.this, "값을 입력하세요.", Toast.LENGTH_SHORT).show();
                }
                else if(getNull.length() < 3)
                {
                    Toast.makeText(PlayballActivity.this, "3자리 숫자를 입력하세요.", Toast.LENGTH_SHORT).show();
                }
                else
                {
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
                        inputRes = playball(firstNum,secondNum,thirdNum);
                        //Log.i("확인용","이거 데이터 오니? : " + res[0] + "," + res[1]);
                        playball_resStrike.setText(String.valueOf(inputRes[0]));
                        playball_resBall.setText(String.valueOf(inputRes[1]));

                        // 입력할때마다 결과창에 등록
                        //playball_tableL_historyTableL.setStretchAllColumns(true);
                        //playball_tableL_historyTableL.setShrinkAllColumns(true);
                        TableRow res_talbeRow = new TableRow(PlayballActivity.this);
                        res_talbeRow.setLayoutParams(new TableRow.LayoutParams(
                                ViewGroup.LayoutParams.WRAP_CONTENT,
                                ViewGroup.LayoutParams.WRAP_CONTENT,1f));
                        res_talbeRow.setGravity(Gravity.CENTER);

                        TextView history_number = new TextView(PlayballActivity.this);
                        TextView history_result = new TextView(PlayballActivity.this);
                        history_number.setText("   " + playball_inputNum.getText().toString());
                        history_result.setText("          " + playball_resStrike.getText().toString() + "   " + playball_resBall.getText().toString());
                        history_number.setGravity(Gravity.CENTER);
                        history_result.setGravity(Gravity.CENTER);
                        //history_number.setPadding(15, 10, 15, 10);
                        //history_result.setPadding(15, 10, 15, 10);
                        res_talbeRow.addView(history_number);
                        res_talbeRow.addView(history_result);

                        playball_tableL_historyTableL.addView(res_talbeRow);
                    }
                }
                playball_inputNum.setText("");
            }
        });

        // 힌트받기 버튼 리스너
        playball_hintBtn = findViewById(R.id.playball_btn_hintBtn);
        playball_hintBtn.setOnClickListener(new View.OnClickListener() {
            @RequiresApi(api = Build.VERSION_CODES.LOLLIPOP)
            @Override
            public void onClick(View view) {

                // 헬퍼
                playball_tableL_hintTableL.setStretchAllColumns(true); // 축소 기능으로 자식 뷰의 개수 또는 크기가 넓어져서 부모의 크기를 넘어서도 각각 자식들의 열너비를 줄여 부모의 전체 크기를 채우도록 하는 속성
                playball_tableL_hintTableL.setShrinkAllColumns(true); // 확장 기능으로 자식 뷰의 개수 또는 크기가 작아서 부모의 크기에 못미치더라도 각각의 자식들의 열너비를 늘여 부모의 전체 크기를 채우도록 하는 속성
                TableRow tableRow = new TableRow(PlayballActivity.this);
                tableRow.setLayoutParams(new TableRow.LayoutParams(
                        ViewGroup.LayoutParams.WRAP_CONTENT,
                        ViewGroup.LayoutParams.WRAP_CONTENT));

                // 여기에 c라이브러리 호출후 배열의 방갯수만큼만 포문 돌려서 화면에 뿌려주기 ㄱㄱ
                playball_tableL_hintTableL.removeAllViewsInLayout();
                hintRes = hint(firstNum,secondNum,thirdNum,Integer.parseInt(playball_resStrike.getText().toString()),Integer.parseInt(playball_resBall.getText().toString()));

                int cnt = 0;

                for(int i = 0 ; i < 999; i++)
                {
                    if(hintRes[i] != -1)
                    {
                        TextView textView = new TextView(PlayballActivity.this);
                        //textView.setText(String.valueOf(random.nextInt(899)+100)); // 테스트 값
                        textView.setText(String.valueOf(hintRes[i]));
                        textView.setGravity(Gravity.CENTER);
                        textView.setPadding(15, 10, 15, 10);
                        textView.setBackground(getDrawable(R.drawable.hint_textview_background));
                        tableRow.addView(textView);
                        cnt++;
                    }
                    if(cnt % 10 == 0)
                    {
                        playball_tableL_hintTableL.addView(tableRow);
                        tableRow = new TableRow(PlayballActivity.this);
                        tableRow.setLayoutParams(new TableRow.LayoutParams(
                                ViewGroup.LayoutParams.WRAP_CONTENT,
                                ViewGroup.LayoutParams.WRAP_CONTENT));
                    }
                }
                playball_tableL_hintTableL.addView(tableRow);
                tableRow = new TableRow(PlayballActivity.this);
                tableRow.setLayoutParams(new TableRow.LayoutParams(
                        ViewGroup.LayoutParams.WRAP_CONTENT,
                        ViewGroup.LayoutParams.WRAP_CONTENT));

            }
        });

        // 돌아가기 버튼 리스너
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

    @Override
    public boolean onEditorAction(TextView textView, int i, KeyEvent keyEvent) {
        //Log.i("확인용","여기는 오고 오류나니?");
        return false;
    }
}
// 새 C/C++ 파일을 프로젝트에 추가한 후에 CMake를 구성하여 네이티브 라이브러리에 포함해야 한다. 이거 중요하다!!
// https://developer.android.com/studio/projects/configure-cmake?hl=ko