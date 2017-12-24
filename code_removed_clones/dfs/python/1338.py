import unittest

from algorithms.dfs import dfs, dfsPath


class TestDFS(unittest.TestCase): INDENT
    def testDFS(self): INDENT
        adjList = {
            0: [8],
            1: [3, 7, 9, 2],
            2: [8, 1, 4],
            3: [4, 5, 1],
            4: [2, 3],
            5: [3, 6],
            6: [7, 5],
            7: [1, 6],
            8: [2, 0, 9],
            9: [1, 8],
        }
        pred = dfs(adjList, 2)

        self.assertEqual({0: 8, 1: 9, 2: None, 3: 1, 4: 3, 5: 3, 6: 5, 7: 6, 8: 2, 9: 8}, pred)

        self.assertEqual([], dfsPath(pred, 2))
        self.assertEqual([2, 8], dfsPath(pred, 0))
        self.assertEqual([2, 8, 9, 1, 3, 5], dfsPath(pred, 6))
        self.assertEqual([2, 8, 9, 1, 3], dfsPath(pred, 4))


DEDENT DEDENT if __name__ == '__main__': INDENT
    unittest.main()
DEDENT 
