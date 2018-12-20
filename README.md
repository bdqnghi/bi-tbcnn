# Bilateral Tree-based Convolutional Neural Networks

The project is the implementation of our work on the Bilateral Tree-based CNN introduced in our 2 papers :

- SANER'19: Bilateral Dependency Neural Networks for Cross-Language Algorithm Classification, by Nghi D. Q. BUI, Yijun YU, Lingxiao JIANG, in the 26th edition of the IEEE International Conference on Software Analysis, Evolution and Reengineering, Research Track, Zhejiang University in Hangzhou, February 24-27, 2019
- NL4SE-AAAI'18: Cross-Language Learning for Program Classification Using Bilateral Tree-Based Convolutional Neural Networks, by Nghi D. Q. BUI, Lingxiao JIANG, and Yijun YU. In the proceedings of the 32nd AAAI Conference on Artificial Intelligence (AAAI) Workshop on NLP for Software Engineering, New Orleans, Lousiana, USA, 2018. 

You can find the papers here: https://bdqnghi.github.io/publications/

Here's our proposed Neural Network structure. In short, this structure is a variance of the Siamese Neural Network (SNN), which is  a class of Neural Network used for finding similarity or a relationship between two comparable things. Each sub network in this case can be:
- **Tree-based Convolutional Neural Network (TBCNN)** (https://arxiv.org/abs/1409.5718)
- **Gated Graph Neural Network** (https://arxiv.org/abs/1511.05493): the implementation of GGNN for this task can be found here: https://github.com/bdqnghi/ggnn_graph_classification
- **Dependency Tree Convolutional Neural Network (DTBCNN)** (https://bdqnghi.github.io/files/SANER_2019_bilateral_dependency.pdf)

## References
```
@inproceedings{DBLP:conf/aaai/BuiJY18,
  author    = {Nghi D. Q. Bui and
               Lingxiao Jiang and
               Yijun Yu},
  title     = {Cross-Language Learning for Program Classification Using Bilateral
               Tree-Based Convolutional Neural Networks},
  booktitle = {The Workshops of the The Thirty-Second {AAAI} Conference on Artificial
               Intelligence, New Orleans, Louisiana, USA, February 2-7, 2018.},
  pages     = {758--761},
  year      = {2018},
  crossref  = {DBLP:conf/aaai/2018w},
  url       = {https://aaai.org/ocs/index.php/WS/AAAIW18/paper/view/17338},
  timestamp = {Thu, 19 Jul 2018 13:38:55 +0200},
  biburl    = {https://dblp.org/rec/bib/conf/aaai/BuiJY18},
  bibsource = {dblp computer science bibliography, https://dblp.org}
}
```
