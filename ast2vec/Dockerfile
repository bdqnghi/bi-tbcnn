#FROM tensorflow/tensorflow
FROM tensorflow/tensorflow:latest-gpu
RUN apt-get update
RUN apt-get install time
RUN pip install tqdm
RUN pip install requests
RUN pip install requests_cache
ADD . /ast2vec
WORKDIR /
CMD ["bash", "-c", "ast2vec/run"]
