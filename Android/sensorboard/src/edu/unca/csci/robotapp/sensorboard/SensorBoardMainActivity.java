package edu.unca.csci.robotapp.sensorboard;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.app.Activity;
import android.content.Context;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ToggleButton;
import edu.unca.csci.foundation.DebugTextView;

public class SensorBoardMainActivity extends Activity implements SensorEventListener {
	public final String reset = "Reset";
	protected void onCreate(Bundle savedInstanceState) {
		
	
		
		
		setContentView(R.layout.activity_sensor_board_main);
		final SensorEventListener sel = this;
		super.onCreate(savedInstanceState);
		final DebugTextView dbg = (DebugTextView) findViewById(R.id.debugTextView1);
		final ToggleButton toggler = (ToggleButton) findViewById(R.id.toggleButton1);
		
		final SensorManager msense = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
		final Sensor accelerometer = msense.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
		
		//now perform application logic
		toggler.setOnClickListener(new OnClickListener(){
			public void onClick(View v){
				boolean checked = toggler.isChecked();
				if(checked){
					msense.registerListener(sel, accelerometer, Sensor.TYPE_ACCELEROMETER);
				}else{
					//turn it off
					msense.unregisterListener(sel);
				}
			}
		});
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.sensor_board_main, menu);
			
		menu.add(reset);
		return true;
	}
	public boolean onOptionsItemSelected (MenuItem mi){
		if(mi.getTitle() == reset){
			DebugTextView dbg = (DebugTextView) findViewById(R.id.debugTextView1);
			dbg.setText("");

		}
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
		DebugTextView dbg = (DebugTextView) findViewById(R.id.debugTextView1);
		float accelX, accelY, accelZ;
		accelX = event.values[0];
		accelY = event.values[1];
		accelZ = event.values[2];
		dbg.debugAppend("!!NEW ACCELEROMETER VALUES!!"+'\n'+"X:"+accelX+'\n'+"Y:"+accelY+'\n'+"Z:"+accelZ);
		
		
	}

}
