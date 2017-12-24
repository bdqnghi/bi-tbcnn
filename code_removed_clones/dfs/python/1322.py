from timer.algorithm.algorithm import Algorithm
from timer.algorithm.delay_calculator.capacitance_calculator import CapacitanceCalculator
from timer.algorithm.delay_calculator.delay_calculator import DelayCalculator
from timer.node.node import Node

__author__ = 'yuczhou'


class DFS(Algorithm): INDENT
    def __init__(self, root, unit_electro_property, rc_adjustment): INDENT
        Algorithm.__init__(self, root, unit_electro_property, rc_adjustment)

DEDENT     def delay(self): INDENT
        return self._delay(self.root)

DEDENT     def _delay(self, root): INDENT
        if not isinstance(root, Node): INDENT
            raise TypeError('invalid type: Node expected')
DEDENT         if not root: INDENT
            return 0, root.electro_property.c
DEDENT         downstream_delays, downstream_caps = zip(*[self._delay(child) for child in root.neighbors()])

        delay_cal = DelayCalculator(root, downstream_delays, downstream_caps, self.unit_rc, self.wire_rc_adjustment)
        cap_cal = CapacitanceCalculator(root, downstream_caps, self.unit_rc, self.wire_rc_adjustment)
        return delay_cal.calculate(), cap_cal.calculate()
DEDENT DEDENT 
