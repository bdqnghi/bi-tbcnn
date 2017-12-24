import json


START_CHARACTER = u"Woobeewoo Villagers"

dict_characters = json.loads(open('../problem/graph_nodes.json','rb').read())
dict_episodes = json.loads(open('../problem/graph_vertices.json','rb').read())

def edges(for_character): INDENT
    return [(character, episode) for episode in dict_characters[for_character] for character in dict_episodes[episode] if not character == for_character]



DEDENT discovered_characters = {}
logger = "started: \n"

def DFS(character_link): INDENT
    global logger
    logger += '      + ' +  character_link + '\n'
    discovered_characters[character_link] = logger
    for adjacent_character, link_episode in edges(character_link): INDENT
        if adjacent_character not in discovered_characters: INDENT
            logger += '----from %s via %s to \n' % (character_link, link_episode)
            DFS(adjacent_character)


DEDENT DEDENT DEDENT print edges(START_CHARACTER)
DFS(START_CHARACTER)
print 'Here:'
print discovered_characters['Goblins']
print "------------------------------------"
print "  Total: %s of %s characters discovered" % (len(discovered_characters.keys()), len(dict_characters.keys()))
