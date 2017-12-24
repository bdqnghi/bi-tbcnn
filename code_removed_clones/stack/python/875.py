"""
YADAYADA is a simple toolbox for training neural networks with many hidden layers.
It allows to build these deep networks by successivly pretraining these layers in
order to help training the complete deep network. Therefore, the central data structure
is the Stack, a list of layers.
Two aspects are at the center of YADAYADA: (i) It must allow pretraining the single
layers and (ii) it must allow the usage of general optimization algorithms. To facilitate
this, the Stack is managing the complete parameter vector of the deep network. The
various layers only have views into this vector -- they have their own parameters when
in pretraining mode. It only uses its view on the global parameter vector when updating
this global parameter after a finished pretraining session. This explains why every single layer gets always the parameters
passed in when doing forward or backward computations over the full stack.
"""


import numpy as np
from itertools import izip
import h5py
from time import strftime


from gnumpy import zeros as gzeros
import gnumpy as gpu

from losses import loss_table
from utils import prepare_opt, replace_gnumpy_data
import chopmunk as munk


class Stack(list): INDENT
    def __init__(self, ind, schedule): INDENT
        gpu.seed_rand(seed=None)
        self.logging = schedule["logging"]
        self.psize = 0
        cuts = [0]
        self.stack = schedule["stack"]
        for layer in self.stack: INDENT
            ltype = layer["type"]
            units = layer["units"]
            l = ltype.__new__(ltype)
            l.__init__(shape=(ind, units), **layer)
            self.psize += l.size
            self.append(l)
            cuts.append(l.size)
            ind = units
DEDENT         self.params = gzeros(self.psize)
        self.cuts = np.cumsum(cuts)
        for layer, (c1, c2) in izip(self, izip(self.cuts[:-1], self.cuts[1:])): INDENT
            layer.p = self.params[c1:c2]
DEDENT         if "score" in schedule: INDENT
            self._score = schedule["score"]
DEDENT         else: INDENT
            print("You may have a problem: _score_ is NONE")
            self._score = None

DEDENT DEDENT     def __repr__(self): INDENT
        rep = "|".join([str(l) for l in self])
        return rep

DEDENT     def pretrain(self, schedule): INDENT
        train = [schedule["train"][0], schedule["train"][1]]
        valid = None if not schedule.get("valid") else [schedule["valid"][0], schedule["valid"][1]]

        assert (valid is not None) == ("valid" in schedule["eval"]), "Confusion about validation set!"

        for i, (layer, sched) in enumerate(izip(self, self.stack)): INDENT
            pt_params = layer.pt_init(**sched)
            
            opt_schedule = sched["opt"]
            
            pp = {"layer":i, "type":str(layer)}
            munk.taggify(self.logging, "pretty").send(pp)
            log = munk.add_keyvalue(self.logging, "layer", i)
            
            epochs = opt_schedule["epochs"]
            if epochs > 0: INDENT
                opt_schedule["f"] = layer.pt_score
                opt_schedule["fprime"] = layer.pt_grad

                opt, evals, peeks = prepare_opt(opt_schedule, pt_params, schedule, train, valid)

                stop = opt_schedule["stop"]
                for j, info in enumerate(opt): INDENT
                    if (j+1) % stop == 0: INDENT
                        for e in evals: INDENT
                            info[e] = evals[e](pt_params)
DEDENT                         info = replace_gnumpy_data(info)
                        log.send(info)
                        
DEDENT                     if (j+1) == epochs: INDENT
                        break
DEDENT DEDENT DEDENT             else: INDENT
                pp = {"msg": "NO PRETRAINING of layer %i"%i}
                munk.taggify(self.logging, "pretty").send(pp)

DEDENT             info = layer.pt_done(pt_params, **sched)
            pt_params = None
            log.send(info)

            # move data forward, save in temporary hdf5
            if i < (len(self) - 1): INDENT
                nxt_name = strftime("%Y-%m-%d-%H:%M:%S") + "_L" + str(i+1) + "_TMP.h5"
                nxt = h5py.File(nxt_name)
                pp = {"msg": "Take care of temporary " + nxt_name}
                munk.taggify(self.logging, "pretty").send(pp)
                # if a validation set is available, move it forward, too.
                if valid: INDENT
                    valid[0] = self.next_hdf5(layer, valid[0], "validation", nxt, chunk=512)
DEDENT                 train[0] = self.next_hdf5(layer, train[0], "train", nxt, chunk=512)

DEDENT DEDENT DEDENT     def train(self, schedule): INDENT
        train = [schedule["train"][0], schedule["train"][1]]
        valid = None if not schedule.get("valid") else [schedule["valid"][0], schedule["valid"][1]]

        assert (valid is not None) == ("valid" in schedule["eval"]), "Confusion about validation set!"

        opt_schedule = schedule["opt"]
        
        pp = {"type" : str(self)}
        munk.taggify(self.logging, "pretty").send(pp)
        log = munk.add_keyvalue(self.logging, "layer", "Stack")
       
        epochs = opt_schedule["epochs"]
        if epochs > 0: INDENT
            opt_schedule["f"] = self.score
            opt_schedule["fprime"] = self.grad

            if "eval_score" in opt_schedule: INDENT
                self._eval_score = opt_schedule["eval_score"]
                opt_schedule["eval_score"] = self.evaluate_score

DEDENT             opt, evals, peeks = prepare_opt(opt_schedule, self.params, schedule, train, valid)

            stop = opt_schedule["stop"]
            if "peeks" in opt_schedule: INDENT
                peek_iv = opt_schedule["peek_intervall"]
                peek_files = {}
                for p in opt_schedule["peeks"]: INDENT
                    peek_files[p] = p + ".peek"
DEDENT DEDENT             else: INDENT
                peek_iv = epochs + 1

DEDENT             for i, info in enumerate(opt): INDENT
                if (i+1) % stop == 0: INDENT
                    for e in evals: INDENT
                        info[e] = evals[e](self.params)
DEDENT                     info = replace_gnumpy_data(info)
                    log.send(info)

DEDENT                 if i+1 == epochs: INDENT
                    break
                
DEDENT                 if (i+1) % peek_iv == 0: INDENT
                    for p in peeks: INDENT
                        prediction, inputs = peeks[p](self.params)
                        np.savez(peek_files[p], prediction, inputs)
                        pp = {"msg": "Writing peek file %s"%peek_files[p]}
                        munk.taggify(self.logging, "pretty").send(pp)

DEDENT DEDENT DEDENT DEDENT         else: INDENT
            pp = {"msg": "NO FINETUNING of stack"}
            munk.taggify(self.logging, "pretty").send(pp)

DEDENT         _params = self.params.as_numpy_array().tolist()
        info = dict(params=_params, shape=self.__repr__())
        log.send(info)

DEDENT     def score(self, params, inputs, targets, **kwargs): INDENT
        data = inputs
        for layer, (c1, c2) in izip(self, izip(self.cuts[:-1], self.cuts[1:])): INDENT
            data = layer.fward(self.params[c1:c2], data)
DEDENT         return self._score(data, targets, **kwargs)

DEDENT     def grad(self, params, inputs, targets, **kwargs): INDENT
        data = inputs
        for layer, (c1, c2) in izip(self, izip(self.cuts[:-1], self.cuts[1:])): INDENT
            data = layer.fprop(self.params[c1:c2], data)

DEDENT         _, delta = self._score(data, targets, error=True)

        g = gzeros(self.psize)
        for layer, (c1, c2) in izip(self[::-1], izip(self.cuts[-2::-1], self.cuts[:0:-1])): INDENT
            delta = layer.bprop(params=params[c1:c2], grad=g[c1:c2], delta=delta)
DEDENT         return g

DEDENT     def evaluate_score(self, params, inputs, targets, **kwargs): INDENT
        data = inputs
        for layer, (c1, c2) in izip(self, izip(self.cuts[:-1], self.cuts[1:])): INDENT
            data = layer.fward(self.params[c1:c2], data)
DEDENT         return self._eval_score(data, targets, **kwargs)

DEDENT     def next_hdf5(self, layer, data, dname, nxt, chunk): INDENT
        """After pretraining one layer, move
        data to new temporary hdf5 store.
        """
        n = data.shape[0]
        d = layer.shape[1]
        tmp = nxt.create_dataset(name=dname, shape=(n, d), dtype=data.dtype)
        for i in xrange(0, n, chunk): INDENT
            tmp[i:i+chunk] = layer._fward(data[i:i+chunk])
DEDENT         return tmp

DEDENT     def _fward(self, data): INDENT
        for layer in self: INDENT
            data = layer._fward(data)
DEDENT         return loss_table[self._score](data, targets=None, predict=True)

DEDENT     def _fward_layers(self, data, layers): INDENT
        """
        Only pass _data_ through _layers_ many layers.
        No loss applied!.
        """
        for layer in self[:layers]: INDENT
            data = layer._fward(data)
DEDENT         return data

DEDENT     def reload(self, depot, folder, tag): INDENT
        """
        reload schedule and parameters from depot/folder/tag.params
        depot, abs path
        """
        from utils import load_params
        from os.path import join
        from gnumpy import as_garray
        file_prefix = join(depot, folder, tag)
        params = load_params(file_prefix + ".params")
        params_stack = params['Stack']['params']
        self.params = as_garray(params_stack)
        for layer, (c1, c2) in izip(self, izip(self.cuts[:-1], self.cuts[1:])): INDENT
            layer.p = self.params[c1:c2]
DEDENT DEDENT DEDENT 
