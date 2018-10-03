package dfs;

import java.util.List;

import common.Constants;
import common.DFileID;

public abstract class DFS {

	protected boolean _format;
	protected String _volName;

	/**
	 * @volName: Explicitly overwrite volume name
	 * @format: If format is true, the system should earse the underlying disk
	 *          contents and reinialize the volume.
	 */

	DFS(String volName, boolean format) {
		_volName = volName;
		_format = format;
	}

	DFS(boolean format) {
		this(Constants.vdiskName, format);
	}

	DFS() {
		this(Constants.vdiskName, false);
	}

	/**
	 * Initialize all the necessary structures with sizes as specified in the
	 * common/Constants.java
	 */
	public abstract void init();

	/**
	 * creates a new DFile and returns the DFileID, which is useful to uniquely
	 * identify the DFile
	 */
	public abstract DFileID createDFile();

	/** destroys the file specified by the DFileID */
	public abstract void destroyDFile(DFileID dFID);

	/**
	 * reads the file dfile named by DFileID into the buffer starting from the
	 * buffer offset startOffset; at most count bytes are transferred
	 */
	public abstract int read(DFileID dFID, byte[] buffer, int startOffset, int count);

	/**
	 * writes to the file specified by DFileID from the buffer starting from the
	 * buffer offset startOffset; at most count bytes are transferred
	 */
	public abstract int write(DFileID dFID, byte[] buffer, int startOffset, int count);

	/** returns the size in bytes of the file indicated by DFileID. */
	public abstract int sizeDFile(DFileID dFID);

	/**
	 * List all the existing DFileIDs in the volume
	 */
	public abstract List<DFileID> listAllDFiles();

	/** Write back all dirty blocks to the volume, and wait for completion. */
	public abstract void sync();
}
