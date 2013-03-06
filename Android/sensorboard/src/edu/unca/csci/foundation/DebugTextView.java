/**
 * 
 */
package edu.unca.csci.foundation;

import android.content.Context;
import android.util.AttributeSet;
import android.view.View;
import android.widget.TextView;

/**
 * @author nick
 *
 */
public class DebugTextView extends TextView {

	/**
	 * @param context
	 */
	public DebugTextView(Context context) {
		super(context);
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param context
	 * @param attrs
	 */
	public DebugTextView(Context context, AttributeSet attrs) {
		super(context, attrs);
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param context
	 * @param attrs
	 * @param defStyle
	 */
	public DebugTextView(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		// TODO Auto-generated constructor stub
	}
	public void debugAppend(CharSequence c){
		String linebreak = String.valueOf('\n');
		this.append(linebreak + c);
		scrollToBottom();
	}
	private void scrollToBottom(){
		//Implement internal class-based scroll down of debugtextview
		//get the height of the view and go down
		System.out.println("hey");
	}

}
