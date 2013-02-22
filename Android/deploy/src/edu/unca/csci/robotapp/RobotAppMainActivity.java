package edu.unca.csci.robotapp;

import android.os.Bundle;
import android.app.Activity;
import android.text.method.ScrollingMovementMethod;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;
import edu.unca.csci.robotapp.DebugTextView;

public class RobotAppMainActivity extends Activity {
	private Button theButton;
	private DebugTextView theText;
	private ToggleButton toggableButton;
	private ScrollView scrollControl;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_robot_app_main);
		theButton = (Button) findViewById(R.id.exampleButton);
		theText = (DebugTextView) findViewById(R.id.debugTextView1);
		toggableButton = (ToggleButton)findViewById(R.id.toggleButton1);
		scrollControl = (ScrollView) findViewById(R.id.scrollView1);
		 final String returnable = "hello";
		 theText.setMovementMethod(new ScrollingMovementMethod());
		
		theButton.setOnClickListener(new OnClickListener(){
			public void onClick(View v){
				theText.debugAppend(returnable);
				scrollControl.fullScroll(View.FOCUS_DOWN);
				
			}
		
		});
		
		toggableButton.setOnClickListener(new OnClickListener(){
			public void onClick(View v){
				boolean checked = toggableButton.isChecked();
				if(checked){
					theText.debugAppend("the button is on");
					scrollControl.fullScroll(View.FOCUS_DOWN);
				}else {
					theText.debugAppend("the button is off");
					scrollControl.fullScroll(View.FOCUS_DOWN);
				}
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
