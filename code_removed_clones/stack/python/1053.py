#!/usr/bin/env python
# coding: utf-8
import argparse
import json
import yaml
import collections
from termcolor import colored
from textwrap import TextWrapper, dedent
from pydoc import pager

from cement.core import controller

from nepho.cli import base, scope
from nepho.core import common, cloudlet, stack, provider, provider_factory, scenario, parameter


class NephoStackController(base.NephoBaseController): INDENT
    class Meta: INDENT
        label = 'stack'
        interface = controller.IController
        stacked_on = 'base'
        stacked_type = 'nested'
        description = 'create, manage, and destroy stacks built from blueprints'
        usage = "nepho stack <action> [options]"
        arguments = [
            (['cloudlet'], dict(help=argparse.SUPPRESS, nargs='?')),
            (['blueprint'], dict(help=argparse.SUPPRESS, nargs='?')),
            (['--save', '-s'], dict(help=argparse.SUPPRESS, action='store_true')),
            (['--name', '-n'], dict(help='custom stack name', default=None)),
            (['--develop', '-d'], dict(help='development mode (vagrant only)', action='store_true')),
            (['--params', '-p'], dict(help=argparse.SUPPRESS, nargs='*', action='append')),
        ]

DEDENT     def _setup(self, app): INDENT
        super(base.NephoBaseController, self)._setup(app)
        self.cloudletManager = cloudlet.CloudletManager(self.app)
        self.paramsManager   = parameter.ParamsManager(self.app)

DEDENT     @controller.expose(help='Show the context for a stack from a blueprint and configs')
    def show_context(self): INDENT
        if self.app.cloudlet_name is None or self.app.blueprint_name is None: INDENT
            print "Usage: nepho stack show-context <cloudlet> <blueprint> [-n/--name <stack name] [-s/--save] [-p/--params <param>]"
            exit(1)
DEDENT         else: INDENT
            scope.print_scope(self)

DEDENT         s = self._assemble_scenario()
        c = s.context

        print "Cloudlet:"
        for k in sorted(c['cloudlet']): INDENT
            print "  %-18s: %s" % (k, c['cloudlet'][k])
DEDENT         print "Blueprint:"
        for k in sorted(c['blueprint']): INDENT
            print "  %-18s: %s" % (k, c['blueprint'][k])
DEDENT         print "Parameters:"
        for k in sorted(c['parameters']): INDENT
            print "  %-18s: %s" % (k, c['parameters'][k])

DEDENT DEDENT     @controller.expose(help='Validate and display the template output for a stack from a blueprint')
    def validate(self): INDENT
        if self.app.cloudlet_name is None or self.app.blueprint_name is None: INDENT
            print "Usage: nepho stack validate <cloudlet> <blueprint>"
            exit(1)
DEDENT         else: INDENT
            scope.print_scope(self)

DEDENT         s = self._assemble_scenario()

        output  = "-" * 80 + "\n"
        output += s.provider.validate_template(s.template)
        output += "\n" + "-" * 80 + "\n"
        output += s.provider.format_template(s.template)
        pager(output)

DEDENT     @controller.expose(help='Display the raw template for a stack from a blueprint')
    def show_template(self): INDENT
        if self.app.cloudlet_name is None or self.app.blueprint_name is None: INDENT
            print "Usage: nepho stack show-template <cloudlet> <blueprint>"
            exit(1)
DEDENT         else: INDENT
            scope.print_scope(self)

DEDENT         s = self._assemble_scenario()

        template_str = self._assemble_scenario().template
        try: INDENT
            template_str = s.provider.format_template(template_str)
DEDENT         except Exception: INDENT
            pass

DEDENT         print template_str

DEDENT     @controller.expose(help='Create a stack from a blueprint', aliases=['deploy', 'up'])
    def create(self): INDENT
        if self.app.cloudlet_name is None or self.app.blueprint_name is None: INDENT
            print dedent("""\
                Usage: nepho stack create <cloudlet> <blueprint> [-n/--name <stack name>] [-s/--save] [-p/--params <param>]

                -n, --name <stack name>
                  A custom name for your stack rather than nepho-<cloudlet>-<blueprint>.
                  When using this option you must specify name for other stack actions such as
                  connect, destroy, and status or they will not know which stack to act upon.
                -s, --save
                  [NOT IMPLEMENTED] Save command-line (and/or interactive) parameters to an
                  overrides file for use in all future invocations of this command.

                -p, --params
                  Override any parameter from the blueprint template. This option can be passed
                  multiple key=value pairs, and can be called multiple times. If a required
                  parameter is not passed as a command-line option, nepho will interactively
                  prompt for it.

                Examples:
                  nepho stack create my-app development --name foostack --params AZ1=us-east-1a
                  nepho stack create my-app development -s -p Foo=True -p Bar=False""")
            exit(1)
DEDENT         else: INDENT
            scope.print_scope(self)

DEDENT         s = self._assemble_scenario()
        s.provider.create(self.app)

DEDENT     @controller.expose(help='Update a running stack', aliases=['provision'])
    def update(self): INDENT
        if self.app.cloudlet_name is None or self.app.blueprint_name is None: INDENT
            print "Usage: nepho stack update <cloudlet> <blueprint> [-n/--name <stack name>]"
            exit(1)
DEDENT         else: INDENT
            scope.print_scope(self)

DEDENT         s = self._assemble_scenario()
        s.provider.update(self.app)

DEDENT     @controller.expose(help='Check on the status of a stack.')
    def status(self): INDENT
        if self.app.cloudlet_name is None or self.app.blueprint_name is None: INDENT
            print "Usage: nepho stack status <cloudlet> <blueprint> [-n/--name <stack name]"
            exit(1)
DEDENT         else: INDENT
            scope.print_scope(self)

DEDENT         s = self._assemble_scenario()

        # For now the provider prints this information
        s.provider.status(self.app)

DEDENT     @controller.expose(help='Gain access to the stack', aliases=['ssh'])
    def access(self): INDENT
        if self.app.cloudlet_name is None or self.app.blueprint_name is None: INDENT
            print "Usage: nepho stack access <cloudlet> <blueprint> [-n/--name <stack name]"
            exit(1)
DEDENT         else: INDENT
            scope.print_scope(self)

DEDENT         s = self._assemble_scenario()

        s.provider.access(self.app)

DEDENT     @controller.expose(help='Destroy a stack from a blueprint', aliases=['delete', 'down', 'remove'])
    def destroy(self): INDENT
        if self.app.cloudlet_name is None or self.app.blueprint_name is None: INDENT
            print "Usage: nepho stack destroy <cloudlet> <blueprint> [-n/--name <stack name]"
            exit(1)
DEDENT         else: INDENT
            scope.print_scope(self)

DEDENT         s = self._assemble_scenario()
        s.provider.destroy(self.app)

DEDENT     @controller.expose(help='List running stacks')
    def list(self): INDENT
        scope.print_scope(self)

        print "Unimplemented action. (input: %s)" % self.app.pargs.params
        exit(0)

        try: INDENT
            cloudlt = self.cloudletManager.find(self.app.cloudlet_name)
            y = cloudlt.definition
DEDENT         except IOError: INDENT
            print colored(base.DISP_PATH, "yellow"), cloudlt.name, "(", colored("error", "red"), "- missing or malformed cloudlet.yaml )"
            exit(1)
DEDENT         else: INDENT
            print colored(base.DISP_PATH, "yellow"), cloudlt.name, "(", colored("v%s", "blue") % (y['version']), ")"

DEDENT DEDENT     def _parse_user_params(self): INDENT
        """Helper method to extract params from command line into a dict."""
        params = dict()
        if self.app.pargs.params is not None: INDENT
            paramList = self.app.pargs.params
            for item in paramList[0]: INDENT
                (k, v) = item.split("=")
                params[k] = v
DEDENT DEDENT         return params

DEDENT     def _load_blueprint(self): INDENT
        """Helper method to load blueprint & pattern from args."""

        try: INDENT
            cloudlt = self.cloudletManager.find(self.app.cloudlet_name)
DEDENT         except Exception: INDENT
            print colored("Error: ", "red"), "Could not load cloudlet %s" % (self.app.cloudlet_name)
            exit(1)

DEDENT         try: INDENT
            bprint = cloudlt.blueprint(self.app.blueprint_name)
DEDENT         except Exception: INDENT
            print colored("Error: ", "red"), "Could not load blueprint %s for cloudlet %s.\nFor a list of blueprints run `nepho blueprint list %s`" % (self.app.blueprint_name, self.app.cloudlet_name, self.app.cloudlet_name)
            exit(1)

DEDENT         return bprint

DEDENT     def _assemble_scenario(self): INDENT
        """Helper method to create a suitable scenario from the command line options."""

        stored_params = self.paramsManager
        user_params = self._parse_user_params()
        bprint = self._load_blueprint()
        if self.app.pargs.name is not None: INDENT
            stack_name = self.app.pargs.name
DEDENT         else: INDENT
            stack_name = '%s-%s' % (self.app.cloudlet_name, self.app.blueprint_name)
DEDENT         s = scenario.Scenario(bprint, stored_params, user_params, stack_name)

        return s
DEDENT DEDENT 
