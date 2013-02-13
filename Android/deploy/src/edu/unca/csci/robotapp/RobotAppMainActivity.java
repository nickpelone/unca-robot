package edu.unca.csci.robotapp;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.widget.TextView;

public class RobotAppMainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		TextView debugMessageArea = new TextView(this);
		super.onCreate(savedInstanceState);
		Button button = new Button(this);
		setContentView(R.layout.activity_robot_app_main);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_robot_app_main, menu);
		return true;
	}

}
