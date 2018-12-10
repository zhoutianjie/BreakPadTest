package com.kedacom.myapplication;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.ztj.breakpad.BreakPad;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        BreakPad.BreakPadInit(Environment.getExternalStorageDirectory().getAbsolutePath());

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                BreakPad.BreakPadTest();

            }
        });

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

}
