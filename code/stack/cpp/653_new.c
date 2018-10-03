#include "StackFreeCell.h"

StackFreeCell::StackFreeCell() : TEComponentStack(FreeCell) {
}

bool doesAccept(TEComponentStack* stack);

int StackFreeCell::getStackOffset(bool isFirst) {
	return 0;
}
	
bool StackFreeCell::doesAccept(TEComponentStack* stack) {
	return ((getChildStack() == NULL) && (stack->getChildStack() == NULL));
}

void StackFreeCell::update() {}

void StackFreeCell::pushStack(TEComponentStack* stack) {
	TEComponentStack::pushStack(stack);
	setOpenFreeCellCount(TEComponentStack::getOpenFreeCellCount() - 1);
}

void StackFreeCell::popStack(TEComponentStack* stack) {
	TEComponentStack::popStack(stack);
	setOpenFreeCellCount(TEComponentStack::getOpenFreeCellCount() + 1);
}
