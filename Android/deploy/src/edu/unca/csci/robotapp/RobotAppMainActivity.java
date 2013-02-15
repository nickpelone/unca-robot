package edu.unca.csci.robotapp;

import android.os.Bundle;
import android.app.Activity;
import android.text.method.ScrollingMovementMethod;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;

public class RobotAppMainActivity extends Activity {
	private Button theButton;
	private TextView theText;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_robot_app_main);
		theButton = (Button) findViewById(R.id.exampleButton);
		theText = (TextView) findViewById(R.id.exampleText);
		 final String returnable = "hello";
		 theText.setMovementMethod(new ScrollingMovementMethod());
		
		theButton.setOnClickListener(new OnClickListener(){
			public void onClick(View v){
				theText.append('\n' + returnable);
				
				
			}
		});
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_robot_app_main, menu);
		return true;
	}

}
