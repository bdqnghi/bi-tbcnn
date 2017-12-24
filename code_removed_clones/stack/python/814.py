import yaml
from os.path import basename, join, isfile
from nepho.core.common import merge


def load_and_merge_blueprint(paths): INDENT
    """
    Take multiple directory paths for the same blueprint, find and read/validate
    each YAML file, and merge them, with later paths taking precedence. Return
    result as a dict.
    """
    blueprint = None
    for p in paths: INDENT
        blueprint_key = basename(p)
        blueprint_file = join(p, "%s.yaml") % (blueprint_key)
        if isfile(blueprint_file): INDENT
            try: INDENT
                f = open(blueprint_file)
                blueprint_yaml = yaml.safe_load(f)
                f.close()
DEDENT             except IOError as e: INDENT
                print "Error loading or parsing deployment blueprint file \"%s\"" % (blueprint_file)
                print e
                exit(1)
DEDENT             if blueprint is not None: INDENT
                blueprint = merge(blueprint_yaml, blueprint)
DEDENT             else: INDENT
                blueprint = blueprint_yaml
DEDENT DEDENT DEDENT     return blueprint
DEDENT 
