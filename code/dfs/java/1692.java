/*
 * org.fsola
 *
 * File Name: DFS.java
 *
 * Copyright 2014 Dzhem Riza
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.fsola.graphtheory;

import org.fsola.datastructures.graph.Graph;
import org.fsola.datastructures.vector.BitVector;

import java.util.List;

/**
 * Depth-First-Search algorithm for graph traversal.
 * <p/>
 * Used Resources: README file resources section line 1
 */
public class DFS {

    private static BitVector visited;

    public static <V> void dfs(Graph<V> graph, V startVertex,
                               VertexVisitor<V> visitor) {
        // Clear visited vertices bit vector
        visited = new BitVector();
        dfsImpl(graph, startVertex, visitor);
    }

    private static <V> void dfsImpl(Graph<V> graph, V startVertex,
                                    VertexVisitor<V> visitor) {
        if (visited.getBit(startVertex.hashCode())) {
            // This vertex is already visited so we just end of the recursion
            // here.
            return;
        }

        // Mark as visited
        visited.setBit(startVertex.hashCode(), true);

        visitor.visit(startVertex);

        // Recursive call to all incident vertices
        List<V> neighbors = graph.neighbors(startVertex);

        for (V y : neighbors) {
            // If this vertex is already visited just ignore it
            if (!visited.getBit(y.hashCode())) {
                dfsImpl(graph, y, visitor);
            }
        }
    }
}
