// A topological sorting of nodes in a graph is an ordering of the nodes in the graph where every 
// node appears only after all the nodes pointing to it have appeared. For example, for a graph with 
// 4 nodes and these relations: a→b , a→c , b→d , c→d , there are two acceptable topological 
// sorts: a, b, c, d and a, c, b, d .
// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for 
// every directed edge u→v, vertex u comes before v in the ordering. There may be several topological orderings for a graph.
// Note: Topological Sorting for a graph is not possible if the graph is not a DAG.