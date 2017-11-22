#include <cassert>
#include <iomanip>
#include <list>
#include <queue>
#include <set>
#include <stack>

#include "debug.h"
#include "facts.h"
#include "rules.h"
#include "algorithms/bfs.h"
#include "algorithms/common.h"
#include "parser/setblock.h"

using ::std::cout;
using ::std::endl;

using ::std::queue;
using ::std::stack;

/*
 * Inizializza e chiama l'algoritmo BFS sulla working memory
 */
uint32_t
algo_bfs(RuleSet *ruleset, Fact *initial, Fact *final, Options *options) {
	if (options->get("limit")->get_type() != ITEM_INT)
		throw WorkingMemoryError("missing or invalid 'limit' option");

	stringstream ss;
	ss << options->get("limit")->get_value();
  uint32_t limit;
	ss >> limit;
	if (limit == 0)
		throw WorkingMemoryError("missing or invalid 'limit' option");

	cout << "Limit: " << options->get("limit")->get_value() << endl;

  uint32_t expanded_nodes = 0;
	SearchNode *result = bfs(ruleset, initial, final, limit, &expanded_nodes);

	if (!result)
		cout << "No solution found" << endl;
	else {
		cout << "Solution found!" << endl;
		cout << "Sequence: " << endl;

		/* la lista di passi torna in ordine inverso visto che partiamo dalle
		 * foglie, mettiamo in una pila e mostriamo l'output solo successivamente
		 */
		SearchNode *tmp = result;
		stack<string> steps;
		while (tmp->father) {
			steps.push(tmp->applied_rule->get_name());
			tmp = tmp->father;
		}

		/* ora possiamo mandare in output i passi */
		unsigned int i = 1;
		string rulename;
		while (!steps.empty()) {
			rulename = steps.top();
			steps.pop();

			cout << std::setw(3) << i++ << ". " << rulename << endl;
		}
	}

	return expanded_nodes;
};

/*
 * Implementazione vera e propria dell'algoritmo di BFS
 */
SearchNode *
bfs(RuleSet *ruleset, Fact *initial, Fact *final, unsigned int depth_limit, unsigned int *expanded_nodes) {
	list<RuleApplication> *applications;
	list<RuleApplication>::iterator app_iterator;

	queue<SearchNode *> nodes;
	queue<SearchNode *> cs_app_result;

	SearchNode *currnode, *tmpnode;

  std::set<string> nodes_hash;
	string hash;

	assert(initial->equals_to(initial));

	SearchNode *root = new SearchNode();
	root->father = NULL;
	root->applied_rule = NULL;
	root->fact = initial;
	root->depth = 0;

	if (initial->equals_to(final)) return root;
	nodes_hash.insert(root->fact->hash());
	nodes.push(root);
	(*expanded_nodes)++;

	uint32_t depth = 0;
	while (!nodes.empty() && depth < depth_limit) {
		currnode = nodes.front();
		nodes.pop();

		depth = currnode->depth;

		applications = ruleset->get_conflict_set(currnode->fact);
		/* se non ci sono cammini da qui in poi abbandoniamo il processo */
		if (applications->empty()) {
			delete currnode;
			delete applications;
			continue;
		}
		cs_app_result = apply_conflict_set(ruleset, applications, currnode, ++depth);

		while (!cs_app_result.empty()) {
			tmpnode = cs_app_result.front();
			cs_app_result.pop();

			/* abbiamo trovato una soluzione */
			if (tmpnode->fact->equals_to(final))
				return tmpnode;

			/* se il nodo generato coincide con il suo genitore allora non
			 * aggiungerlo alla lista
			 */
			if (tmpnode->fact->equals_to(currnode->fact)) {
				delete tmpnode;
				continue;
			}

			hash = tmpnode->fact->hash();
	
			/* controlliamo se questo nodo e` gia` stato calcolato, solo se non lo e`
			 * lo aggiungiamo alla lista di stati da considerare */
			if (nodes_hash.find(hash) == nodes_hash.end()) {
				nodes_hash.insert(tmpnode->fact->hash());
				nodes.push(tmpnode);
				(*expanded_nodes)++;
			}
		}

		delete applications;
	}

	return NULL;
};

