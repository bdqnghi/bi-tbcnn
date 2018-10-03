package test;

import common.DFileID;
import dfs.DFS;

/**
 * Created by zmichaelov on 12/8/13.
 */
public class Client implements Runnable {
    private DFS dfs;
    private byte[] data;
    private int sleep = -1;
    private DFileID file;
    public Client(DFS dfs, byte[] data) {
        this.dfs = dfs;
        this.data = data;
    }

    public Client(DFS dfs, byte[] data, int sleep) {
        this.dfs = dfs;
        this.data = data;
        this.sleep = sleep;
    }

    @Override
    public void run() {

        DFileID b = dfs.createDFile();
        file = b;
        dfs.write(b, data, 0, data.length);
        if (sleep != -1) {
            try {
                Thread.sleep(sleep);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public String read() {
        byte[] out = new byte[data.length];
        dfs.read(file, out, 0, out.length);
        return new String(out);
    }
}
