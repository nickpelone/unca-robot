package edu.unca.csci.robotapp;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.JavaCameraView;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.core.Mat;

import android.hardware.Camera;
import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SurfaceView;
import android.view.WindowManager;

public class OpenCVCameraActivity extends Activity {
	private CameraBridgeViewBase mOpenCvCameraView;
    private boolean              mIsJavaCamera = true;
    private MenuItem             mItemSwitchCamera = null;

    private BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(int status) {
            switch (status) {
                case LoaderCallbackInterface.SUCCESS:
                {
                    mOpenCvCameraView.enableView();
                } break;
                default:
                {
                    super.onManagerConnected(status);
                } break;
            }
        }
    };
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		//keep the screen on during camera
		getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
		
		setContentView(R.layout.activity_open_cvcamera);
		if(mIsJavaCamera){
			mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.tutorial1_activity_java_surface_view);
			mOpenCvCameraView.setVisibility(SurfaceView.VISIBLE);
			CameraBridgeViewBase jcam = new JavaCameraView(this, Camera.CameraInfo.CAMERA_FACING_BACK);
			CameraBridgeViewBase.CvCameraViewListener listen = new CameraBridgeViewBase.CvCameraViewListener() {
				@Override
				public void onCameraViewStopped() {
					// TODO Auto-generated method stub
					
				}
				
				@Override
				public void onCameraViewStarted(int width, int height) {
					mOpenCvCameraView.setVisibility(SurfaceView.VISIBLE);
					mOpenCvCameraView.setCvCameraViewListener(this);
				}
				
				@Override
				public Mat onCameraFrame(Mat inputFrame) {
					// TODO Auto-generated method stub
					return null;
				}
			};
			
		}
	
		
	}

}
