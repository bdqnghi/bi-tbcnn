package com.envision_lightning.big_o;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.text.Html;
import android.text.method.LinkMovementMethod;
import android.view.MenuItem;
import android.widget.TextView;

/**
 * Created by oscar on 1/9/2017.
 */

public class linkedlist extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(com.envision_lightning.big_o.R.layout.linkedlists);

        TextView linked_list =(TextView)findViewById(com.envision_lightning.big_o.R.id.first_link);
        TextView linked_list_implementation =(TextView)findViewById(com.envision_lightning.big_o.R.id.second_link);
        TextView linked_list_video =(TextView)findViewById(com.envision_lightning.big_o.R.id.third_link);
        TextView linked_vs_array =(TextView)findViewById(com.envision_lightning.big_o.R.id.fourth_link);

        linked_list.setClickable(true);
        linked_list.setMovementMethod(LinkMovementMethod.getInstance());
        String text = "<a href='https://www.cs.cmu.edu/~adamchik/15-121/lectures/Linked%20Lists/linked%20lists.html'> Linked Lists (cs.cmu.edu) </a>";
        linked_list.setText(Html.fromHtml(text));

        linked_list_implementation.setClickable(true);
        linked_list_implementation.setMovementMethod(LinkMovementMethod.getInstance());
        String textTwo = "<a href='https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm'> Linked Lists (tutorialspoint) </a>";
        linked_list_implementation.setText(Html.fromHtml(textTwo));

        linked_list_video.setClickable(true);
        linked_list_video.setMovementMethod(LinkMovementMethod.getInstance());
        String textThree= "<a href='https://www.youtube.com/watch?v=vcQIFT79_50'>  Linked Lists Implementation Video (youtube) </a>";
        linked_list_video.setText(Html.fromHtml(textThree));

        linked_vs_array.setClickable(true);
        linked_vs_array.setMovementMethod(LinkMovementMethod.getInstance());
        String textFour = "<a href='https://www.youtube.com/watch?v=lC-yYCOnN8Q'> Arrays vs Linked Lists (youtube) </a>";
        linked_vs_array.setText(Html.fromHtml(textFour));
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item.getItemId() == android.R.id.home) {
            finish();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
