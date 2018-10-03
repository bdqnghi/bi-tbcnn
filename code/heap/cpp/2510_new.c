void remove_max(std::vector<int>* heap) {
  std::swap(*heap->begin(), *(heap->end() - 1));
  heap->resize(heap->size() - 1);
  size_t index = 0;
  while (index < heap->size()) {
    auto child = lchild_index(index);
    if (child >= heap->size()) {
      break;
    }
    auto right = rchild_index(index);
    if (right < heap->size()
        && (*heap)[right] > (*heap)[child]) {
      child = right;
    }
    if ((*heap)[index] >= (*heap)[child]) {
      break;
    }
    std::swap((*heap)[index], (*heap)[child]);
    index = child;
  }
}