package edu.unca.csci.robot.compass;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.app.Activity;
import android.content.Context;
import android.view.Menu;
import android.widget.TextView;

public class RobotCompass extends Activity implements SensorEventListener{

	private static final int MATRIX_SIZE = 0;
	//private float[] mGravity;
    //private float[] mMagnetic;
	private float[] magnetic_field_values;
	private float[] accelerometer_values;
    
    
    
   
   
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_robot_compass);
		final SensorEventListener sel = this;
		final SensorManager msense = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
		final Sensor accelerometer = msense.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
		final Sensor compass = msense.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD);
		msense.registerListener(sel, accelerometer, SensorManager.SENSOR_DELAY_NORMAL);
		msense.registerListener(sel, compass, SensorManager.SENSOR_DELAY_NORMAL);
	}
	public void onSensorChanged(SensorEvent event) {
		TextView tv = (TextView) findViewById(R.id.textView1);
		   switch (event.sensor.getType()) {
		   case Sensor.TYPE_MAGNETIC_FIELD:
		      this.magnetic_field_values = event.values.clone();
		      break;
		   case Sensor.TYPE_ACCELEROMETER:
		      this.accelerometer_values = event.values.clone();
		      break;
		   }

		   if (this.magnetic_field_values != null && this.accelerometer_values != null) {
		      float[] R = new float[9];

		      if (SensorManager.getRotationMatrix(R, null, this.accelerometer_values, this.magnetic_field_values)) {
		         float[] actual_orientation = new float[3];
		         SensorManager.getOrientation(R, actual_orientation);

		         float direction = (float) Math.toDegrees(actual_orientation[0]);
		         tv.setText(Float.toString(direction));
		         
		      }
		   }
		}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.robot_compass, menu);
		return true;
	}
	@Override
	public void onAccuracyChanged(Sensor arg0, int arg1) {
		// TODO Auto-generated method stub
		
	}
}