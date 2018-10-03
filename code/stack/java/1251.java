package org.matheusdev.screens.gui;

import java.awt.Color;
import java.awt.Graphics2D;

import org.matheusdev.res.ResLoader;

public class Stack {
	
	private int itemtype;
	private int num;
	
	public Stack(int itemtype, int num) {
		this.itemtype = itemtype;
		this.num = num;
	}
	
	public int getMaxStackable() {
		switch(itemtype) {
		case ResLoader.TILE_GRASS: return 50;
		case ResLoader.TILE_SAND: return 99;
		case ResLoader.TILE_TOWER: return 99;
		case ResLoader.GUI_WOODITEM: return 99;
		case ResLoader.GUI_FABRICITEM: return 1;
		case ResLoader.GUI_BASEICON: return 1;
		default: return 1000;
		}
	}
	
	public int tryAddStack(Stack s) {
		if (s == null) {
			return 0;
		}
		if (itemtype != s.getType()) {
			return s.getNumber();
		}
		int takenAway = pushItems(s.getNumber());
		s.popItems(s.getNumber()-takenAway);
		return takenAway;
	}
	
	public boolean isFilled() {
		return num == getMaxStackable();
	}
	
	public int pushItems(int number) {
		while(number > 0 && num < getMaxStackable()) {
			num++;
			number--;
		}
		return number;
	}
	
	public int popItems(int number) {
		int prenum = num;
		num = Math.max(0, num-number);
		return number-prenum;
	}
	
	public int getType() {
		return itemtype;
	}
	
	public int getNumber() {
		return num;
	}
	
	public void renderIcon(Graphics2D g, int x, int y) {
		g.drawImage(ResLoader.get(itemtype), x, y, null);
	}
	
	public void renderNumber(Graphics2D g, int x, int y) {
		if (getType() == ResLoader.GUI_WOODITEM 
				|| getType() == ResLoader.GUI_FABRICITEM
				|| getType() == ResLoader.GUI_BASEICON
				|| getType() == ResLoader.TILE_TOWER) {
			g.setColor(Color.WHITE);
		} else {
			g.setColor(Color.BLACK);
		}
		g.drawString(Integer.toString(num), x+1, y+12);
	}
	
}
