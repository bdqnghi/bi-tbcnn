/***************************************************************************
 *   Copyright (C) 2004 by Chris Smith                                     *
 *   chris.rs@xtra.co.nz                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "stack.h"
#include <iostream>

bool Stack::isEmpty()
{
	if( list.getSize() == 0 )
		return true;
	else
		return false;
}

int Stack::top()
{
	if( list.head == NULL )
		return 0;
		
	return list.head->data;
}

void Stack::push( int i )
{
	list.addToFront( i );
}

void Stack::pop()
{
	if( list.getSize() > 0 ) 
		list.removeFromFront();
}

