import java.util.LinkedList;
import java.util.Queue;

public class BFS {

	SudokuProcessor processor;
	short[][] sudoku;
	Queue<SudokuState> unVisited = new LinkedList<SudokuState>();

	public BFS(SudokuProcessor processor, short[][] sudoku) {
		this.processor = processor;
		this.sudoku = processor.clone(sudoku);
		
		this.unVisited.add(new SudokuState(this.sudoku, null));
	}

	public SearchResult search() {
		SudokuState state = unVisited.poll();

		GridSquare square = state.getCurrentSquare();

		if (!this.processor.hasEmptySquares(square)) {
			if (this.processor.isValid(state.getSudoku())) {
				return new SearchResult(state.getSudoku(), true);
			}
		} else {
			square = this.processor.nextEmptySquare(state.getCurrentSquare());
			for (short i = 1; i <= 9; i++) {
				short[][] nextSudoku = this.processor.clone(state.getSudoku());
				nextSudoku[square.getRow()][square.getColumn()] = i;
				unVisited.add(new SudokuState(nextSudoku, square));
			}
		}

		return search();
	}
}
