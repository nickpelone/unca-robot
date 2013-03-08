package edu.unca.csci.robotapp;

import edu.unca.csci.foundation.DebugTextView;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.widget.ScrollView;

public class CompassActivity extends Activity implements SensorEventListener {
	private final SensorEventListener sel = this;
	private final DebugTextView dbg = (DebugTextView) findViewById(R.id.compassDebugTextView1);
	private final ScrollView scroller = (ScrollView) findViewById(R.id.compassScrollView1);
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_compass);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.compass, menu);
		return true;
	}

	@Override
	public void onAccuracyChanged(Sensor arg0, int arg1) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onSensorChanged(SensorEvent arg0) {
		// TODO Auto-generated method stub
		//when the sensor gets new values different from old ones this code is executed
		
	}

}
