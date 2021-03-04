#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct str_Graph {
	
	struct str_Vertex* graph;
	int vertexCount;

}Graph, *GraphPtr;

typedef struct str_Vertex {

	ElementType data;
	struct str_Vertex* Next;
	struct str_Edge* Edges;

	int index;
	int visited;

}Vertex, *VertexPtr;

typedef struct str_Edge {

	struct str_Vertex* start;
	struct str_Vertex* end;

	struct str_Edge* Next;
	int weight;

}Edge, *EdgePtr;

GraphPtr createGraph();
void deleteGraph(GraphPtr G);

VertexPtr createVertex(ElementType data);
void deleteVertex(VertexPtr V);

EdgePtr createEdge(VertexPtr start, VertexPtr end, int weight);
void deleteEdge(EdgePtr E);

void addVertex(GraphPtr G, VertexPtr V);
void addEdge(VertexPtr V, EdgePtr E);

void printGraph(GraphPtr G);