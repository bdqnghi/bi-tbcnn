package com.jlabirinto.dfs;

import java.util.ArrayList;
import java.util.Collections;

import com.jlabirinto.Labirinto;
import com.jlabirinto.No;

public class DFS {

	private Boolean[][] labirintoDFS;

	public Boolean[][] getLabirintoDFS() {
		return labirintoDFS;
	}

	public DFS(Labirinto labirinto) {

		this.labirintoDFS = labirinto.getLabirintoPrincipal();
		retornaLabirintoDFS(labirinto, labirinto.getOrigem());

	}

	public void retornaLabirintoDFS(Labirinto labirinto, No noAtual) {

		ArrayList<No> arredores = labirinto.getArredores(noAtual, false, 1);
		if (!arredores.isEmpty()) {
			Collections.shuffle(arredores);
			for (No noLista : arredores) {
				Integer posicaoX = noLista.getPosicaoX();
				Integer posicaoY = noLista.getPosicaoY();
				if (labirintoDFS[posicaoX][posicaoY] == false) {
					labirintoDFS[posicaoX][posicaoY] = true;
					switch (noAtual.verificaPosicaoRelativa(noLista)) {
					case 1:
						labirintoDFS[posicaoX - 1][posicaoY] = true;
						break;
					case 2:
						labirintoDFS[posicaoX + 1][posicaoY] = true;
						break;
					case 3:
						labirintoDFS[posicaoX][posicaoY - 1] = true;
						break;
					case 4:
						labirintoDFS[posicaoX][posicaoY + 1] = true;
						break;
					default:
						break;
					}
					if (!noLista.equals(labirinto.getAlvo())) {
						retornaLabirintoDFS(labirinto, noLista);
					}
				}
			}
		}

	}

}
