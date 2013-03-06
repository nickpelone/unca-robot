package edu.unca.csci.robotapp.sensorboard;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.app.Activity;
import android.content.Context;
import android.view.Menu;

public class SensorBoardMainActivity extends Activity implements SensorEventListener {
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		SensorManager msense = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
		Sensor accelerometer = msense.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
		msense.registerListener(this, accelerometer, SensorManager.SENSOR_DELAY_FASTEST);
		setContentView(R.layout.activity_sensor_board_main);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.sensor_board_main, menu);
		return true;
	}

	@Override
	public void onAccuracyChanged(Sensor arg0, int arg1) {
		// TODO Auto-generated method stub
		//nothing happens here
		
	}

	@Override
	public void onSensorChanged(SensorEvent event) {
		// TODO Auto-generated method stub
		float accelX, accelY, accelZ;
		accelX = event.values[0];
		accelY = event.values[1];
		accelZ = event.values[2];
		
	}

}
