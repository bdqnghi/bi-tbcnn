package com.example.sabin.sabinwork_active.task;

import android.app.Activity;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.TextView;

import com.example.sabin.sabinwork_active.R;

/**
 * Created by sabin on 7/8/16.
 */
public class Bubblesort extends AsyncTask<Integer[],Integer,int[]> {

private Activity activity;
    private long start;
    private long stop;
    private TextView tvBubblesort;

    public Bubblesort(Activity activity) {
        this.activity = activity;
    }

    @Override
    protected int[] doInBackground(Integer[]... arrays1) {
        Log.i("sabin","bubb");

        Integer[]array = arrays1[0];

        Log.i("size", String.valueOf(array.length));


        start = System.currentTimeMillis();

        //int []array =t[0];

        int n = array.length;
        int temp = 0;

        for(int i=0; i < n; i++){
            for(int j=1; j < (n-i); j++){

                if(array[j-1] > array[j]){
                    //swap the elements!
                    temp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = temp;
                }

            }
        }

        return null;
    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();
        tvBubblesort=(TextView)activity.findViewById(R.id.tvbubble);

    }

    @Override
    protected void onPostExecute(int[] ints) {
        super.onPostExecute(ints);
        stop = System.currentTimeMillis();
        tvBubblesort.setText(stop - start + "ms");
    }


}
