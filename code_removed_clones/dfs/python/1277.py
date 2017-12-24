import helium
import unittest
import os

SMILES = helium.Smiles()

class DFSTestVisitor(helium.DFSVisitor): INDENT

    output = ''

    def initialize(self, mol): INDENT
        self.output += 'initialize()\n'

DEDENT     def component(self, i): INDENT
        self.output += 'component(' + str(i) + ')\n'

DEDENT     def atom(self, mol, prev, atom): INDENT
        self.output += 'atom(' + str(atom.index()) + ')\n'

DEDENT     def bond(self, mol, prev, bond): INDENT
        self.output += 'bond(' + str(bond.index()) + ')\n'

DEDENT     def backtrack(self, mol, atom): INDENT
        self.output += 'backtrack(' + str(atom.index()) + ')\n'

DEDENT     def back_bond(self, mol, bond): INDENT
        self.output += 'back_bond(' + str(bond.index()) + ')\n'


DEDENT DEDENT class TestDFS(unittest.TestCase): INDENT

    datadir = os.getenv('HEDATADIR', os.getenv('HOME', 'c:/') + '/Helium/data')

    def test_data_dir(self): INDENT
        self.assertTrue(os.path.isdir(self.datadir))

DEDENT     def compare_file(self, filename, output): INDENT
        f = open(self.datadir + '/' + filename)
        lines = f.read()
        self.assertEqual(output, lines)

DEDENT     def test_dfs_1(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C(CC)(CC)CC', mol)

        visitor = helium.DFSDebugVisitor()
        helium.depth_first_search(mol, visitor)
        self.compare_file('dfs1.log', visitor.output)

DEDENT     def test_dfs_2(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C1CCC(CC)CC1', mol)

        visitor = helium.DFSDebugVisitor()
        helium.depth_first_search(mol, visitor)
        self.compare_file('dfs2.log', visitor.output)

DEDENT     def test_dfs_3(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C1CCC(CC)CC1', mol)

        visitor = helium.DFSDebugVisitor()
        helium.exhaustive_depth_first_search(mol, mol.atom(0), visitor)
        self.compare_file('dfs3.log', visitor.output)

DEDENT     def test_dfs_4(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C1CCCCC1CC.CC', mol)

        visitor = helium.DFSDebugVisitor()
        helium.depth_first_search(mol, visitor)
        self.compare_file('dfs4.log', visitor.output)

DEDENT     def test_dfs_5(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C1CCCCC1CC.CC', mol)

        atomMask = [True] * mol.numAtoms()
        atomMask[6] = False
        atomMask[7] = False

        visitor = helium.DFSDebugVisitor()
        helium.depth_first_search_mask(mol, visitor, atomMask)
        self.compare_file('dfs5.log', visitor.output)

DEDENT     def test_dfs_6(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C1CCCCC1CC.CC', mol)

        atomMask = [True] * mol.numAtoms()
        atomMask[6] = False
        atomMask[7] = False
        bondMask = [True] * mol.numBonds()
        bondMask[6] = False
        bondMask[7] = False
        bondMask[8] = False

        visitor = helium.DFSDebugVisitor()
        helium.depth_first_search_mask(mol, visitor, atomMask, bondMask)
        self.compare_file('dfs6.log', visitor.output)

DEDENT     def test_dfs_7(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C1CCCCC1CC.CC', mol)

        visitor = helium.DFSDebugVisitor()
        helium.depth_first_search(mol, mol.atom(0), visitor)
        self.compare_file('dfs7.log', visitor.output)

DEDENT     def test_dfs_8(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C1CCCCC1CC.CC', mol)

        atomMask = [True] * mol.numAtoms()
        atomMask[6] = False
        atomMask[7] = False

        visitor = helium.DFSDebugVisitor()
        helium.depth_first_search_mask(mol, mol.atom(0), visitor, atomMask)
        self.compare_file('dfs8.log', visitor.output)

DEDENT     def test_dfs_9(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C1CCCCC1CC.CC', mol)

        atomMask = [True] * mol.numAtoms()
        atomMask[6] = False
        atomMask[7] = False
        bondMask = [True] * mol.numBonds()
        bondMask[5] = False
        bondMask[6] = False
        bondMask[7] = False

        visitor = helium.DFSDebugVisitor()
        helium.depth_first_search_mask(mol, mol.atom(0), visitor, atomMask, bondMask)
        self.compare_file('dfs9.log', visitor.output)

DEDENT     def test_dfs_10(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C(C)N', mol)

        visitor = helium.DFSDebugVisitor()
        helium.ordered_depth_first_search(mol, [0, 2, 1], visitor)
        self.compare_file('dfs10.log', visitor.output)

DEDENT     def test_dfs_11(self): INDENT
        mol = helium.Molecule()
        SMILES.read('CCC', mol)

        visitor = helium.DFSDebugVisitor()
        helium.exhaustive_depth_first_search(mol, mol.atom(1), visitor)
        self.compare_file('dfs11.log', visitor.output)

DEDENT     def test_atom_order_visitor(self): INDENT
        mol = helium.Molecule()
        SMILES.read('CCC', mol)

        visitor = helium.DFSAtomOrderVisitor()
        helium.depth_first_search(mol, visitor)
        self.assertListEqual([0, 1, 2], visitor.atoms)

DEDENT     def test_bond_order_visitor(self): INDENT
        mol = helium.Molecule()
        SMILES.read('CCC', mol)

        visitor = helium.DFSBondOrderVisitor()
        helium.depth_first_search(mol, visitor)
        self.assertListEqual([0, 1], visitor.bonds)

DEDENT     def test_closure_recorder_visitor(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C1CCCCC1', mol)

        visitor = helium.DFSClosureRecorderVisitor()
        helium.depth_first_search(mol, visitor)
        self.assertListEqual([5], visitor.back_bonds)

DEDENT     def test_custom_visitor(self): INDENT
        mol = helium.Molecule()
        SMILES.read('C1CCC(CC)CC1', mol)

        visitor = DFSTestVisitor()
        helium.depth_first_search(mol, visitor)
        self.compare_file('dfs2.log', visitor.output)


DEDENT DEDENT if __name__ == '__main__': INDENT
    unittest.main()
DEDENT 
