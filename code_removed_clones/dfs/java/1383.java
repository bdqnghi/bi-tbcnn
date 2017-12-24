package com.fqy.recursion;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class DFS {
	public List<String> letterCombinations(String digits) {
		List<String> result = new ArrayList<>();
		if (digits == null || digits.length() < 1)
			return result;
		HashMap<Character, String> map = new HashMap<>();
		map.put('0', "0");
		map.put('1', "1");
		map.put('2', "abc");
		map.put('3', "def");
		map.put('4', "ghi");
		map.put('5', "jkl");
		map.put('6', "mno");
		map.put('7', "pqrs");
		map.put('8', "tuv");
		map.put('9', "wxyz");
		StringBuilder sb = new StringBuilder();
		dfs(digits, 0, sb, map, result);
		return result;
	}

	public void dfs(String digits, int step, StringBuilder sb, HashMap<Character, String> map, List<String> result) {
		if (step == digits.length()) {
			result.add(sb.toString());
			return;
		}
		Character curr = digits.charAt(step);
		String str = map.get(curr);
		for (int i = 0; i < str.length(); i++) {
			sb.append(str.charAt(i));
			dfs(digits, step + 1, sb, map, result);
			sb.deleteCharAt(sb.length() - 1);
		}
	}
}
