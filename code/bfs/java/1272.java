package applications;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Counters;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;

import graph_filter.FrameworkMain;
import hadoopComponents.hadoopReducer;
import hadoopComponents.HadoopTerminator;
import hadoopComponents.HadoopJob;

enum count {
	PROCESSED_GRAY,			
	UNPROCESSED_GRAY		
}

class MapClass extends Mapper<LongWritable, Text, IntWritable, Text> {
	
	public void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {

		NodeExtendedBFS node = new NodeExtendedBFS(value.toString());

		if (node.getColor() == NodeExtendedBFS.Color.GRAY) {
			for (int v : node.getEdgeList()) {
				NodeExtendedBFS nghbrNode = new NodeExtendedBFS(v);
				nghbrNode.setDistance(node.getDistance() + 1);
				nghbrNode.setColor(NodeExtendedBFS.Color.GRAY);
				context.write(new IntWritable(nghbrNode.getId()), new Text(nghbrNode.toString()));
			}
			node.setColor(NodeExtendedBFS.Color.BLACK);
			context.getCounter(count.PROCESSED_GRAY).increment(1L);
		}

		context.write(new IntWritable(node.getId()), new Text(node.toString()));
	}
}

class ReduceClass extends Reducer<IntWritable, Text, IntWritable, Text> {
	
	public void reduce(IntWritable key, Iterable<Text> values,
		Context context) throws IOException, InterruptedException {
		
		ArrayList<Integer> edges = null;
		int distance = Integer.MAX_VALUE;
		NodeExtendedBFS.Color color = NodeExtendedBFS.Color.WHITE;
		
		for (Text value : values) {
		
			NodeExtendedBFS u = new NodeExtendedBFS(key.get() + "\t" + value.toString());
		
			if (u.getEdgeList().size() > 0) {
				edges = u.getEdgeList();
			}
		
			// Save the minimum distance
			if (u.getDistance() < distance) {
				distance = u.getDistance();
			}
		
			// Save the darkest color
			if (u.getColor().ordinal() > color.ordinal()) {
				color = u.getColor();
			}
		}
		
		NodeExtendedBFS n = new NodeExtendedBFS(key.get());
		n.setDistance(distance);
		n.setEdgeList(edges);
		n.setColor(color);
		context.write(key, new Text(n.toString()));
		
		if (color == NodeExtendedBFS.Color.GRAY)
			context.getCounter(count.UNPROCESSED_GRAY).increment(1L);
	}
}

public class BFS {
	static FrameworkMain fwMain;
	static HadoopJob hJob;
	
	static HadoopJob CreateHadoopJob(String name){
		hJob = new HadoopJob();
		hJob.setmapperClass(MapClass.class);
		hJob.setReducerClass(ReduceClass.class);
		hJob.setOtputKeyClass(IntWritable.class);
		hJob.setOutputValueClass(Text.class);
		hJob.setTerminatorClass(TerminatorClassBFS.class);
		hJob.setJobName(name);
		return hJob;
	}
	
	public static void main(String args[]){
		fwMain = new FrameworkMain();
		fwMain.runMain(args, CreateHadoopJob("BFS"));
	}
}

