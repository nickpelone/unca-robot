package edu.unca.csci.robotapp;

import edu.unca.csci.foundation.DebugTextView;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.app.Activity;
import android.content.Context;
import android.view.Menu;
import android.widget.ScrollView;

public class CompassActivity extends Activity implements SensorEventListener {
 
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_compass);
		//
		final SensorEventListener sel = this;
		final ScrollView scroller = (ScrollView) findViewById(R.id.compassScrollView1);
		final SensorManager compassSensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
		final Sensor compass = compassSensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD);
		final DebugTextView dbg = (DebugTextView) findViewById(R.id.compassDebugTextView1);
		compassSensorManager.registerListener(sel, compass, SensorManager.SENSOR_DELAY_NORMAL);
		dbg.setText("No compass data yet");
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
		DebugTextView dbg1 = (DebugTextView) findViewById(R.id.compassDebugTextView1);
		// TODO Auto-generated method stub
		//when the sensor gets new values different from old ones this code is executed
		//dbg1.debugAppend(""+ arg0.values[0]);
		float x, y, z;
		x = arg0.values[0];
		y = arg0.values[1];
		z = arg0.values[2];
		dbg1.setText("Degrees from Magnetic North (+ or - 180 scale): " + x);
	}
		
	}


