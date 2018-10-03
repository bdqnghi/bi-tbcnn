package test;

import java.util.Arrays;

import common.DFileID;

import dfs.DFS;

public class DFSThing
{

    public static void main(String[] args)
    {
		System.out.println("Making DFS");
        DFS dfs = new DFS(true);
		System.out.println("DFS made");
        dfs.init();
		System.out.println(dfs.listAllDFiles().size());
		System.out.println("Making file");
		DFileID dfid = dfs.createDFile();
		System.out.println(dfs.listAllDFiles().size());
		
		byte[] input = new byte[64];
		for (int i = 0; i < 32; i++)
			input[8 + i] = (byte) i;
		dfs.write(dfid, input, 8, 32);

		byte[] output = new byte[64];
		dfs.read(dfid, output, 0, 64);
		System.out.println(Arrays.toString(input));
		System.out.println(Arrays.toString(output));
    }

}
