package dfs;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.List;

import common.Constants;
import common.DFileID;

public abstract class DFS {
		
	private boolean _format;
	private String _volName;

	DFS(String volName, boolean format) {
		_volName = volName;
		_format = format;
	}
	
	DFS(boolean format) {
		this(Constants.vdiskName,format);
	}

	DFS() {
		this(Constants.vdiskName,false);
	}

	/*
	 * If format is true, the system should format the underlying disk contents,
	 * i.e., initialize to empty. On success returns true, else return false.
	 */
	public abstract boolean format();
	
	/* creates a new DFile and returns the DFileID, which is useful to uniquely identify the DFile*/
	public abstract DFileID createDFile();
	
	/* destroys the file specified by the DFileID */
	public abstract void destroyDFile(DFileID dFID);

	/*
	 * reads the file dfile named by DFileID into the buffer starting from the
	 * buffer offset startOffset; at most count bytes are transferred
	 */
	public abstract int read(DFileID dFID, byte[] buffer, int startOffset, int count) throws IllegalArgumentException, FileNotFoundException, IOException;
	
	/*
	 * writes to the file specified by DFileID from the buffer starting from the
	 * buffer offset startOffsetl at most count bytes are transferred
	 */
	public abstract int write(DFileID dFID, byte[] buffer, int startOffset, int count) throws IllegalArgumentException, FileNotFoundException, IOException;
	
	/* returns the size in bytes of the file indicated by DFileID. */
	public abstract int sizeDFile(DFileID dFID);

	/* 
	 * List all the existing DFileIDs in the volume
	 */
	public abstract List<DFileID> listAllDFiles();
}